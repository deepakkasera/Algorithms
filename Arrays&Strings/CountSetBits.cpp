#include <bits/stdc++.h>
using namespace std;
int setBits(int n)
{
	int cnt=0;
	while(n){
		cnt += (n&1);
		n/=2;
	}
	return cnt;
}
int setBits2(int n){
	int cnt=0;
	while(n){
		n &= (n-1);
		cnt++;
	}
	return cnt;
}
int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	cout << setBits(n) << " " << setBits2(n) << endl;
	return 0;
}