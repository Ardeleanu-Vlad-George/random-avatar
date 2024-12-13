#include <iostream>
#include <cstdlib>
#include <SFML/Graphics.hpp>

#define CELL_SIZE 84

int main(){
  int mask[5][5];
  for(int i=0; i < 25; i++)
    mask[i/5][i%5]=0;
  srand(time(NULL));

  //generate first half
  for(int i=0; i < 5; i++)
    for(int j=0; j < 2; j++)
      mask[i][j]=rand()%3;

  //generate middle part
  for(int i=0; i < 5; i++)
    mask[i][2]=rand()%3;

  //mirror the first half over the other
  for(int i=0; i < 5; i++)
    for(int j=0; j < 2; j++)
      mask[i][4-j]=mask[i][j];

  //start saving into image

  sf::Color colors[3];
  colors[0] = sf::Color(155, 55, 55);//primary
  colors[1] = sf::Color(55, 155, 55);//secondary
  colors[2] = sf::Color(55, 55, 155);//accent

  sf::Image img;
  img.create(5*CELL_SIZE, 5*CELL_SIZE);

  for(int i=0; i < 5*CELL_SIZE; i++)
    for(int j=0; j < 5*CELL_SIZE; j++)
      img.setPixel(i, j, colors[mask[j/CELL_SIZE][i/CELL_SIZE]]);

  img.saveToFile("data/out.png");

  for(int i=0; i < 25; i++)
    std::cout<<mask[i/5][i%5]<<(i%5==4 ? '\n' : '\0');
  return 0;
}
