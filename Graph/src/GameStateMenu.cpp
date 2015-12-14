//
// GameStateStart.cpp for GameStateStart in /home/trupin_t/rendu/gomoku_client
// 
// Made by Thomas Trupin
// Login   <trupin_t@epitech.net>
// 
// Started on Thu Dec 10 15:53:45 2015 Thomas Trupin
// Last update Sat Dec 12 02:49:37 2015 Thomas Trupin

#include	"GameStateStart.hpp"
#include	"GameStateMenu.hpp"

GameStateMenu::GameStateMenu(Game *game)
{
  _game = game;
  sf::Vector2f pos = sf::Vector2f(_game->_window.getSize());
  _view.setSize(pos);
  pos *= 0.5f;
  _view.setCenter(pos);
}

void		GameStateMenu::draw(const float dt)
{
  (void)dt;
  _game->_window.setView(_view);
  _game->_window.clear(sf::Color::Black);
  _game->_window.draw(_game->_background);
  _game->drawMap();
  _game->drawMenu();
}

void	        GameStateMenu::update(const float dt)
{
  (void)dt;
}

void	        GameStateMenu::handleInput()
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
	      _game->changeState(new GameStateStart(_game));
	    break;
	  }
	default:
	  break;
	}
    }
}
