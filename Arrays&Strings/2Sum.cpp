#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	int n,x;
	cin >> n >> x;
	int a[n];
	for(int i=0;i<n;i++)
		cin >> a[i];
	sort(a,a+n);
	int left = 0,right = n-1;
	int sum = a[left] + a[right];
	while(left < right){
		if(sum == x){
			cout << left << " " << right << endl;
			return 0;
		}
		if(sum < x){
			sum -= a[left];
			left++;
			sum += a[left];
		}else{
			sum -= a[right];
			right--;
			sum += a[right];
		}
	}
	cout << "Not found\n";
	return 0;
}