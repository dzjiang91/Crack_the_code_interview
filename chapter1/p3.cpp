//cracking the code interview 1.3
// Given two strings, write a method to decide if one is a permutation of the other

#include <iostream>
#include <string>
using namespace std;

bool compare(string &str1, string &str2);

int main(){
  string str1;
  string str2;
  cout << "input string1: " << endl;
  cin >> str1;
  cout << "input string2: " << endl;
  cin >> str2;
  if(compare(str1,str2))
    cout << "One is a permutation of the other!" << endl;
  else
    cout << "NOT QUALIFIED!" << endl;
  return 0;
}

bool compare(string &str1, string &str2){
  int result[256];
  memset(result, 0, 256 * sizeof(int));
  int size1 = str1.size();
  int size2 = str2.size();
  if(size1 != size2) return false;
  else{
    for(int i=0; i < size1; ++i){
      ++result[str1[i]];
      --result[str2[i]];
    }
  }
  for(int i=0; i < 256; ++i){
    if(result[i] != 0) return false;
  }
  return true;
}
