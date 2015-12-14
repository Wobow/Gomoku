//
// Tile.hpp for Tile in /home/trupin_t/rendu/gomoku_client
// 
// Made by Thomas Trupin
// Login   <trupin_t@epitech.net>
// 
// Started on Fri Dec 11 18:13:06 2015 Thomas Trupin
// Last update Sat Dec 12 00:19:53 2015 Thomas Trupin
//

#ifndef TILE_H_
# define TILE_H_

#include	<SFML/Graphics.hpp>
#include	<iostream>

enum		e_color
{
  BLANK,
  WHITE,
  BLACK,
  TRANS
};

class Tile
{
public:
  Tile(int x, int y);

  void		draw(sf::RenderWindow &window);
  void		setState(e_color kek, sf::Texture &texture);
  e_color	getState();

private:
  sf::Sprite	_sprite;
  e_color	_color;
};

#endif /*!TILE_H_*/
