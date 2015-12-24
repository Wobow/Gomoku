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
#include	"Arbiter.hpp"

#define		WINDOW_NAME	"Gomoku no desu ne"
#define		WINDOW_W	1210
#define		WINDOW_H	700

#define		BOARD_W		19
#define		BOARD_H		19
#define		TILE_W		36.4
#define		TILE_H		36.4
#define		BORDER_W	260
#define		BORDER_H	7

typedef enum	e_menu {
  M_PLAY,
  M_LOAD,
  M_OPTIONS,
  M_EXIT
}		e_menu;

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
  void				drawOver();
  void				drawCurrentPlayer(int pl);
  void				drawMenu(e_menu selected);

  Arbiter			getArbiter();
  void				captureStones(int nb, char player);
  void				gameOver(int player);
  void				resetMap();
  void				setBackground(const std::string name);

  std::stack<GameState*>	_states;
  sf::RenderWindow		_window;
  sf::Sprite			_background;
  TextureManager		_txmgr;
  Tile				*_map[19][19];
  Arbiter			_arbiter;
  char				_captures[2];
  int				_isOver;
  bool				_doubleThreeRule;
  bool				_pentakillu;

};

#endif /*!GAME_H_*/
