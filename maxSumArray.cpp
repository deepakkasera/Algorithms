#include <bits/stdc++.h>
using namespace std;
int ans=INT_MIN;
// Brute Force approach // Time complexity is O(n^3)
int max_sum_subArray1(int a[],int n){
	for(int sub_array_size = 1 ; sub_array_size <= n ; sub_array_size)
	{
		for(int start_index=0 ; start_index < n ; start_index++)
		{
			if(sub_array_size + start_index > n) break;   //subarray exceeds array bound
			int sum=0;
			for(int i=start_index ; i < (start_index + sub_array_size) ; i++ )
     			sum+=a[i];
			ans=max(ans,sum);
		}
	}
	return ans;
}
// Efficient approach Time complexity is O(n^2)
int max_sum_subArray2(int a[],int n){
	for(int start_index = 0 ; start_index < n ; start_index++){
		int sum=0;
		for(int sub_array_size = 1 ; sub_array_size <= n ; sub_array_size++){
			if(sub_array_size + start_index > n )  break;
			sum+=a[sub_array_size + start_index - 1];
			ans=max(sum,ans);
		}
	}
	return ans;
}
// More efficient approach Time complextiy is O(nLogn) 
int max_sum_subArray3(int a[],int n){
	if(n==1)
		return a[0];
	int m=n/2;
	int left_MSS=max_sum_subArray3(a,m);
	int right_MSS=max_sum_subArray3(a+m,n-m);
	int left_sum=INT_MIN;
	int right_sum=INT_MIN;
	int sum=0;
	for(int i=m-1 ; i>=0 ; i--){
		sum+=a[i];
		left_sum=max(sum,left_sum);
	}
	sum=0;
	for(int i=m ; i<n ; i++){
		sum+=a[i];
		right_sum=max(sum,right_sum);
	}
	ans=max(left_MSS,right_MSS);
	return max(ans,left_sum + right_sum);
}
// Most Efficient approach (KADANE'S ALGO) Time complexity is O(n)
int max_sum_subArray4(int a[],int n){
	int sum=0;
	for(int i=0;i<n;i++){
		ans=max(ans,a[i]);
	}
	if(ans<0)  return ans;
	ans=0;
	for(int i=0;i<n;i++){
		if(sum+a[i]>0)  sum+=a[i];
		else sum=0;
		ans=max(sum,ans);
	}
	return ans;
}
int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)   cin>>a[i];
	cout<<"O(n^2) approach ";
    cout<<max_sum_subArray2(a,n)<<"\n";
	cout<<"O(nlogn) approach ";
	cout<<max_sum_subArray3(a,n)<<"\n";
	cout<<"O(n) approach ";
	cout<<max_sum_subArray4(a,n);
	return 0;
}
