#include "io.hpp"
#include <fstream>
#include <cstdio>

sf::Color* read_conf(char* file, int& cell_count, int& cell_size, int& colr_count){
  sf::Color* values;
  std::ifstream in(file);
  in>>cell_count>>cell_size>>colr_count;
  values = new sf::Color[colr_count];
  char hex_code[8];
  int r, g, b;
  for(int iter=0; iter<colr_count; iter++){
    in.getline(hex_code, 8);
    sscanf(hex_code, "#%02x%02x%02x", r, g, b);
    values[iter].r = r;
    values[iter].g = g;
    values[iter].b = b;
  }
  in.close();
  return values;
}
