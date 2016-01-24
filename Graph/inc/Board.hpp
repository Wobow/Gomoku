#ifndef BOARD_HPP__
# define BOARD_HPP__

#include <list>
#include "CellState.hpp"
#include "Point.hpp"
#include "Tile.hpp"

class			Board
{
public:
  Board(int size, Tile *[19][19]);
  Board() {}
  ~Board();
  int			getSize();
  void			putStone(CellState color, Point location);
  void			putStone(CellState color, int x, int y);
  CellState		getStone(Point location);
  CellState		getStone(int x, int y);
  bool			isOutSide(int x, int y);
  void			clear(Tile*map[19][19]);
  std::list<Point>	enumerateCells();
private:
  int			_size;
  CellState		_stones[19][19];
};

#endif
