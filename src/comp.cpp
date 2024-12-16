#include "comp.hpp"
#include <cstdlib>
#include <ctime>

int** create(int size){
  int** result = new int*[size];
  *result = new int[size*size];
  for(int iter=0; iter < size; iter++)
    result[iter] = *result + iter*size;  
  return result;
}

void assign(int size, int limt, int **data){
  for(int iter=0; iter < size*size; iter++)
    iter[*data] = 0;

  srand(time(NULL));

  for(int iter_l=0; iter_l < size; iter_l++)
    for(int iter_c=0; iter_c < size/2; iter_c++)
      data[iter_l][iter_c] = rand() % limt;

  for(int iter_l=0; iter_l < size; iter_l++)
    data[iter_l][size/2] = rand() % limt;

  for(int iter_l=0; iter_l < size; iter_l++)
    for(int iter_c=0; iter_c < size/2; iter_c++)
      data[iter_l][size-1-iter_c] = data[iter_l][iter_c];
}
