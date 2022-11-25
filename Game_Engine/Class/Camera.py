import pygame as pg
import pyautogui
from Class.Utils.matrix_functions import *

class Camera:
    def __init__(self, render, position):
        self.render = render
        self.position = np.array([*position, 1.0])
        self.forward = np.array([0, 0, 1, 1])
        self.up = np.array([0, 1, 0, 1])
        self.right = np.array([1, 0, 0, 1])
        self.h_fov = math.pi / 3
        self.v_fov = self.h_fov * (render.HEIGHT / render.WIDTH)
        self.near_plane = 0.1
        self.far_plane = 100
        self.moving_speed = 0.3
        self.rotation_speed = 0.015

        self.anglePitch = 0
        self.angleYaw = 0
        self.angleRoll = 0

        self.sensitivity = 0.1

    def control(self):
        key = pg.key.get_pressed()
        if key[pg.K_q]:
            self.position -= self.right * self.moving_speed
        if key[pg.K_d]:
            self.position += self.right * self.moving_speed
        if key[pg.K_z]:
            self.position += self.forward * self.moving_speed
        if key[pg.K_s]:
            self.position -= self.forward * self.moving_speed
        if key[pg.K_SPACE]:
            self.position += self.up * self.moving_speed
        if key[pg.K_LSHIFT]:
            self.position -= self.up * self.moving_speed

        if key[pg.K_RIGHT]:
            self.camera_yaw(-self.rotation_speed)
        if key[pg.K_LEFT]:
            self.camera_yaw(self.rotation_speed)
        if key[pg.K_DOWN]:
            self.camera_pitch(-self.rotation_speed)
        if key[pg.K_UP]:
            self.camera_pitch(self.rotation_speed)
        self.camera_mouse()
        
    
    def camera_mouse(self):
        # get mouse position
        print(pyautogui.position())
        # calc the difference between the center of the screen and the mouse position
        mouse_x, mouse_y = pyautogui.position()
        diff_x = self.render.WIDTH / 2 - mouse_x
        diff_y = self.render.HEIGHT / 2 - mouse_y
        # set the mouse position to the center of the screen
        if diff_x > 0:
            self.camera_yaw(self.rotation_speed * self.sensitivity * -diff_x)
        elif diff_x < 0:
            self.camera_yaw(-self.rotation_speed * self.sensitivity * diff_x)
        if diff_y > 0:
            self.camera_pitch(self.rotation_speed * self.sensitivity * -diff_y)
        elif diff_y < 0:
            self.camera_pitch(-self.rotation_speed * self.sensitivity * diff_y)
        # calc the angle of the mouse movement
        pg.mouse.set_pos(self.render.WIDTH / 2, self.render.HEIGHT / 2)

    def camera_yaw(self, angle):
        self.angleYaw += angle

    def camera_pitch(self, angle):
        self.anglePitch += angle

    def axiiIdentity(self):
        self.forward = np.array([0, 0, 1, 1])
        self.up = np.array([0, 1, 0, 1])
        self.right = np.array([1, 0, 0, 1])

    def camera_update_axii(self):
        # rotate = rotate_y(self.angleYaw) @ rotate_x(self.anglePitch)
        rotate = rotate_x(self.anglePitch) @ rotate_y(self.angleYaw)  # this concatenation gives right visual
        self.axiiIdentity()
        self.forward = self.forward @ rotate
        self.right = self.right @ rotate
        self.up = self.up @ rotate

    def camera_matrix(self):
        self.camera_update_axii()
        return self.translate_matrix() @ self.rotate_matrix()

    def translate_matrix(self):
        x, y, z, w = self.position
        return np.array([
            [1, 0, 0, 0],
            [0, 1, 0, 0],
            [0, 0, 1, 0],
            [-x, -y, -z, 1]
        ])

    def rotate_matrix(self):
        rx, ry, rz, w = self.right
        fx, fy, fz, w = self.forward
        ux, uy, uz, w = self.up
        return np.array([
            [rx, ux, fx, 0],
            [ry, uy, fy, 0],
            [rz, uz, fz, 0],
            [0, 0, 0, 1]
        ])
