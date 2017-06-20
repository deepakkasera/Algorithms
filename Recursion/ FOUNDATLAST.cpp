#include <bits/stdc++.h>
using namespace std;
int x = -1;
int returnIndex(int a[],int i,int n,int m){
    if(n==0){
        return x;
    }
    if(a[i] == m){
        x = i;
        return returnIndex(a,i+1,n-1,m);
    }
    else{
        return returnIndex(a,i+1,n-1,m);
    }
}
int main(){
    int n,m;
    cin >> n;
    int a[n];
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    cin >> m;
    cout << returnIndex(a,0,n,m) << endl;
    return 0;
}