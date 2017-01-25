#include <bits/stdc++.h>
using namespace std;
long catalan(int n){
	if(n<=1) return 1;
	long int result=0;
	for(int i=0;i<n;i++){
		result += catalan(i)*catalan(n-i-1);
	}
	return result;
}
int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	cout << catalan(n) << endl;
	return 0;
}