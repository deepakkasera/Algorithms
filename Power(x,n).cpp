#include <bits/stdc++.h>
using namespace std;
//Recursive approach, Complexity is O(logn)
long long power(int x,long long n){
	if(n == 0) return 1;
	if(n%2 == 0){
		return power(x*x,n/2);
	}
	else if(n%2 != 0){
		return x*power(x*x,(n-1)/2);
	}
}
//Iterative Approach
long long powerIterative(int x,long long n){
	long long result=1;
	while(n > 0){
		if(n%2 == 1) {
			result*=x;
		}
		n = n>>1;  //(n/=2)
		x*=x;
	}
	return result;
}
int main(int argc, char const *argv[])
{
	int x,n;
	cin >> x >> n;
	cout << power(x,n) << endl << powerIterative(x,n) ;
	return 0;
}