// link to problem -> https://codeforces.com/problemset/problem/1097/B

#include<iostream>

using namespace std;

typedef long long int ll;
typedef unsigned long long int  ull;


int main(){
	int n, m;
	cin >> n;
	int a[20];
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}

	m=1<<n;
    for(int i=0;i<m;i++)
    {
        int sum=0;
        for(int j=0;j<n;j++)
        {
            if((1<<j)&i) sum+=a[j];
            else sum-=a[j];
        }

        if(sum%360==0)
        {
            cout << "YES" << endl;
            return 0;
        }
    }

    cout << "NO" << endl;

    return 0;

}
