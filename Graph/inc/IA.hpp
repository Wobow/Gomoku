//
// GameStateIA.hpp for GameStateIA in /home/trupin_t/rendu/gomoku_client
// 
// Made by Thomas Trupin
// Login   <trupin_t@epitech.net>
// 
// Started on Thu Dec 10 15:53:23 2015 Thomas Trupin
// Last update Sat Dec 12 00:14:07 2015 Thomas Trupin
//

#ifndef IA_H_
# define IA_H_

#include	<SFML/Graphics.hpp>
#include	<iostream>

class	GameStateIA;

class	IA
{
public:
  IA(GameStateIA *);
  ~IA();

public:
  void		play();

private:
  GameStateIA	*_state;
};

#endif
