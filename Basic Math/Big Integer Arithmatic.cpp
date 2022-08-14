// link to problem -> https://www.spoj.com/submit/JULKA/

#include<bits/stdc++.h>
using namespace std;

string longDivision(string number, int divisor)
{
    // As result can be very large store it in string
    string ans;
 
    // Find prefix of number that is larger
    // than divisor.
    int idx = 0;
    int temp = number[idx] - '0';
    while (temp < divisor)
        temp = temp * 10 + (number[++idx] - '0');
 
    // Repeatedly divide divisor with temp. After
    // every division, update temp to include one
    // more digit.
    while (number.size() > idx) {
        // Store result in answer i.e. temp / divisor
        ans += (temp / divisor) + '0';
 
        // Take next digit of number
        temp = (temp % divisor) * 10 + number[++idx] - '0';
    }
 
    // If divisor is greater than number
    if (ans.length() == 0)
        return "0";
 
    // else return ans
    return ans;
}

string addLarge(string a, string b){
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	string result;
	int i = 0, j = 0, carry = 0;
	while(i < a.length() && j < b.length()){
		int temp = (a[i++] - '0') + (b[j++] - '0') + carry;
		result.push_back((temp%10) + '0');
		carry = temp / 10;
	}
	while(i < a.length()){
		int temp = (a[i++] - '0') + carry;
		result.push_back((temp%10) + '0');
		carry = temp / 10;
	}
	while(j < b.length()){
		int temp = (b[j++] - '0') + carry;
		result.push_back((temp%10) + '0');
		carry = temp / 10;
	}
	while(carry > 0){
		int temp = carry%10;
		result.push_back(temp + '0');
		carry /= 10;
	}
	reverse(result.begin(), result.end());
	return result;
}

string subLarge(string str1, string str2) 
{ 
    // Take an empty string for storing result 
    string str = ""; 
  
    // Calculate length of both string 
    int n1 = str1.length(), n2 = str2.length(); 
  
    // Reverse both of strings 
    reverse(str1.begin(), str1.end()); 
    reverse(str2.begin(), str2.end()); 
      
    int carry = 0; 
  
    // Run loop till small string length 
    // and subtract digit of str1 to str2 
    for (int i=0; i<n2; i++) 
    { 
        // Do school mathematics, compute difference of 
        // current digits 
          
        int sub = ((str1[i]-'0')-(str2[i]-'0')-carry); 
          
        // If subtraction is less then zero 
        // we add then we add 10 into sub and 
        // take carry as 1 for calculating next step 
        if (sub < 0) 
        { 
            sub = sub + 10; 
            carry = 1; 
        } 
        else
            carry = 0; 
  
        str.push_back(sub + '0'); 
    } 
  
    // subtract remaining digits of larger number 
    for (int i=n2; i<n1; i++) 
    { 
        int sub = ((str1[i]-'0') - carry); 
          
        // if the sub value is -ve, then make it positive 
        if (sub < 0) 
        { 
            sub = sub + 10; 
            carry = 1; 
        } 
        else
            carry = 0; 
              
        str.push_back(sub + '0'); 
    } 
  
    // reverse resultant string 
    reverse(str.begin(), str.end()); 
  
    return str; 
} 

int main(){
	int t = 10;
	while(t--){
		string n,k;
		getline(cin, n);
		getline(cin, k);

		string temp = subLarge(n, k);
		string ans1 = longDivision(temp, 2);
		string ans2 = addLarge(ans1, k);
		cout << ans2 << endl << ans1 << endl;

	}
}
