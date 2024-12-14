#include <iostream>
#include <cstdlib>
#include <SFML/Graphics.hpp>

#define CELL_SIZE   84
#define CELL_COUNT  7

int main(){
  int mask[CELL_COUNT][CELL_COUNT];
  for(int i=0; i < CELL_COUNT*CELL_COUNT; i++)
    mask[i/CELL_COUNT][i%CELL_COUNT]=0;
  srand(time(NULL));

  //generate first half
  for(int i=0; i < CELL_COUNT; i++)
    for(int j=0; j < CELL_COUNT/2+1; j++)
      mask[i][j]=rand()%3;

  //generate middle part
  for(int i=0; i < CELL_COUNT; i++)
    mask[i][CELL_COUNT/2+1]=rand()%3;

  //mirror the first half over the other
  for(int i=0; i < CELL_COUNT; i++)
    for(int j=0; j < CELL_COUNT/2+1; j++)
      mask[i][CELL_COUNT-1-j]=mask[i][j];

  //start saving into image

  sf::Color colors[3];
  colors[0] = sf::Color(255, 0, 0);//primary
  colors[1] = sf::Color(0, 255, 0);//secondary
  colors[2] = sf::Color(0, 0, 255);//accent

  sf::Image img;
  img.create(CELL_COUNT*CELL_SIZE, CELL_COUNT*CELL_SIZE);

  for(int i=0; i < CELL_COUNT*CELL_SIZE; i++)
    for(int j=0; j < CELL_COUNT*CELL_SIZE; j++)
      img.setPixel(i, j, colors[mask[j/CELL_SIZE][i/CELL_SIZE]]);

  img.saveToFile("data/out.png");

  for(int i=0; i < CELL_COUNT*CELL_COUNT; i++)
    std::cout<<mask[i/CELL_COUNT][i%CELL_COUNT]<<(i%CELL_COUNT==CELL_COUNT-1 ? '\n' : '\0');
  return 0;
}
