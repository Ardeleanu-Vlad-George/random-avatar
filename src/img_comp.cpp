#include "img_comp.hpp"

sf::Image make_from_mask(int cell_size, int **mask, int cell_count, sf::Color *values, int colr_count){
  sf::Image result;
  result.create(cell_count*cell_size, cell_count*cell_size);
  
  for(int iter_x=0; iter_x < cell_count*cell_size; iter_x++)
    for(int iter_y=0; iter_y < cell_count*cell_size; iter_y++)
      result.setPixel(iter_x, iter_y, values[mask[iter_y/cell_size][iter_x/cell_size]]);

  return result;
}
