
- You are given an array, you need to find the element at index k in the sorted array (k<sup>th</th> order statistics)
	- Obvious Solution: sort the array and then pick the element (nlogn TC).
	- We can do this in a faster way using a randomised process that is similar to the above quick sort method. 
- Approach:
	- We take a randomised index, and swap all the elements less than the element present at the randomised index to the front of the array, and the rest to the back. 
	- Now, we check the if the k < m, we only do the recursive call to the front part, if not, we do a recursive call to the last part. By doing this process, finally we will be left with a single element for which would contain the value of a[k] in the sorted order. 
	```cpp
	order_statistics(int l, int r, int k){ //we are finding the k'th smallest element from l to r - 1.
	if(r - l <= 1) return a[l]; // return if the size pf the array is less than 1.
	x = a[random_number between l to r-1];
	int m = l;
	for(int i = l; i < r; i++){
		if(a[i] < x){
			swap(a[i], a[m]);
			m++;
		}
	}
	// now from l - m -1 we have elements lesser than x, and from m to r-1 greater than x.
	if(m < k) order_statistics(l,m,k);
	else order_statistics(m,r,k);
```
- Key difference between this and quick sort if that for every function, we only have one fucntion call instead of 2
- On calculating, we find that the total time complexity would be linear. it is actually much harder to prove that this runs in linear time, but it does so take the word.
- This algo is also called as the quick select algo. and is a probabilistic algorithm.
- There also exists a deterministic version of this algorithm.

### Deterministic Kth order statistics:
- Why did we need randomisation: because we want to pick some good element. 
- In the deterministic method, we find a sure shot way to pick the good element (probability = 1)
- This algo is called as *Blume-Flyod-Pratt-Rivest-Trojan Algorithm* 
- So how do we pick a good element from the array?
	- We split the array into groups of 5 elements. 
	- Inside the block, we can find the median element. 
	- So then we can take these median elments and find the median of all the medians. 
	- This median of median value is our X.
- [For more information](https://en.wikipedia.org/wiki/Median_of_medians)

```cpp
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
```

