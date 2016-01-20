//
// GameState.hpp for GameState in /home/trupin_t/rendu/gomoku_client
// 
// Made by Thomas Trupin
// Login   <trupin_t@epitech.net>
// 
// Started on Thu Dec 10 15:53:09 2015 Thomas Trupin
// Last update Thu Dec 10 15:53:12 2015 Thomas Trupin
//

#ifndef GAMESTATE_H_
# define GAMESTATE_H_

#include	"Game.hpp"

class GameState
{
public:
  virtual   ~GameState(){}

  Game		*_game;

  virtual void	draw(const float dt) = 0;
  virtual void	update(const float dt) = 0;
  virtual void	handleInput() = 0;
  virtual Game	*getGame() {
    return (_game);
  }
};

#endif /*!GAMESTATE_H_*/
