//
// TextureManager.cpp for TextureManager in /home/trupin_t/rendu/gomoku_client
// 
// Made by Thomas Trupin
// Login   <trupin_t@epitech.net>
// 
// Started on Thu Dec 10 16:03:48 2015 Thomas Trupin
// Last update Thu Dec 10 16:03:52 2015 Thomas Trupin
//

#include	"TextureManager.hpp"

void		TextureManager::loadTexture(std::string const &name, std::string const &filename)
{
  sf::Texture	tex;

  tex.loadFromFile(filename);
  _textures[name] = tex;
}

sf::Texture	&TextureManager::getRef(const std::string texture)
{
  return (_textures.at(texture));
}

void		TextureManager::loadFont(std::string const &filename)
{
  sf::Font      font;

  font.loadFromFile(filename);
  _font = font;
}

sf::Font	&TextureManager::getFont()
{
  return (_font);
}
