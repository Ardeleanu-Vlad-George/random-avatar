#include "img_comp.hpp"

sf::Image from_mask(int cell_count, int cell_size, int **mask, sf::Color *values, int colr_count){
  sf::Image result;
  result.create(cell_count*cell_size, cell_count*cell_size);
  
  for(int iter_x; iter_x < cell_count*cell_size; iter_x++)
    for(int iter_y; iter_y < cell_count*cell_size; iter_y++)
      result.setPixel(iter_x, iter_y, values[mask[iter_y/cell_size][iter_x/cell_size]]);

  return result;
}
