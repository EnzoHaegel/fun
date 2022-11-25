from Class.Utils.matrix_functions import *
from Class.Vec3 import Vec3
import pygame as pg

def any_func(arr, a, b):
    return np.any((arr == a) | (arr == b))

class Cube:
    def __init__(self, render, pos: Vec3 = Vec3(0, 0, 0)):
        self.render = render
        self.pos = pos
        self.vertices = np.array([
            (self.pos.x + 0, self.pos.z + 0, self.pos.y + 0, 1),   # 0
            (self.pos.x + 0, self.pos.z + 1, self.pos.y + 0, 1),   # 1
            (self.pos.x + 1, self.pos.z + 1, self.pos.y + 0, 1),   # 2
            (self.pos.x + 1, self.pos.z + 0, self.pos.y + 0, 1),   # 3
            (self.pos.x + 0, self.pos.z + 0, self.pos.y + 1, 1),   # 4
            (self.pos.x + 0, self.pos.z + 1, self.pos.y + 1, 1),   # 5
            (self.pos.x + 1, self.pos.z + 1, self.pos.y + 1, 1),   # 6
            (self.pos.x + 1, self.pos.z + 0, self.pos.y + 1, 1)    # 7
        ])
        self.faces = np.array([
            (0, 1, 2, 3),   # 0
            (4, 5, 6, 7),   # 1
            (0, 4, 5, 1),   # 2
            (2, 3, 7, 6),   # 3
            (1, 2, 6, 5),   # 4
            (0, 3, 7, 4)    # 5
        ])
        self.color_faces = [(pg.Color('orange'), face) for face in self.faces]
        self.movement_flag, self.draw_vertices = False, True
        self.label = ''

    def translate(self, pos):
        self.vertices = self.vertices @ translate(pos)
    
    def rotate_x(self, a):
        self.vertices = self.vertices @ rotate_x(a)
    
    def rotate_y(self, a):
        self.vertices = self.vertices @ rotate_y(a)
    
    def rotate_z(self, a):
        self.vertices = self.vertices @ rotate_z(a)
    
    def scale(self, n):
        self.vertices = self.vertices @ scale(n)
    
    def draw(self):
        self.screen_projection()
        self.movement()

    def movement(self):
        if self.movement_flag:
            self.rotate_y(-(pg.time.get_ticks() % 0.005))
    
    def screen_projection(self):
        vertices = self.vertices @ self.render.camera.camera_matrix()
        vertices = vertices @ self.render.projection.projection_matrix
        vertices /= vertices[:, -1].reshape(-1, 1)
        vertices[(vertices > 2) | (vertices < -2)] = 0
        vertices = vertices @ self.render.projection.to_screen_matrix
        vertices = vertices[:, :2]

        for index, color_face in enumerate(self.color_faces):
            color, face = color_face
            polygon = vertices[face]
            if not any_func(polygon, self.render.H_WIDTH, self.render.H_HEIGHT):
                pg.draw.polygon(self.render.screen, color, polygon, 1)
                if self.label:
                    text = self.font.render(self.label[index], True, pg.Color('white'))
                    self.render.screen.blit(text, polygon[-1])

        if self.draw_vertices:
            for vertex in vertices:
                if not any_func(vertex, self.render.H_WIDTH, self.render.H_HEIGHT):
                    pg.draw.circle(self.render.screen, pg.Color('white'), vertex, 2)
