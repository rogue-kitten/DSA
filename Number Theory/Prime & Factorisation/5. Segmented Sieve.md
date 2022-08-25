# Segmented Sieve

```
The problem with a the normal sieve method is that we can only make an array of the size 10^8 at max.

Segemented Sieve helps in finding the primes between a and b, such that the 
difference between a and b is less than 10^5, while a and b are less than 10^9 
individually. 

Clearly, due to the constraints, we see that the normal sieve method will fail
for such large numbers. 

```
Problem statement: SPOJ Prime1

## Approach
```
1. We will store all the primes uptill sqrt(n). max value of n can be 10^9, so
   we find all the primes till 10^5. 
2. We then create an array of size (n-m + 1)[index 0 to index n - m], such that
   index zero will get mapped to m, n - m to n. Thus, any ith index will be 
   mapped to i + m. 
3. Later we mark all the even values in the range of m, n to be not prime and
   then we run a loop from 0 to sqrt(n) and use the normal sieve method to 
   cut out all the multiples lying in this range. 
4. How do we get the multiples of prime number p in the range of m, n?
   compute the value of (m/p)*p. if this lies in the range, then start from this, 
   else take the next immediate one. (m/p)*p + p.
```
