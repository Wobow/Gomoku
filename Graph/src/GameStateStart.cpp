//
// GameStateStart.cpp for GameStateStart in /home/trupin_t/rendu/gomoku_client
// 
// Made by Thomas Trupin
// Login   <trupin_t@epitech.net>
// 
// Started on Thu Dec 10 15:53:45 2015 Thomas Trupin
// Last update Sat Dec 12 02:49:37 2015 Thomas Trupin
//

#include	"GameStateMenu.hpp"
#include	"GameStateStart.hpp"

GameStateStart::GameStateStart(Game *game)
{
  _game = game;
  sf::Vector2f pos = sf::Vector2f(_game->_window.getSize());
  _view.setSize(pos);
  pos *= 0.5f;
  _view.setCenter(pos);
  _turn = DEFAULT_TURN;
  _game->setBackground("background");
  _game->resetMap();
}

void		GameStateStart::draw(const float dt)
{
  (void)dt;
  _game->_window.setView(_view);
  _game->_window.clear(sf::Color::Black);
  _game->_window.draw(_game->_background);
  _game->drawMap();
  _game->drawCurrentPlayer(_turn);
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
	      _game->changeState(new GameStateMenu(_game));
	    else if (event.key.code == sf::Keyboard::Num3 ||
		     event.key.code == sf::Keyboard::Numpad3)
	      _game->_doubleThreeRule = !_game->_doubleThreeRule;
	    else if (event.key.code == sf::Keyboard::Num5 ||
		     event.key.code == sf::Keyboard::Numpad5)
	      _game->_pentakillu = !_game->_pentakillu;
	    else if (event.key.code == sf::Keyboard::Space)
	      loadGame();
	    break;
	  }
	case sf::Event::MouseButtonPressed:
	  this->playTurn(event);
	  break;
	case sf::Event::MouseMoved:
	  this->displayPreview(event);
	  break;
	default:
	  break;
	}
    }
}

void		GameStateStart::displayPreview(sf::Event event)
{
  static int	oldabs = 0;
  static int	oldord = 0;
  static char	oldturn = 0;
  int		abs = (event.mouseMove.x - BORDER_W) / TILE_W;
  int		ord = (event.mouseMove.y - BORDER_H) / TILE_H;

  if (0 <= abs && abs <= BOARD_W - 1 && 0 <= ord && ord <= BOARD_H - 1)
    {
      if ((oldabs != abs || oldord != ord) &&
	  _game->_map[oldabs][oldord]->getState() == TRANS && oldturn == _turn)
	_game->_map[oldabs][oldord]->setState(BLANK, _game->_txmgr.getRef("blank"));
      oldabs = abs;
      oldord = ord;
      oldturn = _turn;
      if ((_game->_map[abs][ord]->getState() == BLANK ||
	   _game->_map[abs][ord]->getState() == TRANS))
	{
	  if (_game->getArbiter().isMoveLegit(_turn, abs, ord, false))
	    {
	      if (_turn == 1)
		_game->_map[abs][ord]->setState(TRANS, _game->_txmgr.getRef("whiteT"));
	      else
		_game->_map[abs][ord]->setState(TRANS, _game->_txmgr.getRef("blackT"));
	    }
	  else
	    _game->_map[abs][ord]->setState(TRANS, _game->_txmgr.getRef("wrong"));
	}
    }
}
 
void		GameStateStart::playTurn(sf::Event event)
{
  int		abs = (event.mouseButton.x - BORDER_W) / TILE_W;
  int		ord = (event.mouseButton.y - BORDER_H) / TILE_H;

  if (0 <= abs && abs <= BOARD_W - 1 && 0 <= ord && ord <= BOARD_H - 1)
    {
      if ((_game->_map[abs][ord]->getState() == BLANK ||
	   _game->_map[abs][ord]->getState() == TRANS) &&
	  _game->getArbiter().isMoveLegit(_turn, abs, ord, true))
	{
	  if (_turn == 1)
	    _game->_map[abs][ord]->setState(WHITE, _game->_txmgr.getRef("white"));
	  else
	    _game->_map[abs][ord]->setState(BLACK, _game->_txmgr.getRef("black"));
	  for (int x = 0; x < 19; x++)
	    {
	      for (int y = 0; y < 19; y++)
		{
		  if (_game->_map[x][y]->getState() != BLANK &&
		      _game->getArbiter().hasPentakillu(_turn, x, y))
		    {
		      _game->gameOver(_turn);
		      return ;
		    }
		}
	    }
	  _turn == 1 ? _turn = 2 : _turn = 1;
	}
    }
}

  void		GameStateStart::loadGame()
  {
    std::cout << "newGame" << std::endl;
    //  _game->pushState(new GameStateEditor(_game));
  }
