#ifndef LOGIC_HPP__
# define LOGIC_HPP__

#include <cstdlib>
#include "Board.hpp"

class			ALogic
{
public:
  ALogic(Board board, int gameSize);
  ALogic() {};
  virtual ~ALogic();

  Board			getBoard();
  int			getGameSize();
  bool			haveVictoryAt(int x, int y, CellState color);
  bool			haveVictoryAt(Point location, CellState color);
  virtual Point		selectBestCell(CellState color) = 0;
  CellState		getOpponentColor(CellState color);
  int			countStonesInDirection(Point start, int dx, int dy, CellState color);
  int			calcScore(Point location, CellState color);

private:
  Board			_board;
  int			_gameSize;
};

#endif
