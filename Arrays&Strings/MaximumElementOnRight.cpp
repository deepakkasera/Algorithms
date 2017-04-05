#include <bits/stdc++.h>
using namespace std;
void betterMethod(std::vector<int> &v,int n){
	int temp = v[n-1];
	v[n-1] = -1;
	for (int i = n-2; i >=0 ; --i)
	{
		//int temp = v[i];
		//v[i] = maximum;
		//maximum = max(temp,maximum);
		temp = max(temp,v[i+1]);
		v[i] = temp ;
	}
	for (int i = 0; i < n; ++i)
	{
		cout << v[i] << " ";
	}
}
int main(int argc, char const *argv[])
{
	int n ;
	cin >> n ;
	std::vector<int> v(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> v[i];
	}
	//O(n*n) solution
	// for(int i=0;i<n-1;i++){
	// 	int x = v[i+1] ;
	// 	for(int j=i+1;j<n;j++){
	// 		x = max(x,v[j]);
	// 	}
	// 	v[i] = x;
	// }
	// v[n-1] = -1;
	// cout << endl ;
	//betterMethod(v,n);
	int x = v[n-1];
	v[n-1] = -1;
	for(int i=n-2;i>=0;i--){
		int temp = v[i];
		v[i] = x ;
		x = max(temp,x);
	}
	for (int i = 0; i < n; ++i)
	{
		cout << v[i] << " ";
	}
	// for (int i = 0; i < n-1; ++i)
	// {
	// 	v[i] = *max_element(v.begin() + i + 1 , v.end());
	// }
	// v[n-1] = -1 ;
	// for (int i = 0; i < n; ++i)
	// {
	// 	cout << v[i] << " " ;
	// }
	return 0;
}