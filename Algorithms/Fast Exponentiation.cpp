ll mod = 1e9 + 7;

ll solve(ll a, ll n){
	if(a == 0)
		return 0;
	if(n == 0)
		return 1;
	if(n == 1)
		return a;

	ll x = solve(a, n/2);
	if(n&1)
		return a*x*x;

	else
		return x*x;
}

