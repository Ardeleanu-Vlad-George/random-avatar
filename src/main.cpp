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
      mask[i][j]=rand()%2;

  //generate middle part
  for(int i=0; i < 5; i++)
    mask[i][2]=rand()%2;

  //mirror the first half over the other
  for(int i=0; i < 5; i++)
    for(int j=0; j < 2; j++)
      mask[i][4-j]=mask[i][j];

  //start saving into image
  sf::Color bg=sf::Color(50,100, 50), fg=sf::Color(100, 200, 0);
  sf::Image img;
  img.create(5*CELL_SIZE, 5*CELL_SIZE);

  for(int i=0; i < 5*CELL_SIZE; i++)
    for(int j=0; j < 5*CELL_SIZE; j++)
      img.setPixel(i, j, mask[j/CELL_SIZE][i/CELL_SIZE] ? fg : bg);

  img.saveToFile("data/out.png");

  for(int i=0; i < 25; i++)
    std::cout<<mask[i/5][i%5]<<(i%5==4 ? '\n' : '\0');
  return 0;
}
