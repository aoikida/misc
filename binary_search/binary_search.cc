#include <stdio.h>

int binary_search(int data[], int min, int max, int key){

  while (1){
    int mid = min + (max - min) / 2; //avoid max+min exceeding maximum value of int
    if (data[mid] == key)
      return mid;
    else if (min == max)
      printf("Not Found %d\n", key);
    else if (data[mid] > key)
      max = mid - 1;
    else if (data[mid] < key)
      min = mid + 1;
    }

}


int main(void){

  int array[100];
  int size = sizeof(array) / sizeof(int);

  for (int i = 0; i< size; ++i){
    array[i] = i + 1;
  }

  int min = 0, max = size - 1;

  for (int i = 0; i<size; ++i){
    int num = array[i];
    printf("%d\n", binary_search(array, min, max, num)+1);
  }

  return 0;

}