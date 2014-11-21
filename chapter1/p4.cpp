//cracking the code interview 1.4
// Write a method to replace all spaces in a string with '%20'. You may assume that the string has sufficient space at the end of the string to hold the additional characters, and that you are given the "true" length of the string.
// Example:
// input: "Mr John Smith     ", 13
// output: "Mr%20John%20Smith"

#include <iostream>
#include <memory.h>
#include <string>
using namespace std;
//replace space with '%20'
void replacespace(string &str, int &num);
//return the number of space in the string
int lookforspace(string &str,int &num);

int main(){
  string str = "Mr John Smith    ";
  int num = 13;
  cout << str << endl;
  replacespace(str, num);
  cout << str << endl;
  return 0;
}

void replacespace(string &str, int &num){
  int spacenum = lookforspace(str, num);
  int first = num - 1;
  int last = first + spacenum*2;
  char temp;
  // iterate by two index 'first' and 'last'
  while(first < last){
    if(str[first] != ' '){
      temp = str[last];
      str[last] = str[first];
      str[first] = temp;
    }
    else{
      str[last--] = '0'; str[last--] = '2'; str[last] = '%';
    }
    --first; --last;
  }
}
int lookforspace(string &str, int &num){
  int result=0;
  for(int i=0; i < num; ++i){
    if(str[i] == ' ') ++result;
  }
  return result;
}
