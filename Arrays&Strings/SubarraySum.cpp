#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	int n,x;
	cin >> n >> x;
	int a[n];
	for(int i=0;i<n;i++)
		cin >> a[i];
	int left = 0,right = 0,sum = a[left];
	while(left <= right)
	{
		if(sum == x){
			cout << left << " " << right;
			return 0; 
		}
		if(sum + a[right + 1] <= x){
			right++;
			sum += a[right];
		}else{
			sum -= a[left];
			left++;
		}
	}
	cout << "Not found\n";
	return 0;
}