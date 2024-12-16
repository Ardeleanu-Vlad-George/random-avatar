#include <SFML/Graphics.hpp>
#include "io.hpp"
#include "comp.hpp"
#include "img_comp.hpp"

int main(){
  int **mask;
  int cell_count, cell_size, colr_count;
  sf::Color *colors;
  colors = read_conf("data/config", cell_count, cell_size, colr_count);

  mask = create(cell_count);
  assign(cell_count, colr_count, mask);
  sf::Image avatar = from_mask(cell_count, cell_size, mask, colors, colr_count);
  avatar.saveToFile("data/img/out.png");
  delete *mask;
  delete mask;
  delete colors;
  return 0;
}
