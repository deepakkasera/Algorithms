#include <bits/stdc++.h>
using namespace std;
void betterMethod(std::vector<int> &v,int n){
	int maximum = v[n-1];
	v[n-1] = -1;
	for (int i = n-2; i >=0 ; --i)
	{
		int temp = v[i];
		v[i] = maximum;
		maximum = max(temp,maximum);
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
	betterMethod(v,n);
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