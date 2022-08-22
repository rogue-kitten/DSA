# Pigeonhole Principle (Dirichlet box principle)

```
P+1 Pigeons and P holes, then there will be atleast 1 hole which will have 2 or 
more pigeons. 

This principle is very easy to inderstand, but it is used to solve some very hard 
level problems as well. You can look at PHP a sort of mapping from the pigeons to 
holes. 

Another definition could be phrased as among any $n$ integers, there are two with
the same modulo n-1 residue (a%n-1 == b%n-1).

The extended version of the Pigeonhole Principle states that if k objects are
placed in n boxes then at least one box must hold at least [k/n] objects. Here [.] denotes the ceiling function.
```

## Sample Problem 1
```
Given a array of M integers and an integer N (N < M), prove that there always exists a pair such that their 
difference is divisible by N, that is
(a-b)%N == 0. 

For any interger a,
a%N = {0, 1, 2, 3, ..., N-1} (residue class)

here M = no of pigeons, 
	 elements of the residue class = no of holes (N) 

Since M > N, and if we consider M = N + 1, then by PHP, 2 of the integers will have the same value of modulo N.  
```

## Sample Problem 2
```
In a computer science department, a student club can be formed with either 10 
members from first year or 8 members from second year or 6 from third year or 4 
from final year. What is the minimum no. of students we have to choose randomly 
from department to ensure that a student club is formed?

In the worst case, we take 9 from first year, 7 from second year, 5 from third 
year and 3 from fourth year. Thus after this we pick any one student randomly 
from any year, the computer club will be formed. Thus ans = 9 + 7 + 5 + 3 + 1 = 25


A general theorem can be established from this example, which says that: (long form of the Pigeon Hole Principle)

Let q1, q2, . . . , qn be positive integers.

If q1+ q2+ . . . + qn – n + 1 objects are put into n boxes, then either the 1st 
box contains at least q1 objects, or the 2nd box contains at least q2 objects, . 
. ., the nth box contains at least qn objects.
```

## Sample Problem 3
```
A box contains 6 red, 8 green, 10 blue, 12 yellow and 15 white balls. What is the 
minimum no. of balls we have to choose randomly from the box to ensure that we 
get 9 balls of same color?

Since the number of red and green balls are less than 9, we will directly take 
them in the ans. Since the number of blue, yellow and white balls are more than 
9, we will take 8 from each of them. Thus after this, any ball we pick will 
complete the set of having 9 balls of the same color. 
Ans = 6 + 8 + 8 + 8 + 8 + 1 = 39
```
