//Write an algorithm such that if an element in an M*N matrix is 0, its entire row and column are set to 0
//hash
// union find
#include <iostream>
#include <memory.h>
#include <iomanip>
using namespace std;

void setZero(int** m, int M, int N);
void outMatrix(int** m, int M, int N);


int main(){
  int M = 5;
  int N = 6;
  int** m = new int*[M];
  for(int i = 0; i < M; ++i){
    *(m + i) = new int[N];
    for(int j = 0; j < N; ++j){
      m[i][j] = i - j +2; 
    }
  }
  outMatrix(m, M, N);
  setZero(m, M, N);
  outMatrix(m, M, N);
  //delete
  for(int i = 0; i < M; ++i){
    delete[] *(m + i);
  }
  delete[] m;
  return 0;
}

void setZero(int** m, int M, int N){
  bool rowCol[M + N];
  memset(rowCol, 0, M+N);
  //get the row and col that need to set 0
  for(int i = 0; i < M; ++i){
    for(int j = 0; j < N; ++j){
      if(*(*(m + i) + j) == 0){
        rowCol[M + j] = 1;
        rowCol[i] = 1; 
      }
    }
  }
  //set 0
  for(int i = 0; i < M; ++i){
    for(int j = 0; j < N; ++j){
      if(rowCol[M + j] || rowCol[i]){
        *(*(m + i) + j) = 0;
      }
    }
  }

}

void outMatrix(int** m, int M, int N){
  for(int i = 0; i < M; ++i){
    for(int j = 0; j < N; ++j){
      cout << setw(5) << m[i][j]; 
    }
    cout << endl;
  }
}


