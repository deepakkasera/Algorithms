#include<bits/stdc++.h>
using namespace std;
int main(){
    int t,n;
    cin >> t;
    while(t--){
        int count=0;
        cin >> n;
        vector<int> v(n);
        for(int i=0;i<n;i++){
            cin >> v[i];
        }
        sort(v.begin(),v.end());
        int j,k;
        for(int i=0;i<n-2;i++){
            j=i+1;
            k=j+1;
            for(j;j<n-1;j++){
                while(k<n && v[i]+v[j]>v[k]) k++;
                count += (k-j-1);
            }
        }
        cout << count << endl;
    }
    return 0;
}