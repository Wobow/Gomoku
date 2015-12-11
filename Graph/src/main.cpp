//
// main.cpp for main in /home/trupin_t/rendu/gomoku_client
// 
// Made by Thomas Trupin
// Login   <trupin_t@epitech.net>
// 
// Started on Thu Dec 10 15:53:52 2015 Thomas Trupin
// Last update Thu Dec 10 15:53:55 2015 Thomas Trupin
//

#include	"Game.hpp"
#include	"GameStateStart.hpp"

int main()
{
  Game		game;

  game.pushState(new GameStateStart(&game));
  game.gameLoop();
  return (EXIT_SUCCESS);
}
