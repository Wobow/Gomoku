//
// GameStateStart.cpp for GameStateStart in /home/trupin_t/rendu/gomoku_client
// 
// Made by Thomas Trupin
// Login   <trupin_t@epitech.net>
// 
// Started on Thu Dec 10 15:53:45 2015 Thomas Trupin
// Last update Sat Dec 12 02:49:37 2015 Thomas Trupin
//

#include	"GameStateStart.hpp"

GameStateStart::GameStateStart(Game *game)
{
  _game = game;
  sf::Vector2f pos = sf::Vector2f(_game->_window.getSize());
  _view.setSize(pos);
  pos *= 0.5f;
  _view.setCenter(pos);
  _turn = DEFAULT_TURN;
}

void		GameStateStart::draw(const float dt)
{
  (void)dt;
  _game->_window.setView(_view);
  _game->_window.clear(sf::Color::Black);
  _game->_window.draw(_game->_background);
  _game->drawMap();
}

void		GameStateStart::update(const float dt)
{
  (void)dt;
}

void		GameStateStart::handleInput()
{
  sf::Event	event;

  while (_game->_window.pollEvent(event))
    {
      switch(event.type)
	{
	case sf::Event::Closed:
	  {
	    _game->_window.close();
	    break;
	  }
	case sf::Event::KeyPressed:
	  {
	    if (event.key.code == sf::Keyboard::Escape)
	      _game->_window.close();
	    else if (event.key.code == sf::Keyboard::Space)
	      loadGame();
	    break;
	  }
	case sf::Event::MouseButtonPressed:
	  this->playTurn(event);
	default:
	  break;
	}
    }
}

void		GameStateStart::playTurn(sf::Event event)
{
  int		abs = event.mouseButton.x / TILE_W;
  int		ord = event.mouseButton.y / TILE_H;

  if (0 <= abs && abs <= BOARD_W - 1 && 0 <= ord && ord <= BOARD_H - 1)
    {
      if (_game->_map[abs][ord]->getState() == BLANK && _game->getArbiter().isMoveLegit(_turn, abs, ord))
	{
	  if (_turn == 1)
	    _game->_map[abs][ord]->setState(WHITE, _game->_txmgr.getRef("white"));
	  else
	    _game->_map[abs][ord]->setState(BLACK, _game->_txmgr.getRef("black"));
	  _turn == 1 ? _turn = 2 : _turn = 1;
	}
    }
}

void		GameStateStart::loadGame()
{
  std::cout << "newGame" << std::endl;
  //  _game->pushState(new GameStateEditor(_game));
}
