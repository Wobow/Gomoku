#include <cstdlib>
#include "Board.hpp"

Board::Board(int size, Tile *map[19][19])
{
  _size = size;
  clear(map);
}

Board::~Board() {}

int			Board::getSize()
{
  return (_size);
}

void			Board::putStone(CellState color, Point location)
{
  putStone(color, location.getX(), location.getY());
}

void			Board::putStone(CellState color, int x, int y)
{
  if (isOutSide(x, y))
    exit(-1);
  _stones[x][y] = color; 
}

CellState		Board::getStone(Point location)
{
  return (getStone(location.getX(), location.getY()));
}

CellState		Board::getStone(int x, int y)
{
  return (isOutSide(x, y) ? None : _stones[x][y]);
}

bool			Board::isOutSide(int x, int y)
{
  return (x < 0 || x > _size - 1 || y < 0 || y > _size - 1);
}

void			Board::clear(Tile *map[19][19])
{
  for (int i = 0; i != _size; i++)
    {
      for (int j = 0; j != _size; j++)
	{
	  if (map[i][j]->getState() == BLACK)
	    _stones[i][j] = Black;
	  if (map[i][j]->getState() == WHITE)
	    _stones[i][j] = White;
	  else
	    _stones[i][j] = None;
	  std::cout << " " << _stones[i][j] << " ";
	}
      std::cout << std::endl;
    }
}

std::list<Point>	Board::enumerateCells()
{
  std::list<Point>	liste;
  
  for (int x = 0; x != _size; x++)
    {
      for (int y = 0; y != _size; y++)
	{
	  liste.push_back(Point(x, y));
	}
    }
  return (liste);
}
