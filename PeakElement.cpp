#include <bits/stdc++.h>
using namespace std;
// if ( (mid == 0 || array[mid - 1] <= array[mid]) && (mid == n - 1 || array[mid] >= array[mid + 1]))
bool isPeak(int a[],int n,int middle){
	if(middle == 0 && a[middle]>=a[middle+1]){
		// cout<<"1\n";
		return true;
	}
	if (middle == n-1 && a[middle] >= a[middle-1]){
		// cout<<"2\n";
		return true;
	}
	if(a[middle] >= a[middle-1] && a[middle]>=a[middle+1]){
		// cout<<"3\n";
		return true;
	} 
	return false;
}
int peakElement(int a[],int n){
	int s = 0, e = n-1;
	while(s <= e){
		int middle = (s+e)/2;

		if(isPeak(a,n,middle)){
			return middle;
		}
		else if (a[middle-1] >= a[middle]){
			e = middle-1;
		}
		else 
			s = middle+1;
	}
	return -1;
}
int main(){
	int n;
	cin >> n;
	int a[n];
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	peakElement(a,n) == -1 ? cout << "No peakElement\n" : cout << a[peakElement(a,n)] <<endl; 
	// cout << "Peak Element is " <<  << endl;
}