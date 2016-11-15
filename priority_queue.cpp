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
int maximum(int a[]){
	return a[1];
}
void extract_maximum(int a[],int n){            /*  Complexity of extract_maximum is O(log(n))*/ 
	int length=n;
	if(length==0)    cout<<"Empty heap",return 0;
	int max=a[1];
	a[1]=a[length];
	length--;
	max_heapify(a,1,length);
	return max;
}
void increase_value(int a[],int i,int val){     /*Complexity of increase_value is O(log(n))*/
	if(val<a[i])   return 0;
	a[i]=val;
	while(i>1 && a[i/2]<a[i])
		swap(a[i],a[i/2]),i/=2;
}
void insert_value(int a[],int value,int n){     /*Complexity of insert_value is O(log(n))*/     
	int length=n+1;
	a[length]=-1;       //assuming all the numbers to be inserted in queue are greater than 0
	increase_value(a,length,val);
	for(int i=1;i<=length;i++ )   cout<<a[i]<<" ";
}
int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
    cin>>n;
    for(int i=1;i<=n;i++)    cin>>a[i];
    build_max_heap(a,n);
    for(int i=1;i<=n;i++ )   cout<<a[i]<<" ";
    	cout<<"\n";
    cout<<"Maximum element in queue is "<<maximum(a)<<"\n";
    increase_value(a,4,15);
    cout<<"\n";
    for(int i=1;i<=n;i++ )   cout<<a[i]<<" ";
    insert_value(a,20,n);
	return 0;
}