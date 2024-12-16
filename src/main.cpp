#include <iostream>
#include <cstdlib>
#include <SFML/Graphics.hpp>
#include "io.hpp"
#include "comp.hpp"
#include "img_comp.hpp"

#define CELL_SIZE   84
#define CELL_COUNT  7

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
  // int mask[CELL_COUNT][CELL_COUNT];
  // for(int i=0; i < CELL_COUNT*CELL_COUNT; i++)
  //   mask[i/CELL_COUNT][i%CELL_COUNT]=0;
  // srand(time(NULL));
  //
  // //generate first half
  // for(int i=0; i < CELL_COUNT; i++)
  //   for(int j=0; j < CELL_COUNT/2+1; j++)
  //     mask[i][j]=rand()%6;
  //
  // //generate middle part
  // for(int i=0; i < CELL_COUNT; i++)
  //   mask[i][CELL_COUNT/2+1]=rand()%6;
  //
  // //mirror the first half over the other
  // for(int i=0; i < CELL_COUNT; i++)
  //   for(int j=0; j < CELL_COUNT/2+1; j++)
  //     mask[i][CELL_COUNT-1-j]=mask[i][j];
  //
  // //start saving into image
  //
  // sf::Color colors[6] = {
  //   sf::Color::Red, sf::Color::Blue, sf::Color::Green,
  //   sf::Color::Yellow, sf::Color::Cyan, sf::Color::Magenta
  // };
  //
  // sf::Image img;
  // img.create(CELL_COUNT*CELL_SIZE, CELL_COUNT*CELL_SIZE);
  //
  // for(int i=0; i < CELL_COUNT*CELL_SIZE; i++)
  //   for(int j=0; j < CELL_COUNT*CELL_SIZE; j++)
  //     img.setPixel(i, j, colors[mask[j/CELL_SIZE][i/CELL_SIZE]]);
  //
  // img.saveToFile("data/out.png");
  //
  // for(int i=0; i < CELL_COUNT*CELL_COUNT; i++)
  //   std::cout<<mask[i/CELL_COUNT][i%CELL_COUNT]<<(i%CELL_COUNT==CELL_COUNT-1 ? '\n' : '\0');
  return 0;
}
