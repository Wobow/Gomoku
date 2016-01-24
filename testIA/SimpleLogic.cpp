#include "SimpleLogic.hpp"

SimpleLogic::SimpleLogic(Board board, int gameSize)
{
  _board = board;
  _gameSize = gameSize;
}

SimpleLogic::~SimpleLogic() {}

Point			SimpleLogic::selectBestCell(CellState color)
{
  std::list<Point>	candidates = filterCellStageThree(color);

  if (candidates.size() == 0)
    return (Point(-1, -1));
  if (candidates.size() == 1)
    return (candidates.front());
  int			index;

  srand(time(NULL));
  index = rand() % (candidates.size() - 1);
  std::list<Point>	tmp;

  tmp = candidates;
  for (int i = 0; i != index; i++)
    {
      tmp.pop_front();
    }
  return (tmp.front());
}

std::list<Point>	SimpleLogic::filterCellStageOne(CellState color)
{
  return (filterCellCore(_board.enumerateCells(), 1, color));
}

std::list<Point>	SimpleLogic::filterCellStageTwo(CellState color)
{
  return (filterCellCore(filterCellStageOne(color), 2, color));
}

std::list<Point>	SimpleLogic::filterCellStageThree(CellState color)
{
  return (filterCellCore(filterCellStageTwo(color), 3, color));
}

std::list<Point>	SimpleLogic::filterCellCore(std::list<Point> source, int stage, CellState color)
{
  std::list<Point>	result;
  std::list<Point>	tmp;
  Point			tmpPoint(0, 0);
  int			bestEstimate;
  int			estimate;

  tmp = source;
  while (tmp.size() > 0)
    {
      tmpPoint = tmp.front();
      if (_board.getStone(tmpPoint) == None)
	break;
      if (stage == 1)
	estimate = estimateForStageOne(tmpPoint, color);
      if (stage == 2)
	estimate = estimateForStageTwo(tmpPoint, color);
      if (stage == 3)
	estimate = estimateForStageThree(tmpPoint, color);
      if (estimate > bestEstimate)
	{
	  result.clear();
	  bestEstimate = estimate;
	}
      result.push_back(tmpPoint);
      tmp.pop_front();
    }
  return (result);
}

int			SimpleLogic::estimateForStageOne(Point location, CellState color)
{
  int			selfScore;
  int			opponentScore;

  selfScore = 1 + calcScore(location, color);
  opponentScore = 1 + calcScore(location, getOpponentColor(color));
  if (selfScore >= _gameSize)
    selfScore = INTMAX;
  return (selfScore > opponentScore ? selfScore : opponentScore);
}

int			SimpleLogic::estimateForStageOne(int x, int y, CellState color)
{
  return (estimateForStageOne(Point(x, y), color));
}

int			SimpleLogic::estimateForStageTwo(Point location, CellState color)
{
  int			cx = location.getX();
  int			cy = location.getY();
  int			selfCount = 0;
  int			opponentCount = 0;

  for (int x = cx - 1; x <= cx + 1; x++)
    {
      for (int y = cy - 1; y <= cy + 1; y++)
	{
	  if (_board.getStone(x, y) == color)
	    selfCount++;
	  if (_board.getStone(x, y) == getOpponentColor(color))
	    opponentCount++;
	}
    }
  return (2 * selfCount + opponentCount);
}

int			SimpleLogic::estimateForStageTwo(int x, int y, CellState color)
{
  return (estimateForStageTwo(Point(x, y), color));
}

int			SimpleLogic::estimateForStageThree(Point location, CellState color)
{
  double		dx = location.getX() - _board.getSize() / 2;
  double		dy = location.getY() - _board.getSize() / 2;

  return (sqrt(dx * dx + dy * dy));
}

int			SimpleLogic::estimateForStageThree(int x, int y, CellState color)
{
  return (estimateForStageThree(Point(x, y), color));
}
