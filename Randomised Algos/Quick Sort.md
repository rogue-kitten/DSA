
- Sometimes it is possible that by having some random input numbers helps in solving the problem faster. 
- Sometime is it possible to get bettter asymptotics when we use a randomised algorithm instead of a linear algorithm.
- Example: Quick Sort: 

## Quick Sort:
- In quick sort, we basically pick up an element of the array at random, and then we move all the elements which are smaller than the current one to the left and the remaining elements to the right hand side. Then, we repeat this process for both the new smaller arrays until we get an array of size 1. 
```cpp
quick_sort(int l, int r){ //we are sorting from l to r - 1.
	if(r - l <= 1) return // return if the size pf the array is less than 1.
	x = a[random_number between l to r-1];
	int m = l;
	for(int i = l; i < r; i++){
		if(a[i] < x){
			swap(a[i], a[m]);
			m++;
		}
	}
	// now from l - m -1 we have elements lesser than x, and from m to r-1 greater than x.
	quick_sort(l, m);
	quick_sort(m, r);
}
```
- Although this is a fairly good implementation of quick sort, the above program won't work when you have all the elements of the array same (full get stuck in an infinite loop).
- Or even a case might come up where x is the smallest element of the section: here there is no element which is smaller than x, so we just keep on repeating the same operation.
- To solve this issue, we can split the array into 3 parts, less than, equal to and greater than x, and then we can call the recursive functions on the left and the right part of the array.

## Time Complexity of Quick Sort
- We find the worst possible case for the algo: the case when the random element picked up for all the smaller arrays is the smallest one: the Tc for this would be O(n<sup>2</sup>). 
- but since this is a randomised algo, we will use a slightly different technique to calculate: which is the mean of all the operations possible. 
- This actually comes down to O(nlogn) (google to get the proof)
- In practise, Quick Sort is better than heap sort or merge sort because we can tweek the random functions to pick only those functions which give us a good split. (basically we would like to pick a middle element as compared to an edge one)
	- So what we can do it that instead of just picking one element at random, we pick 3 elements and choose the middle one to perform our operations on. So we will have a slightly better performance.

