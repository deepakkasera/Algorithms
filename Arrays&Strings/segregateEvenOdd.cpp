#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	//code
	int t;
	cin >> t;
	while(t--){
	    int n;
	    cin >> n;
	    int a[n];
	    for(int i = 0; i < n; i++){
	        cin >> a[i];
	    }
	    int l = 0;
	    int r = n-1;
	    while(l < r){
	        while(a[l]%2 == 0 && l<r){
	            l++;
	        } 
	        while(a[r]%2 == 1 && l<r){
	            r--;
	        }
	        if(l < r){
	            swap(a[l] , a[r]);
	            l++;
	            r--;
	        }
	    }
	    sort(a,a+l);
	    sort(a+l,a+n);
	    for(int i = 0; i < n; i++){
	        cout<<a[i]<<" ";
	    }
	    cout<<endl;
	}
	return 0;
}