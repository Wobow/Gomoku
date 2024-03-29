//
// GameStateIA.cpp for GameStateIA in /home/trupin_t/rendu/gomoku_client
// 
// Made by Thomas Trupin
// Login   <trupin_t@epitech.net>
// 
// Started on Thu Dec 10 15:53:45 2015 Thomas Trupin
// Last update Sat Dec 12 02:49:37 2015 Thomas Trupin
//

#include "IA.hpp"
#include "GameStateIA.hpp"
#include "Board.hpp"
#include "SimpleLogic.hpp"

IA::IA(GameStateIA *state)
{
  _state = state;
}

IA::~IA()
{

}

void	IA::play(int color)
{
  Board b(19, _state->getGame()->_map);
  SimpleLogic logic(b, 19);

  CellState s = color == BLACK ? Black : White;
  Point p = logic.selectBestCell(s);
  std::cout << "Ia played at : " << p.getX() << ", " << p.getY() << std::endl;
  //  _state->getGame()->_map[x][y]->getState();
  // Get state of map cell at (x, y);
  _state->playTurn(p.getX(), p.getY());
}
