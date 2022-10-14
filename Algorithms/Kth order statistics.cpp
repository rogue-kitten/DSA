#include<bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>

using namespace std;
// using namespace __gnu_pbds;

#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define ll long long
#define ull unsigned long long
#define mod 9
#define vi vector<int>
#define vll vector<long long>
#define vs vector<string>
#define vb vector<bool>
#define vd vector<double>

#define vvi vector<vector<int>>
#define vvll vector<vector<long long>>
#define vvs vector<vector<string>>

#define umii unordered_map<int, int>
#define umivi unordered_map<int, vector<int>>

#define endl '\n'
#define printall(a) for(auto i : a) cout << i << " "
#define print(a) cout << a << endl
#define noo cout << "NO" << endl;
#define yess cout << "YES" << endl;

#define pii pair<int, int>
#define pll pair<ll, ll>
#define vpii vector<pii>
#define vpll vector<pll>
#define mp make_pair

#define pb push_back
#define maxHeap  priority_queue<int>
#define minHeap  priority_queue<ll, vector<ll>, greater<ll>>

#define fo(i, n) for(int i = 0; i < n; i++)
#define rfo(i, n) for(int i = n; i >= 0; i--)
#define foll(i, n) for(ll i = 0; i < n; i++)
#define rfoll(i, n) for(ll i = n; i >= 0; i--)
#define foa(i, a, b) for(int i = a; i < b; i++)

#define print_case(i, x) cout << "Case " << i << ": " << x << '\n';

// typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> pbds;

ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }

int partition(int arr[], int l, int r, int x)
{
	// Search for x in arr[l..r] and move it to end
	int i;
	for (i = l; i < r; i++)
		if (arr[i] == x)
			break;
	swap(arr[i], arr[r]);

	// Standard partition algorithm
	i = l;
	for (int j = l; j <= r - 1; j++)
	{
		if (arr[j] <= x)
		{
			swap(arr[i], arr[j]);
			i++;
		}
	}
	swap(arr[i], arr[r]);
	return i;
}

int findMedian(int arr[], int n)
{
	sort(arr, arr + n); // Sort the array
	return arr[n / 2]; // Return middle element
}

int kthSmallest(int arr[], int l, int r, int k)
{
	// If k is smaller than number of elements in array
	if (k > 0 && k <= r - l + 1)
	{
		int n = r - l + 1; // Number of elements in arr[l..r]

		// Divide arr[] in groups of size 5, calculate median
		// of every group and store it in median[] array.
		int i, median[(n + 4) / 5]; // There will be floor((n+4)/5) groups;
		for (i = 0; i < n / 5; i++)
			median[i] = findMedian(arr + l + i * 5, 5);
		if (i * 5 < n) //For last group with less than 5 elements
		{
			median[i] = findMedian(arr + l + i * 5, n % 5);
			i++;
		}

		// Find median of all medians using recursive call.
		// If median[] has only one element, then no need
		// of recursive call
		int medOfMed = (i == 1) ? median[i - 1] :
		               kthSmallest(median, 0, i - 1, i / 2);

		// Partition the array around a random element and
		// get position of pivot element in sorted array
		int pos = partition(arr, l, r, medOfMed);

		// If position is same as k
		if (pos - l == k - 1)
			return arr[pos];
		if (pos - l > k - 1) // If position is more, recur for left
			return kthSmallest(arr, l, pos - 1, k);

		// Else recur for right subarray
		return kthSmallest(arr, pos + 1, r, k - pos + l - 1);
	}

	// If k is more than number of elements in array
	return INT_MAX;
}

void solve() {
	int arr[] = {12, 3, 5, 7, 4, 19, 26};
	int n = sizeof(arr) / sizeof(arr[0]), k = 3;
	cout << "K'th smallest element is "
	     << kthSmallest(arr, 0, n - 1, k);
}

int main() {
	fastio();
	int t = 1;
	// cin >> t;
	while (t--) {
		solve();
	}
}