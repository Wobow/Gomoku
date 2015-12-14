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
#include	"GameStateOver.hpp"

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

void	Game::resetMap()
{
  for (int i = 0; i != BOARD_W; i ++)
    for (int j = 0; j != BOARD_H; j++)
      _map[i][j]->setState(BLANK, _txmgr.getRef("blank"));
  _captures[0] = 0;
  _captures[1] = 0;
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
  _txmgr.loadFont("ressources/fonts/arial.ttf");
}

void		Game::pushState(GameState *state)
{
  _states.push(state);
}

void		Game::popState()
{
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
  _isOver = player;
  changeState(new GameStateOver(this));
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

  sf::Text cpWhite;
  sf::Text cpBlack;
  sf::Color grey(31, 31, 31);
  sf::Color white(221, 221, 221);
  cpWhite.setFont(_txmgr.getFont());
  cpWhite.setString(std::to_string(_captures[WHITE - 1]));
  cpWhite.setColor(grey);
  cpWhite.setCharacterSize(50);
  cpWhite.setPosition(650, 725);
  cpBlack.setFont(_txmgr.getFont());
  cpBlack.setString(std::to_string(_captures[BLACK - 1]));
  cpBlack.setColor(white);
  cpBlack.setCharacterSize(50);
  cpBlack.setPosition(50, 725);
  _window.draw(cpWhite);
  _window.draw(cpBlack);
}

void		Game::drawOver()
{
  sf::RectangleShape rect(sf::Vector2f(WINDOW_W, WINDOW_H));
  rect.setFillColor(sf::Color(0, 0, 0, 100));
  _window.draw(rect);
  sf::Text gameOver;
  sf::Text playAgain;
  gameOver.setFont(_txmgr.getFont());
  gameOver.setString("Player " + std::to_string(_isOver) + " won");
  gameOver.setColor(sf::Color(221, 221, 221));
  gameOver.setCharacterSize(50);
  gameOver.setPosition(250, 300);
  playAgain.setFont(_txmgr.getFont());
  playAgain.setString("Press space to play again");
  playAgain.setColor(sf::Color(221, 221, 221));
  playAgain.setCharacterSize(30);
  playAgain.setPosition(250, 360);
  _window.draw(gameOver);
  _window.draw(playAgain);
}
