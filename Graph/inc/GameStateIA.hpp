//
// GameStateIA.hpp for GameStateIA in /home/trupin_t/rendu/gomoku_client
// 
// Made by Thomas Trupin
// Login   <trupin_t@epitech.net>
// 
// Started on Thu Dec 10 15:53:23 2015 Thomas Trupin
// Last update Sat Dec 12 00:14:07 2015 Thomas Trupin
//

#ifndef GAMESTATEIA_H_
# define GAMESTATEIA_H_

#include	<SFML/Graphics.hpp>
#include	<iostream>
#include	"GameState.hpp"
#include	"IA.hpp"

#ifndef DEFAULT_TURN
# define DEFAULT_TURN 1
#endif

class GameStateIA : public GameState
{
public:
  GameStateIA(Game *game, char plColor);

  virtual void	draw(const float dt);
  virtual void	update(const float dt);
  virtual void	handleInput();
  void		playTurn(int, int);

private:
  sf::View	_view;
  char		_turn;
  char		_plColor;
  IA		_ia;

  void		loadGame();
  void		playTurn(sf::Event event);
  void		displayPreview(sf::Event event);
  
};

#endif /*!GAMESTATEIA_H_*/
