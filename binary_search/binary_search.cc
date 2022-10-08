#include <iostream>
#include <vector>
using namespace std;

int binary_search(vector<int> data, int min, int max, int key){

  while (max >= min){
    int mid = min + (max - min) / 2; //avoid max+min exceeding maximum value of int
    if (data[mid] == key)
      return mid;
    else if (data[mid] > key)
      max = mid - 1;
    else if (data[mid] < key)
      min = mid + 1;
    }

}


int main(void){

  vector<int> A(100);

  for (int i = 0; i< A.size(); ++i){
    A[i] = i + 1;
  }

  int min = 0, max = (int)A.size() - 1;

  for (int i = 0; i<A.size(); ++i){
    int num = A[i];
    printf("%d\n", binary_search(A, min, max, num)+1);
  }

  return 0;

}