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

# define OTHER_PLAYER (turn == WHITE ? BLACK : WHITE)

class	Game;

class	Arbiter
{
public:
  Arbiter(Game*);
  ~Arbiter();

public:
  void  setMap(Tile *(*map)[19]);
  bool	isMoveLegit(char turn, int posX, int poxY);

private:
  bool isSuicidal(char turn, int posX, int poxY, std::vector<Pos>* pos);
  bool	isEating(char turn, int posX, int posY, int dX, int dY);
  void	removePawns(std::vector<Pos>*);

private:
  Tile	*(*_map)[19];  
  Game	*_game;
};
