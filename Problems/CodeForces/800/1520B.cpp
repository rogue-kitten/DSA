// link to problem ->https://codeforces.com/problemset/problem/1520/B

#include<iostream>
#include<math.h>
 
using namespace std;
 
int main(){
      int t;
      cin >> t;
      while(t--){
            int n;
            cin >> n;
            int ans = 0;
            for(int d = 1; d <= 9; d++){
                  int num = 0;
                  for(int k = 0; k <= 8; k++){
                        num += d*pow(10, k);
                        if(num <= n) ans++;
                        else break;
                  }
            }
            cout << ans << endl;
      }
}
