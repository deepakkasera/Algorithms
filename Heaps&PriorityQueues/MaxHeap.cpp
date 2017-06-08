#include <bits/stdc++.h>
#define ll long long
#define MAXN 100009
using namespace std;
void max_heapify(std::vector<int> &v,int i,int n)
{
	int left = 2*i;
	int right = 2*i+1;
	int largest;
	if(left <= n && v[left] > v[i])
		largest = left;
	else largest = i;
	
	if(right <= n && v[right] > v[largest])
		largest = right;
	if(largest != i)
	{
		swap(v[largest],v[i]);
		max_heapify(v,largest,n);
	}
}
void bulid_max_heap(std::vector<int> &v,int n)
{
	for (int i = n/2; i >= 1; --i)
	{
		/* code */
		max_heapify(v,i,n);
	}
	return ;
}
int main(int argc, char const *argv[])
{
	int n;
	cout << "Enter the value of n\n";
	cin >> n;
	std::vector<int> v(n+1);
	cout << "Enter " << n << " elements\n";
	for(int i=1;i<=n;i++) cin>>v[i];
	bulid_max_heap(v,n);
    cout << "Max heap is\n";
    for(int i=1;i<=n;i++)
    	cout << v[i] << " ";
    cout << '\n';
	return 0;
}