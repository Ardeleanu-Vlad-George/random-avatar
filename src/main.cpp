#include <iostream>
#include <cstdlib>

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

  for(int i=0; i < 25; i++)
    std::cout<<mask[i/5][i%5]<<(i%5==4 ? '\n' : '\0');
  return 0;
}
