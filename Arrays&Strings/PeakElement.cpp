#include <bits/stdc++.h>
using namespace std;
//Time Complexity is O(n)
int peakElement(std::vector<int> &v,int n){
	int res = v[0];
	for(int i=1;i<n;i++){
		if(v[i]>=v[i-1] && v[i]>=v[i+1]) res=v[i]; 
	}
	return res;
}
//Time Complexity O(logn)
int peakElement2(std::vector<int> &v,int n){
	int left=0;
	int right = n-1;
	int middle;
	while(left <= right){
		middle = (left+right)/2;
		if(v[middle] >= v[middle+1] && v[middle] >= v[middle-1])
			return v[middle];
		else if (v[middle]<v[middle+1])
			left = middle+1;
		else if (v[middle] < v[middle-1]) 
			right = middle-1;
	}
	//return -1;
}
int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	std::vector<int> v(n);
	for(int i=0;i<n;i++) cin >> v[i];
	cout << peakElement(v,n) << endl;
    cout << peakElement2(v,n) << endl;
	return 0;
}