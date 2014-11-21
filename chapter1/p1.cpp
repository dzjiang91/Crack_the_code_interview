//cracking the code 1.1
//Implement an algorithm to determine if a string has all unique characters. What if you cannot use additional data structures;

#include <memory.h>
#include <string>
#include <iostream>
using namespace std;

bool gosearch(string &s);
//bool check(bool* a);


int main(){
	string s;
	cin >> s;
	if( gosearch(s) )
		cout << "All chars is unique!" << endl; 
	else
		cout << "Duplicate!" << endl;
	return 0;
}

bool gosearch(string &s){
	int a = s.size();
	bool result[256];
	memset(result, false, 256);
	if(a > 256) return false;
	else{
		for( int i = 0; i < a ; ++i){
			if( result[s[i]] ){
				return false;
			}
			else{
				result[s[i]] = true;
			}
		}
	}
	return true;
}

