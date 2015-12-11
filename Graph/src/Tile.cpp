//
// Tile.cpp for Tile in /home/trupin_t/rendu/gomoku_client
// 
// Made by Thomas Trupin
// Login   <trupin_t@epitech.net>
// 
// Started on Fri Dec 11 18:16:29 2015 Thomas Trupin
// Last update Sat Dec 12 00:21:27 2015 Thomas Trupin
//

#include	"Tile.hpp"

Tile::Tile(int x, int y)
{
  _color = BLANK;
  _sprite.setPosition(x, y);
}

void	Tile::draw(sf::RenderWindow &window)
{
  if (_color != BLANK)
    window.draw(_sprite);
}

void	Tile::setState(e_color kek, sf::Texture &texture)
{
  _color = kek;
  _sprite.setTexture(texture);
}

e_color	Tile::getState()
{
  return (_color);
}
