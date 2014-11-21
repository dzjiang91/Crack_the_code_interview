//cracking the code interview 1.2
//Implement a function void reverse(char* str) in C or C++ which reverses a null-terminated string

#include <iostream>
#
using namespace std;

void reverse (char *str);
int main(){
	char str[] = "abcdefg1234";
	cout << endl;
	cout << "origin: " << str << endl;
	reverse(str);
	cout << "reverse: " << str << endl;
	return 0;
}


void reverse (char *str){
	char *endp = str;
	int length = 0;
	char temp;
	while(*endp != '\0'){ 
		++endp;
		++length;
	}
	--endp;
	for(; length > 0; length -= 2){
		temp = *str;
		*str = *endp;
		*endp = temp;
		++str; --endp;
	}
	
}

