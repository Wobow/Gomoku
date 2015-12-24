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
  _game->setBackground("base_menu");
  sf::Vector2f pos = sf::Vector2f(_game->_window.getSize());
  _view.setSize(pos);
  pos *= 0.5f;
  _view.setCenter(pos);
  _selected = M_PLAY;
}

void		GameStateMenu::draw(const float dt)
{
  (void)dt;
  _game->_window.setView(_view);
  _game->_window.clear(sf::Color::Black);
  _game->_window.draw(_game->_background);
  _game->drawMenu(_selected);
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
	    else if (event.key.code == sf::Keyboard::Down)
	      rotate_down();
	    else if (event.key.code == sf::Keyboard::Up)
	      rotate_up();
	    else if (event.key.code == sf::Keyboard::Return)
	      launch();
	    break;
	  }
	case sf::Event::MouseMoved:
	  {
	    moveToCursor(event);
	    break;
	  }
	case sf::Event::MouseButtonPressed:
	  {
	    launch();
	    break;
	  }
	default:
	  break;
	}
    }
}

void	GameStateMenu::moveToCursor(sf::Event event)
{
  std::vector<Pos*> pos;

  pos.push_back(new Pos(239, 352));
  pos.push_back(new Pos(352, 465));
  pos.push_back(new Pos(465, 575));
  pos.push_back(new Pos(575, 685));
  int i = 0;
  for (Pos *p : pos)
    {
      if (event.mouseMove.x > 410 && event.mouseMove.x <= 600 &&
	  event.mouseMove.y > p->x && event.mouseMove.y < p->y)
	_selected = (e_menu)i;
      i++;
    }
}

void	GameStateMenu::rotate_down()
{
  if (_selected != M_EXIT)
    _selected = (e_menu)((int)_selected + 1);
  else
    _selected = M_PLAY;
}

void	GameStateMenu::rotate_up()
{
  if (_selected != M_PLAY)
    _selected = (e_menu)((int)_selected - 1);
  else
    _selected = M_EXIT;
}

void	GameStateMenu::launch()
{
  switch (_selected)
    {
    case M_PLAY:
      _game->changeState(new GameStateStart(_game));
      break;
    case M_OPTIONS:
      // GameStateOptions
      break;
    case M_LOAD:
      // GameStateLoad
      break;
    case M_EXIT:
      _game->_window.close();
      break;
    }
}
