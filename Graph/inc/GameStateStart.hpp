//
// GameStateStart.hpp for GameStateStart in /home/trupin_t/rendu/gomoku_client
// 
// Made by Thomas Trupin
// Login   <trupin_t@epitech.net>
// 
// Started on Thu Dec 10 15:53:23 2015 Thomas Trupin
// Last update Sat Dec 12 00:14:07 2015 Thomas Trupin
//

#ifndef GAMESTATESTART_H_
# define GAMESTATESTART_H_

#include	<SFML/Graphics.hpp>
#include	<iostream>
#include	"GameState.hpp"

#define		DEFAULT_TURN	1

class GameStateStart : public GameState
{
public:
  GameStateStart(Game *game);

  virtual void	draw(const float dt);
  virtual void	update(const float dt);
  virtual void	handleInput();

private:
  sf::View	_view;
char		_turn;

  void		loadGame();
  void		playTurn(sf::Event event);
};

#endif /*!GAMESTATESTART_H_*/
