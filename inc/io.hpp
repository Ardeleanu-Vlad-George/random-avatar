#ifndef _IO_HPP_
#define _IO_HPP_

#include <SFML/Graphic.hpp>

/**
  * Returns a C style array of colors, in the output parameters 
  * it saves the number of cells to be saved, the size of a cell
  * and the number of read colors
  * The first argument is the file from which these settings are 
  * read
*/
sf::Color* read_conf(char*, int&, int&);

#endif//_IO_HPP_
