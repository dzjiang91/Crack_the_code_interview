
#include<iostream>
using namespace std;

char* compressing(char *s, char *result);

int main(){
  char s[] = "aabcccccaaa";
  char r[] = "           ";
  cout << s << endl;
  //char *t = compressing(s,r);
  cout << compressing(s,r) << endl;
  return 0;
}

char* compressing(char* s, char* result){
  char* s1 = s;
  char* res = result;
  //memset(result,'*',100);
  int sum = 1;
  int si = 0; int ri = 0;
  *(result + 0) = *(s + 0);
  s++;
  while(*s != '\0'){
    si++;
    if(*(s - 1) == *s){
      ++sum;
    }
    else{
      ++result; ++ri;
      
      *result = '0' + sum;
      sum = 1;
      ++result; ++ri;
      *result = *s;
    }
    ++s;
    if(*s == '\0' && ri >=si) return s1;
    if(*s == '\0'){
      ++result;
      *result = '0' + sum;
      ++ri;
    }
    
  }
  ++result; *result = '\0';
  return res;
}
