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

void	Arbiter::removePawns(int posX, int posY)
{
  _map[posX][posY]->setState(BLANK, _game->_txmgr.getRef("blank"));
}

int	Arbiter::isEating(char turn, int posX, int posY, int dX, int dY)
{
  if (posX + 3 * dX < 0 || posX + 3 * dX >= 19 || posY + 3 * dY < 0 || posY + 3 * dY >= 19)
    return (0);
  if (_map[posX + dX][posY + dY]->getState() == OTHER_PLAYER &&
      _map[posX + 2 * dX][posY + 2 * dY]->getState() == OTHER_PLAYER &&
      _map[posX + 3 * dX][posY + 3 * dY]->getState() == turn)
    {
      removePawns(posX + dX, posY + dY);
      removePawns(posX + 2 * dX, posY + 2 * dY);
      return (2);
    }
  return (0);
}

std::vector<Pos*>	*Arbiter::findThree(char turn, int posX, int posY, int dX, int dY,
					    bool countCur)
{
  int			nb = 0;
  std::vector<Pos*>	*out = NULL;

  if (posX < 0 || posX >= 19 || posY < 0 || posY >= 19 || posX + 5 * dX < 0 || posX + 5 * dX >= 19 || posY + 5 * dY < 0 || posY + 5 * dY >= 19)
    return (NULL);
  for (int i = 0; i < 5; i++)
    {
      if (_map[posX + i * dX][posY + i * dY]->getState() == turn)
	nb++;
      if (nb > (countCur ? 2 : 3) || _map[posX + i * dX][posY + i * dY]->getState() == OTHER_PLAYER)
	return (out);
    }
  if (nb < (countCur ? 2 : 3))
    return (out);
  if (posX + -1 * dX < 0 || posY + -1 * dY < 0 || _map[posX + -1 * dX][posY + -1 * dY]->getState() != BLANK)
    return (NULL);
  if (posX + 5 * dX >= 19 || posY + 5 * dY >= 19 || _map[posX + 5 * dX][posY + 5 * dY]->getState() != BLANK)
    return (NULL);
  out = new std::vector<Pos*>();
  for (int i = 0; i < 5; i++)
    {
      Pos *p = new Pos(posX + i * dX, posY + i * dY);
      out->push_back(p);
    }
  return (out);
}

void	Arbiter::eat(char turn, int posX, int posY)
{
  int	eating;
  
  eating = isEating(turn, posX, posY, 1, 0);
  eating += isEating(turn, posX, posY, 0, 1);
  eating += isEating(turn, posX, posY, -1, 0);
  eating += isEating(turn, posX, posY, 0, -1);
  eating += isEating(turn, posX, posY, 1, 1);
  eating += isEating(turn, posX, posY, 1, -1);
  eating += isEating(turn, posX, posY, -1, 1);
  eating += isEating(turn, posX, posY, -1, -1);    
  _game->captureStones(eating, turn);
}

bool	Arbiter::containsADoubleThree(char turn, std::vector<Pos*> *th, int j, int k)
{
  for (Pos *p : *th)
    {
      if (checkDoubleThree(turn, p->x, p->y, true, j , k))
	return (true);
    }
  return (false);
}

bool			Arbiter::checkDoubleThree(char turn, int posX, int posY, bool returnIfFound,
						  int exj, int exk)
{
  std::vector<Pos*>	*th;

  for (int j = -1; j < 2; j++)
    {
      for (int k = -1; k < 2; k++)
	{
	  for (int i = -4; i < 0; i++)
	    {
	      if ((j != 0 || (j == 0 && k != 0)) && (!returnIfFound || !(exj == j && exk == k)))
		{
		  if ((th = findThree(turn, posX + i * j, posY + i * k, j, k, !returnIfFound)) != NULL)
		    {
		      if (returnIfFound || containsADoubleThree(turn, th, j, k))
			{
			  delete (th);
			  return (true);
			}
		      delete (th);
		    }
		}
	    }
	  if (k == -1 && j == -1)
	    j++;
	}
    }
  return (false);
}

std::vector<Pos*>	*Arbiter::findPenta(char turn, int posX, int posY, int dX, int dY)
{
  int			nb = 0;
  std::vector<Pos*>	*out = NULL;

  if (posX < 0 || posX >= 19 || posY < 0 || posY >= 19 || posX + 5 * dX < 0 || posX + 5 * dX >= 19 || posY + 5 * dY < 0 || posY + 5 * dY >= 19)
    return (NULL);
  for (int i = 0; i < 5; i++)
    {
      if (_map[posX + i * dX][posY + i * dY]->getState() == turn)
	nb++;
      else
	return (NULL);
    }
  if (nb < 5)
    return (NULL);
  out = new std::vector<Pos*>();
  for (int i = 0; i < 5; i++)
    {
      Pos *p = new Pos(posX + i * dX, posY + i * dY);
      out->push_back(p);
    }
  return (out);
}

bool	Arbiter::wereItSoEasy(char turn, std::vector<Pos*> *chain)
{
  return (false);
}

bool	Arbiter::hasPentakillu(char turn, int posX, int posY)
{
  std::vector<Pos*>	*th;

  for (int j = -1; j < 2; j++)
    {
      for (int k = -1; k < 2; k++)
	{
	  for (int i = -4; i <= 0; i++)
	    {
	      if (!(j == 0 && k == 0) &&
		  (th = findPenta(turn, posX + i * j, posY + i * k, j, k)) != NULL)
		{		 
		  if (wereItSoEasy(turn, th))
		    {
		      delete (th);
		      return (false);
		    }
		  return (true);
		  delete (th);
		}
	    }
	}
    }  
  return (false);
}

bool	Arbiter::isMoveLegit(char turn, int posX, int posY, bool canEat)
{
  if (checkDoubleThree(turn, posX, posY, false, 0, 0))
    return (false);
  if (canEat)
    eat(turn, posX, posY);
  return (true);
}

