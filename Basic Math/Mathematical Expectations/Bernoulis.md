# Bernouli's Trial

```
An experiement is called as a bernouli trial if it has exactly 2 outcomes, out of
which one of them is desirable for us.
```
## Theorem 1
```
If the probability of success of a bernouli trial is P, then the expected number of trials to get success is 1/p
```

## Theorem 2
```
If the probability of getting successs in a bernouli trial is P, then the probability of getting success in n trials is np.
```

## Coupon Collector Problem
```
Uncle chips always distributes a coupon in a packet of chips. The coupon in each 
packet is selected from a set of n distinct coupons. What is the expected no of 
packets one must buy in order to get all the n distinct coupons. 

Let E(Xi) be the expected no of packets we need to get the i'th new coupon (assuming that we already have i-1 distinct coupons).

P(Xi) = (n - (i-1))/n (we have i-1 coupons already with us)
E(Xi) = n/(n - (i-1)). 

Thus E(X) = E(x1 + x2 + x3+ .. xn) = E(x1) + E(x2) +...+ E(xn)
E(X) = n(1 + 1/2 + 1/3 + .. + 1/n)
```
