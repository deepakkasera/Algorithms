#include<bits/stdc++.h>
using namespace std;
int getSum(int BIT[],int index){
  int sum=0;
  while(index > 0){
    sum += BIT[index];
    
    index -= index&-index;
  } 
  return sum;
}
void update(int BIT[],int n,int index,int val){
  while(index <= n){
    BIT[index] += val;
    index += index&-index;
  }
}
int getInvCount(int a[],int n){
  int maxelement=0,inv=0;
  for(int i=0;i<n;i++){
    maxelement=max(maxelement,a[i]);
  }
  int BIT[maxelement+1];
  for(int i=0;i<maxelement+1;i++)
    BIT[i]=0;
  
  for(int i=n-1;i>=0;i--){
    inv += getSum(BIT,a[i]-1);
    update(BIT,maxelement,a[i],1);
  }
  return inv;
}
int getInvCount2(int a[],int n){
  int maxe=0;
  int inversion=0;
  for(int i=0;i<n;i++)
    maxe=max(maxe,a[i]);
  int BITree[maxe+1];
  for(int i=0;i<maxe+1;i++)
    BITree[i]=0;
  for(int i=0;i<n;i++){
    inversion += getSum(BITree,a[i]-1);
    update(BITree,maxe,a[i],1);
  }
  return inversion;
}
int main(){
  int d;
  cin>>d;
  while(d--){
    int n;
    cin >> n;
    int a[n];
    for(int i=0;i<n;i++) cin >> a[i];
    cout << getInvCount(a,n) << endl;  
    cout << getInvCount2(a,n) << endl;
  }
  return 0;
}