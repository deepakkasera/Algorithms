#include <bits/stdc++.h>
using namespace std;
// O(logn)
float squareRoot(int n,int p){
	int left=0,right=n/2,middle;
	float value;
	while(left <= right){
		middle = (left+right)/2;
		value = middle;
		if(middle*middle == n){
			// value = middle;
			break;
		}
		else if(middle*middle > n){
			right = middle - 1;
		}
		else{
			left = middle + 1;
		}
	}
	cout << value << endl;	
	float inc = 0.1;
	for(int i = 1; i <= p; i++){
		while(value * value <= n){
			value += inc;
		}
		value -= inc;
		inc /= 10;
	}
	return value;
}
int main(int argc, char const *argv[])
{
	int n,p;
	cin >> n >> p;
	cout << squareRoot(n,p) << endl;
	return 0;
}