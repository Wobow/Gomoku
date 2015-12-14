//
// Game.cpp for Game in /home/trupin_t/rendu/gomoku_client
// 
// Made by Thomas Trupin
// Login   <trupin_t@epitech.net>
// 
// Started on Thu Dec 10 15:53:30 2015 Thomas Trupin
// Last update Sat Dec 12 02:54:02 2015 Thomas Trupin
//

#include	"Game.hpp"
#include	"GameState.hpp"

Game::Game() : 
  _arbiter(this)
{
  this->loadTextures();
  _window.create(sf::VideoMode(WINDOW_W, WINDOW_H), WINDOW_NAME, sf::Style::Titlebar |sf::Style::Close);
  _window.setFramerateLimit(60);
  _background.setTexture(_txmgr.getRef("background"));
  _background.setScale(
		       float(WINDOW_W) / float(_background.getTexture()->getSize().x),
		       float(WINDOW_H) / float(_background.getTexture()->getSize().y));
  for (int i = 0; i != BOARD_W; i ++)
    for (int j = 0; j != BOARD_H; j++)
      _map[i][j] = new Tile(i * TILE_W + BORDER, j * TILE_H + BORDER);
  _arbiter.setMap(_map);
  _captures[0] = 0;
  _captures[1] = 0;
}

Game::~Game()
{
  while (!_states.empty())
    popState();
}

void		Game::loadTextures()
{
  _txmgr.loadTexture("background", "ressources/sprites/background.png");
  _txmgr.loadTexture("white", "ressources/sprites/whitePoint.png");
  _txmgr.loadTexture("black", "ressources/sprites/blackPoint.png");
  _txmgr.loadTexture("blank", "ressources/sprites/blank.png");
  _txmgr.loadTexture("whiteT", "ressources/sprites/whitePointTrans.png");
  _txmgr.loadTexture("blackT", "ressources/sprites/blackPointTrans.png");
  _txmgr.loadTexture("wrong", "ressources/sprites/wrong.png");
}

void		Game::pushState(GameState *state)
{
  _states.push(state);
}

void		Game::popState()
{
  delete _states.top();
  _states.pop();
}

void		Game::changeState(GameState *state)
{
  if (!_states.empty())
    popState();
  pushState(state);
}

GameState	*Game::peekState()
{
  if (_states.empty())
    return (nullptr);
  return (_states.top());
}

Arbiter		Game::getArbiter()
{
  return (_arbiter);
}

void		Game::gameOver(int player)
{
  std::cout << "Player " << player << " has won" << std::endl;
}

void		Game::captureStones(int nb, char player)
{
  _captures[player - 1] += nb;
  if (_captures[player - 1] >= 10)
    gameOver(player);
}

void		Game::gameLoop()
{
  sf::Clock	clock;

  while (_window.isOpen())
    {
      sf::Time	elapsed = clock.restart();
      float	dt = elapsed.asSeconds();

      if (peekState() == nullptr)
	continue;
      peekState()->handleInput();
      peekState()->update(dt);
      _window.clear(sf::Color::Black);
      peekState()->draw(dt);
      _window.display();
    }
}

void		Game::drawMap()
{
  for (int i = 0; i != BOARD_W; i++)
      for (int j = 0; j != BOARD_H; j++)
	_map[i][j]->draw(_window);
}
