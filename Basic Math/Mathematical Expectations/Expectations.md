# Mathematical Expectation

```
Expectation of a random variable => Avg value of the random variable. 
The random variable can be discrete or continuous: 
1. For discrete, E(X) = Sum(Xi*P(Xi)), where P(X) is the probability of X
2. For continuous, E(X) = integration(X*P(X)dx), 

in the case of a dice throw, 
X = {1,2,3,4,5,6}
E(X) = 1*(1/6) + 2*(1/6) + 3*(1/6) + 4*(1/6) + 5*(1/6) + 6*(1/6) = 3.5

In this case, the average value is not the most probable outcome (because 3.5 
	cannot come on the dice).
```

## Rule of Linearity of Expectations
```
E[aX + bY] = aE[X] + bE[Y]

the random events X and Y can be dependant or independant from each other, it 
would still be the same. 
```

## Problem 1
```
What are the expected number of trials to get a head?

Let the expected number of coin flips be x. Then we can write an equation for it -
a. If the first flip is the head, then we are done. The probability of this event
is 1/2 and the number of coin flips for this event is 1.

b. If the first flip is the tails, then we have wasted one flip. Since 
consecutive flips are independent events, the solution in this case can be 
recursively framed in terms of x - The probability of this event is 1/2 and the 
expected number of coins flips now onwards is x. But we have already wasted one 
flip, so the total number of flips is x+1.

The expected value x is the sum of the expected values of these two cases. Using 
the rule of linerairty of the expectation and the definition of Expected value, 
we get

x = (1/2)(1) + (1/2) (1+x)
Solving, we get x = 2.

Thus the expected number of coin flips for getting a head is 2.
```

## Problem 2
```
What are the expected no of trials to get 2 consequetive heads?

Let the expected number of coin flips be x. The case analysis goes as follows:
a. If the first flip is a tails, then we have wasted one flip. The probability of 
this event is 1/2 and the total number of flips required is x+1

b. If the first flip is a heads and second flip is a tails, then we have wasted
two flips. The probability of this event is 1/4 and the total number of flips 
required is x+2

c. If the first flip is a heads and second flip is also heads, then we are done. 
The probability of this event is 1/4 and the total number of flips required is 2.

Adding, the equation that we get is -
x = (1/2)(x+1) + (1/4)(x+2) + (1/4)2

Solving, we get x = 6.
Thus, the expected number of coin flips for getting two consecutive heads is 6.
```

## Problem 3 [generalisation]
```
What is the expected number of coin flips for getting N consecutive heads, given N?

Let the exepected number of coin flips be x. Based on previous exercises, we can wind up the whole case analysis in two basic parts

a) If we get 1st, 2nd, 3rd,...,n'th tail as the first tail in the experiment, then we have to start all over again.
b) Else we are done.

For the 1st flip as tail, the part of the equation is (1/2)(x+1)
For the 2nd flip as tail, the part of the equation is (1/4)(x+2)
...
For the k'th flip as tail, the part of the equation is (1/(2k))(x+k)
...
For the N'th flip as tail, the part of the equation is (1/(2N))(x+N)
The part of equation corrresponding to case (b) is (1/(2N))(N)

Adding,

x = (1/2)(x+1) + (1/4)(x+2) + ... + (1/(2^k))(x+k) + .. + (1/(2^N))(x+N) + (1/(2^N))(N)

The entire equation can be very easily reduced to the following form:

x = 2N+1-2

Thus, the expected number of coin flips for getting N consecutive heads is (2N+1 - 2).
```

## Problem 4
```
The queen of a honey bee nest produces offsprings one-after-other till she produces a male offspring. The probability of 
produing a male offspring is p. What is the expected number of offsprings required to be produced to produce a male offspring?

x = p + (1-p)*(x+1)
Solving, x = 1/p

Thus, observe that in the problems where there are two events, where one event is desirable and other is undesirable,
and the probability of desirable event is p, then the expected number of trials done to get the desirable event is 1/p

Generalizing on the number of events - If there are K events, where one event is desirable and all others are undesirable, 
and the probability of desirable event is p, then also the expected number of trials done to get the desirable event is 1/p.
```
