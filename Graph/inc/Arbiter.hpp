//
// Arbiter.hpp for Arbiter in /home/trupin_t/rendu/gomoku_client
// 
// Made by Alan Balbp
// Login   <balbo_a@epitech.net>
// 
// Started on Thu Dec 10 15:53:01 2015 Thomas Trupin
// Last update Fri Dec 11 23:57:40 2015 Thomas Trupin
//

#pragma once

#include  <string>
#include "Tile.hpp"
#include "Pos.hpp"
#include <vector>
#include <iostream>
#include <stack>

# define OTHER_PLAYER (turn == WHITE ? BLACK : WHITE)
# define ABS(X) (X < 0 ? -X : X)

class	Game;

class	Arbiter
{
public:
  Arbiter(Game*);
  ~Arbiter();

public:
  void  setMap(Tile *(*map)[19]);
  bool	isMoveLegit(char turn, int posX, int poxY, bool canEat);
  bool	hasPentakillu(char turn, int posX, int posY);

private:
  int	isEating(char turn, int posX, int posY, int dX, int dY);
  void	removePawns(int, int);
  std::vector<Pos*> *findThree(char turn, int posX, int posY, int dX, int dY, bool);
  void	eat(char turn, int posX, int posY);
  bool	checkDoubleThree(char turn, int posX, int posY, bool, int , int);
  bool	containsADoubleThree(char turn, std::vector<Pos*>*, int j, int k);
  bool	wereItSoEasy(char turn, std::vector<Pos*>*);
  std::vector<Pos*> *findPenta(char turn, int posX, int posY, int dX, int dY);

private:
  Tile	*(*_map)[19];  
  Game	*_game;
};
