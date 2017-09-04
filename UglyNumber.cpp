#include <bits/stdc++.h>
using namespace std;
int maxDivide(int a , int b){
	while(a%b==0){
		a = a/b;
	}
	return a;
}
bool isUgly(int i) {
	int x = i;
	x = maxDivide(x,2);
	x = maxDivide(x,3);
	x = maxDivide(x,5);

	if(x==1){
		return true;
	}
	return false;
}
int fun(int n){
	int ugly = 1;
	int cnt = 1;

	while(cnt < n){
		ugly++;
		if(isUgly(ugly)){
			cnt++;
		}
	}
	return ugly;
}
int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	cout << fun(n) << endl;
	return 0;
}