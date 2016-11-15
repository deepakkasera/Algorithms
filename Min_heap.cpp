#include <bits/stdc++.h>
using namespace std;
int n,a[100000];
void min_heapify(int a[],int i,int n){                  /* Complexity of min_heapify is O(log(n))  */ 
	int left=2*i,right=2*i+1;
	int smallest;
	if(left<=n && a[left]<=a[i])
		smallest=left;
	else smallest=i;
	if(right<=n && a[right]<=a[smallest])
		smallest=right;
	if(smallest!=i){
		swap(a[i],a[smallest]);
		min_heapify(a,smallest,n);
	}
}
void build_min_heap(int a[],int n){                      /* Complexity of build_min_heap is O(n)  */ 
	for(int i=n/2;i>=1;--i)
		min_heapify(a,i,n);
}
int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
    cin>>n;
    for(int i=1;i<=n;i++)    cin>>a[i];
    build_min_heap(a,n);
    for(int i=1;i<=n;i++)    cout<<a[i]<<" ";
	return 0;
}