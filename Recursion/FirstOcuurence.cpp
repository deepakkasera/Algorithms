#include <bits/stdc++.h>
using namespace std;
int firstOccurence(int a[],int s,int e,int x){
	int ans=-1;
	while(s <= e){
		int middle = (s+e)/2;

		if(a[middle] == x){
			ans = middle;
			e = middle-1;
		}
		else if(a[middle] < x){
			s = middle+1; 
		}
		else{
			e = middle-1;
		}
	}
	return ans;
}
int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	int a[n];
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	int x;
	cout<<"Enter element\n";
	cin>>x;
	cout << "First Occurence " << firstOccurence(a,0,n-1,x) << endl; 
	return 0;
}