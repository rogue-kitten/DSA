#include<iostream>
#include<vector>
using namespace std;

void printFactors(int n){
	vector<pair<int, int>> ans;
	for(int i = 2; i*i <= n; i++){
		if(n%i == 0){
			int occ = 0;
			while(n%i == 0){
				occ++;
				n /= i;
			}
			ans.push_back(make_pair(i, occ));
		}
	}
	if(n != 1){
		ans.push_back(make_pair(n, 1));
	}

	for(auto p : ans){
		cout << p.first << " " << p.second << endl;
	}
}

int main(){
	int n;
	cin >> n;

	printFactors(n);
}
