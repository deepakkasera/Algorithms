#include <bits/stdc++.h>
using namespace std;
void min_heapify(std::vector<int> &v,int i,int n)
{
	int left = 2*i;
	int right = 2*i+1;
	int smallest;
	if(left <= n && v[left] < v[i])
		smallest = left;
	else smallest=i;
	if(right <= n && v[right] < v[smallest])
		smallest=right;
	if(smallest != i){
		swap(v[smallest] , v[i]);
		min_heapify(v,smallest,n);
	}
}
void bulid_min_heap(std::vector<int> &v,int n)
{
	for(int i=n/2;i>=1;i--){
		min_heapify(v,i,n);
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
	bulid_min_heap(v,n);
    cout << "Min heap is\n";
    for(int i=1;i<=n;i++)
    	cout << v[i] << " ";
    cout << '\n';
	return 0;
}