//
// TextureManager.hpp for TextureManager in /home/trupin_t/rendu/gomoku_client
// 
// Made by Thomas Trupin
// Login   <trupin_t@epitech.net>
// 
// Started on Thu Dec 10 16:03:39 2015 Thomas Trupin
// Last update Thu Dec 10 16:03:42 2015 Thomas Trupin
//

#ifndef TEXTUREMANAGER_H_
# define TEXTUREMANAGER_H_

#include	<SFML/Graphics.hpp>
#include	<SFML/Graphics/Font.hpp>
#include	<string>
#include	<map>

class TextureManager
{
public:
  TextureManager(){}

  void		loadTexture(std::string const &name, std::string const &filename);
  sf::Texture	&getRef(const std::string texture);
void	        loadFont(std::string const &filename);
sf::Font	&getFont();


private:
  std::map<std::string, sf::Texture> _textures;
sf::Font	_font;
};

#endif /*!TEXTUREMANAGER_H_*/
