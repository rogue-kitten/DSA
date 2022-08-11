// link to problem -> https://codeforces.com/problemset/problem/263/A

#include <bits/stdc++.h>

using namespace std;

int main(){
	int row = 0, col = 0, t;
	for(int i = 1; i <= 5; i++){
		for(int j = 1; j <= 5; j++){
			cin >> t;
			if(t == 1){
				row = i;
				col = j;
			}
		}
	}

	cout << abs(row - 3) + abs(col - 3) << endl;
}
