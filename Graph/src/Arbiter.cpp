//
// Game.cpp for Game in /home/trupin_t/rendu/gomoku_client
// 
// Made by Thomas Trupin
// Login   <trupin_t@epitech.net>
// 
// Started on Thu Dec 10 15:53:30 2015 Thomas Trupin
// Last update Sat Dec 12 02:54:02 2015 Thomas Trupin
//

#include <vector>
#include "Arbiter.hpp"
#include "Game.hpp"

Arbiter::Arbiter(Game *game)
{
  this->_game = game;
}

Arbiter::~Arbiter() 
{}

void	Arbiter::setMap(Tile *(*map)[19])
{
  this->_map = map;
}

void	Arbiter::removePawns(std::vector<Pos> *pawns)
{
  for (Pos p : *pawns)
    {
      _map[p.x][p.y]->setState(BLANK, _game->_txmgr.getRef("blank"));
    }
}

bool	Arbiter::isEating(char turn, int posX, int posY, int dX, int dY)
{
  if (posX + dX >= 0 && posX + dX < 19 && posY + dY >= 0 && posY + dY < 19 && 
      _map[posX + dX][posY + dY]->getState() == OTHER_PLAYER)
    {
      std::vector<Pos> *pos = new std::vector<Pos>();
      Pos p(posX, posY);
      pos->push_back(p);
      if (isSuicidal(OTHER_PLAYER, posX + dX, posY + dY, pos))
	{
	  removePawns(pos);
	  delete pos;
	  return (true);
	}
      delete pos;
    }
  return (false);
}

bool	Arbiter::isMoveLegit(char turn, int posX, int posY)
{
  if (isEating(turn, posX, posY, -1, 0))
    return (true);
  if (isEating(turn, posX, posY, 1, 0))
    return (true);
  if (isEating(turn, posX, posY, 0, -1))
    return (true);
  if (isEating(turn, posX, posY, 0, 1))
    return (true);  
  std::vector<Pos> *pos = new std::vector<Pos>();
  bool out = (!isSuicidal(turn, posX, posY, pos));
  delete pos;
  return (out);
}

bool	Arbiter::isSuicidal(char turn, int posX, int posY, std::vector<Pos> *pos)
{
  if (posX < 0 || posX >= 19 || posY < 0 || posY >= 19)
    return (true);
  for (Pos p : *pos)
    {
      if (p.x == posX && p.y == posY)
	return (true);
    }
  if (pos->size() != 0 && _map[posX][posY]->getState() == BLANK)
    return (false);
  if (_map[posX][posY]->getState() == OTHER_PLAYER)
    return (true);
  Pos me(posX, posY);
  pos->push_back(me);
  if (!isSuicidal(turn, posX + 1, posY, pos) ||
      !isSuicidal(turn, posX, posY + 1, pos) ||
      !isSuicidal(turn, posX - 1, posY, pos) ||
      !isSuicidal(turn, posX, posY - 1, pos))
    return (false);
  return (true);
}

