//cracking the code interview 1.6
//Given an image represented by an N*N matrix, where each pixel in the image is 4 bytes, write a method to rotate the image by 90 degrees. Can you do this in place?

//memo: watch out the way to pass an array or multidimensional array to function(use pointer)
//can it pass by reference?

#include <iostream>
#include <iomanip>
using namespace std;

void rotate(int *m, int N);
void swap(int *m, int i, int j, int N);
void output(int *m, int N);
int main(){
  int N = 5;
  int m[N*N];
  for(int i = 0; i < N; ++i){
    for(int j=0; j < N; ++j){
      m[i*N+j] = N*i + j;
    }
  }
  output(m, N);
  rotate(m, N);
  cout << "rotate 90:" << endl;
  output(m, N);
  return 0;
}

void rotate(int *m, int N){
  for(int i = 0; i < (N + 1)/2; ++i){
    for(int j = 0; j <= N/2; ++j){
      swap(m, i, j, N);
    }
  } 
}

void swap(int *m, int i, int j, int N){
  int temp = m[i*N+j];
  m[i*N+j] = m[(N-1-j)*N+i];
  m[(N-1-j)*N+i] = m[(N-1-i)*N+N-1-j];
  m[(N-1-i)*N+N-1-j] = m[j*N+N-1-i];
  m[j*N+N-1-i] = temp;
}

void output(int *m, int N){
  cout << endl;
  for(int i = 0; i < N; ++i){
    for(int j=0; j < N; ++j){
      cout << setw(5) << m[i*N+j];
    }
    cout << endl;
  }
}
