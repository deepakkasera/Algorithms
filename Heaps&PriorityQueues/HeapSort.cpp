#include <bits/stdc++.h>
using namespace std;
void max_heapify(std::vector<int> &v,int i,int n)
{
	int left = 2*i;
	int right = 2*i+1;
	int largest;
	if(left<=n && v[left] > v[i])
		largest=left;
	else largest=i;
	if(right<=n && v[right] > v[largest])
		largest=right;
	if(largest!=i){
		swap(v[i],v[largest]);
		max_heapify(v,largest,n);
	}
	return;
}
void bulid_max_heap(std::vector<int> &v,int n){
	for(int i=n/2;i>=1;i--){
		max_heapify(v,i,n);
	}
	return;
}
void heap_sort(std::vector<int> &v,int n)
{
	int heap_size = n;
	bulid_max_heap(v,n);
	for(int i=n;i>=2;i--){
		swap(v[1],v[i]);
		heap_size--;
		max_heapify(v,1,heap_size);
	}
	return;
}
int main(int argc, char const *argv[])
{
	int n;
	cout << "Enter the value of n\n";
	cin >> n;
	std::vector<int> v(n+1);
	cout << "Enter " << n << " elements\n";
	for(int i=1;i<=n;i++) cin>>v[i];
	heap_sort(v,n);
    cout << "Array in sorted order is \n";
    for(int i=1;i<=n;i++)
    	cout << v[i] << " ";
    cout << '\n';
	return 0;
}