#include <bits/stdc++.h>

using namespace std;

int main(){
	// string tokenizer -> works only on character arrays
	// declaration char * strtok ( char * str, const char * delimiters ) -> returns a character pointer. 
	// this function basically breaks the string about the 
	// deliminator into different tokens. 

	char s[100] = "today is a rainy day i like it";

	char * ch = strtok(s, " ");

	cout << ch << endl; // o/p -> today

	// to get all the other tokens which have been broken around this
	// deliminator, we call the function again, but this time we
	// pass the string argument as null;
	ch = strtok(NULL, " ");
	cout << ch << endl; // o/p -> is

	ch = strtok(NULL, " ");
	cout << ch << endl;

	// after all the tokens are printed, if we get another call, 
	// the fucntion returns a NULL value, hence we can loop it to get all the tokens

	char *ptr = strtok(s, " ");
	cout << ptr << endl;
	
	while(ptr != NULL){
		ptr = strtok(NULL, " ");
		cout << ptr << endl;
	}
  
  
}
