#include<bits/stdc++.h>
using namespace std;
int firstOcc(int a[],int s,int e,int x){
    int ans = -1;
    while(s<=e){
        int mid = (s+e)/2;
        if(a[mid]==x){
            ans = mid;
            e = mid-1;
        }
        else if (a[mid] > x){
            e = mid-1;
        }
        else{
            s = mid+1;
        }
    }
    return ans;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int m,n;
        cin>>m>>n;
        int a[m],b[n];
        for(int i=0;i<m;i++) cin>>a[i];
        for(int i=0;i<n;i++) cin>>b[i];
        int temp[m],visited[m];
        for(int i=0;i<m;i++){
            temp[i] = a[i];
            visited[i] = 0;
        }
        sort(temp,temp+m);
        int k=0;
        for(int i = 0; i < n; i++){
            int f = firstOcc(temp,0,m-1,b[i]);

            if(f==-1){
                continue;
            }
            
            for(int j = f; j < m && temp[j]==b[i]; j++){
                a[k++] = temp[j];
                visited[j]=1;
            }
        }
        for(int i = 0; i < m; i++){
            if(visited[i]==0){
                a[k++]=temp[i];
            }
        }
        for(int i = 0; i < m; i++){
            cout << a[i] << " ";
        }
        cout<<endl;
    }
}