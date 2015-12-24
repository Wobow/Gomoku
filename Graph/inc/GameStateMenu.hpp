//
// GameStateStart.hpp for GameStateStart in /home/trupin_t/rendu/gomoku_client
// 
// Made by Thomas Trupin
// Login   <trupin_t@epitech.net>
// 
// Started on Thu Dec 10 15:53:23 2015 Thomas Trupin
// Last update Sat Dec 12 00:14:07 2015 Thomas Trupin
//

#pragma once

#include	<SFML/Graphics.hpp>
#include	<iostream>
#include	"GameState.hpp"

class GameStateMenu : public GameState
{
public:
  GameStateMenu(Game *game);

  virtual void	draw(const float dt);
  virtual void	update(const float dt);
  virtual void	handleInput();

private:
  void	rotate_down();
  void	rotate_up();
  void	launch();
  void	moveToCursor(sf::Event);

private:
  sf::View	_view;
  e_menu	_selected;
};

