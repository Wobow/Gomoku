#ifndef SIMPLELOGIC_HPP__
# define SIMPLELOGIC_HPP__

#include <iterator>
#include <time.h>
#include <math.h>
#include "Logic.hpp"
#include "Board.hpp"

#define INTMAX		2147483647

class			SimpleLogic : public ALogic
{
public:
  SimpleLogic(Board board, int gameSize);
  SimpleLogic();
  ~SimpleLogic();

  Point			selectBestCell(CellState color);
  std::list<Point>	filterCellStageOne(CellState color);
  std::list<Point>	filterCellStageTwo(CellState color);
  std::list<Point>	filterCellStageThree(CellState color);
  std::list<Point>	filterCellCore(std::list<Point> source, int stage, CellState color);
  int			estimateForStageOne(Point location, CellState color);
  int			estimateForStageOne(int x, int y, CellState color);
  int			estimateForStageTwo(Point location, CellState color);
  int			estimateForStageTwo(int x, int y, CellState color);
  int			estimateForStageThree(Point location, CellState color);
  int			estimateForStageThree(int x, int y, CellState color);
private:
  Board			_board;
  int			_gameSize;
};

#endif
