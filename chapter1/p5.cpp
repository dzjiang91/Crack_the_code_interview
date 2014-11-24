//cracking the code interview 1.5
// Implement a method to perform basic string compression using the counts of repeated characters. For example, the string aabcccccaaa would become a2b1c5a3. If the "compressed" string would not become smaller than the original string, your method should return the original string. You can assume the string has only upper and lower case letters(a - z).

//I should not implement <string>, and I have to use char* instead
#include <iostream>
#include <string>
#include <math.h>
using namespace std;

string compressing(string &s);
int insertsum(string &s, int sindex, int sum);

int main(){
  string s;
  cin >> s;
  cout << s << endl;
  s = compressing(s);
  cout << s << endl;
  return 0;
}

string compressing(string &s){
  int num = s.size();
  string result = s;
  int sum = 1;
  int rindex = 0;
  result[rindex] = s[0];
  int temp;
  for(int i = 1; i < num; ++i){
    
    if(s[i] == s[i-1]){
      ++sum;
    }
    else{
      ++rindex;
      result[rindex++] = '0'+sum;
      
      //temp = insertsum(result, rindex, sum);
      //rindex = rindex + temp + 1;
      result[rindex] = s[i];
      if(rindex >= num - 1) return s;
      sum = 1;
    }
    if(i == num - 1) result[++rindex] = '0' + sum;
  }
  result[++rindex] = '\0';
  return result;
}

int insertsum(string &s, int sindex, int sum){ 
  //++sindex;
  int digit = 0;
  int sum1 = sum;
  while(sum1){
    ++digit;
    sum1 /= 10;
  }
  for(int i = digit - 1; i >= 0; --i){
    s[sindex++] = '0'+(sum / 10^i) % 10;        
  }
  return digit;
}

