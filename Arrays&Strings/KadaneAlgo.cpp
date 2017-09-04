#include <bits/stdc++.h>
using namespace std;
int maxSum(int *a,int n){
    int cs = a[0];
    int ms = a[0];
    for(int i = 1; i < n; i++){
        cs = max(a[i],cs+a[i]);
        ms = max(ms,cs);
    }
    return ms;
}
int main() {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    int a[n];
	    for(int i = 0; i < n; i++){
	        cin>>a[i];
	    }
	    cout<<maxSum(a,n)<<endl;
	}
	return 0;
}	