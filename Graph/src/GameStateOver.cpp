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
#include	"GameStateOver.hpp"

GameStateOver::GameStateOver(Game *game)
{
  _game = game;
  sf::Vector2f pos = sf::Vector2f(_game->_window.getSize());
  _view.setSize(pos);
  pos *= 0.5f;
  _view.setCenter(pos);
  _turn = DEFAULT_TURN;
}

void		GameStateOver::draw(const float dt)
{
  (void)dt;
  _game->_window.setView(_view);
  _game->_window.clear(sf::Color::Black);
  _game->_window.draw(_game->_background);
  _game->drawMap();
  _game->drawOver();
}

void	        GameStateOver::update(const float dt)
{
  (void)dt;
}

void	        GameStateOver::handleInput()
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
	      replay();
	    break;
	  }
	default:
	  break;
	}
    }
}

void		GameStateOver::replay()
{
  _game->changeState(new GameStateStart(_game));
}
