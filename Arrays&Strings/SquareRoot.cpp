#include <bits/stdc++.h>
using namespace std;
int squareRoot(int n){
	int left=0,right=n/2,middle;
	while(left <= right){
		middle = (left+right)/2;
		if(middle*middle == n){
			return middle;
		}
		else if(middle*middle > n){
			right = middle - 1;
		}
		else{
			left = middle + 1;
		}
	}
	return middle;
}
int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	cout << squareRoot(n) << endl;
	return 0;
}