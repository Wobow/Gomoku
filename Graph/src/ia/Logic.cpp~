#include "Logic.hpp"

ALogic::ALogic(Board board, int gameSize)
{
  if (gameSize < 2)
    exit(-1);
  _board = board;
  _gameSize = gameSize;
}

ALogic::~ALogic() {}

Board		ALogic::getBoard()
{
  return (_board);
}

int		ALogic::getGameSize()
{
  return (_gameSize);
}

bool		ALogic::haveVictoryAt(int x, int y, CellState color)
{
  return (haveVictoryAt(Point(x, y), color));
}

bool		ALogic::haveVictoryAt(Point location, CellState color)
{
  return (_board.getStone(location) == color && calcScore(location, color) >= _gameSize - 1);
}

CellState	ALogic::getOpponentColor(CellState myColor)
{
  if (myColor == White)
    return (Black);
  if (myColor == Black)
    return (White);
  return (None);
}

int		ALogic::countStonesInDirection(Point start, int dx, int dy, CellState color)
{
  int		result = 0;

  for (int i = 0; i != _gameSize; i++)
    {
      Point current = start + Point(i * dx, i * dy);
      if (_board.getStone(current) != color)
	break;
      result++;
    }
  return (result);
}

int		ALogic::calcScore(Point location, CellState color)
{
  int		count[4] = {
    countStonesInDirection(location, -1, 0, color) + countStonesInDirection(location, 1, 0, color),
    countStonesInDirection(location, 0, -1, color) + countStonesInDirection(location, 0, 1, color),
    countStonesInDirection(location, -1, -1, color) + countStonesInDirection(location, 1, 1, color),
    countStonesInDirection(location, -1, 1, color) + countStonesInDirection(location, 1, -1, color)
  };
  int		result = 0;

  for (int i = 0; i != 4; i++)
    {
      result = result > count[i] ? result : count[i];
    }
  return (result);
}
