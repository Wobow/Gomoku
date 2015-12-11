//
// Game.hpp for Game in /home/trupin_t/rendu/gomoku_client
// 
// Made by Thomas Trupin
// Login   <trupin_t@epitech.net>
// 
// Started on Thu Dec 10 15:53:01 2015 Thomas Trupin
// Last update Fri Dec 11 23:57:40 2015 Thomas Trupin
//

#ifndef GAME_H_
# define GAME_H_

#include	<stack>
#include	<map>
#include	<cstring>
#include	<string>
#include	<SFML/Graphics.hpp>
#include	<SFML/System.hpp>
#include	<iostream>
#include	"TextureManager.hpp"
#include	"Tile.hpp"

#define		WINDOW_NAME	"Gomoku no desu ne"
#define		WINDOW_W	720
#define		WINDOW_H	720

#define		BOARD_W		19
#define		BOARD_H		19
#define		TILE_W		35
#define		TILE_H		35
#define		BORDER		27

class	GameState;

class	Game
{
public:
  Game();
  ~Game();

  void				pushState(GameState *state);
  void				popState();
  void				changeState(GameState *state);

  GameState			*peekState();

  void				gameLoop();
  void				loadTextures();
  void				drawMap();

  std::stack<GameState*>	_states;
  sf::RenderWindow		_window;
  sf::Sprite			_background;
  TextureManager		_txmgr;
  Tile				*_map[19][19];
};

#endif /*!GAME_H_*/
