//Assume you have a method isSubstring which checks if one word is a substring of another. Given two strings, s1 and s2, write code to check if s2 is a rotation of s1 using only one call to is Substring(e.g.,"waterbottle" is a rotation of "erbottlewat").

#include<iostream>

using namespace std;


bool Substring(string &s1, string &s2);

int main(){
  string s1 = "waterbottle";
  string s2 = "erbottlewat";
  if(Substring(s1, s2)){
    cout << "s1 and s2 are substring of one another" << endl;
  }
  else{
    cout <<"NOT substring" << endl;
  }
  return 0;
}

bool Substring(string &s1, string &s2){
  bool result = 0;
  //first check if they are permutation of one another
  int num = 0;
  int hashTable[256];
  memset(hashTable, 0, 256 * sizeof(int));
  while(1){
    if(s1[num] == '\0' && s2[num] == '\0'){
      break;
    }
    if(s1[num] == '\0' || s2[num] == '\0'){
      return 0;
    }
    hashTable[s1[num]] += 1;
    hashTable[s2[num]] -= 1;
    ++num;
  }
  //now num is the length of the strings
  for(int i = 0; i < 256; ++i){
    if(hashTable[i]){
      cout <<"NOT Permutation" << endl;
      return 0;
    }
  }
  //check if they are rotation of each other
  int tempIndex = 0;
  for(int i = 0; i < num; ++i){
    for(int j = 0; j < num; ++j){
      tempIndex = i + j;
      if(tempIndex >= num){
        tempIndex = i + j - num;
      }
      if(s1[tempIndex] != s2[j]) break;
      if(j == num - 1) return 1; 
    }
  }
  
  return result;
  
}

