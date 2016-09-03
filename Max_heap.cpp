#include <bits/stdc++.h>
using namespace std;
int n,a[100000];
void max_heapify(int a[],int i,int n){         /* Complexity of max_heapify is O(log(n))  */                  
	int left=2*i,right=2*i+1;                                        
	int largest;
	if(left<=n && a[left]>=a[i])
		largest=left;
	else largest=i;
	if(right<=n && a[right]>=a[largest]) 
		largest=right;
	if(largest != i){
		swap(a[i],a[largest]);
		max_heapify(a,largest,n);
	}
}
void build_max_heap(int a[],int n){              /* Complexity of build_max_heap is O(n)  */
	for(int i=n/2;i>=1;i--)
        max_heapify(a,i,n);
}
int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
    cin>>n;
    for(int i=1;i<=n;i++)    cin>>a[i];
    build_max_heap(a,n);
    for(int i=1;i<=n;i++ )   cout<<a[i]<<" ";
	return 0;
}
