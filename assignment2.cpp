#include <bits/stdc++.h>
using namespace std;
void min_heapify(std::vector<int> &a,int i,int n){
	int left = 2*i;
	int right = 2*i + 1;
	int smallest;
	if(left <= n && a[left] < a[i])
		smallest = left;
	else smallest=i;
	if(right <= n && a[right] < a[smallest]) smallest=right;
	if(smallest != i){
		swap(a[i],a[smallest]);
		min_heapify(a,smallest,n);
	}
}
void build_min_heap(std::vector<int> &a,int n){
	for(int i=n/2;i>=1;i--){
		min_heapify(a,i,n);
	}
}
int main(int argc, char const *argv[])
{
	int n;
	cout << "Enter the number elements " << endl;
	cin >> n ;
	std::vector<int> v(n);
	cout << "Enter elements " << endl ;
	for(int i=1;i<=n;i++) cin>>v[i];
	build_min_heap(v,n);
	for(int i=1;i<=n;i++) cout << v[i] <<" ";
	cout << endl ;
	return 0;
}
