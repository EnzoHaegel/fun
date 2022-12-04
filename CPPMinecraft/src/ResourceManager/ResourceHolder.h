#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Audio/SoundBuffer.hpp>

#include "ResourceManager.h"
#include "../Utils/NonCopyable.h"
#include "../Utils/NonMoveable.h"

class ResourceHolder : public NonCopyable, public NonMovable
{
public:
    static ResourceHolder &get();

    ResourceManager<sf::Font> fonts;
    ResourceManager<sf::Texture> textures;
    ResourceManager<sf::SoundBuffer> soundBuffers;

private:
    ResourceHolder();
};
