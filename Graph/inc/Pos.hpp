//
// Game.cpp for Game in /home/trupin_t/rendu/gomoku_client
// 
// Made by Thomas Trupin
// Login   <trupin_t@epitech.net>
// 
// Started on Thu Dec 10 15:53:30 2015 Thomas Trupin
// Last update Sat Dec 12 02:54:02 2015 Thomas Trupin
//

#pragma once

class Pos
{
public:
  Pos(int x, int y) 
  {
    this->x = x;
    this->y = y;
  }
  ~Pos() {};

public:
  int x;
  int y;
};
