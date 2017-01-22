// Deepak Kasera
// 101403057
#include <bits/stdc++.h>
using namespace std;
int n,m;
std::vector<int> v;
//Complexity of minHeap is O(logn)
void minHeapify(std::vector<int> &v,int i,int n){
	int left = 2*i;
	int right = 2*i + 1;
	int smallest;
	if(v[left] < v[i] && left <=n) smallest = left;
	else smallest = i ;
	if(v[right] < v[smallest] && right <= n)  smallest = right;
	if(smallest != i){
		swap(v[i],v[smallest]);
		minHeapify(v,smallest,n);
	}
}
//Complexity is O(nlog(n))
void buildMinHeap(std::vector<int> &v,int n){
    for(int i=n/2;i>=1;i--){
    	minHeapify(v,i,n);
    }
}
bool isEmpty(std::vector<int> &v){
	if(v.size() == 0) return true;
	return false;
}
int findMin(std::vector<int> &v,int n){
	return v[1];
}
void insert(int n,int item){
	v.resize(++n);
	v[n] =item;
	cout<<n;
	//buildMinHeap(v,n);
}
int main(int argc, char const *argv[])
{
	int x;
	cin >> n;
	v.resize(n);
	for(int i=1;i<=n;i++) cin >> v[i];
	buildMinHeap(v,n);
	for(int i=1;i<=n;i++) cout << v[i] <<" ";
	if(isEmpty(v)) cout << "\nEmpty\n";
    else cout << "Not Empty\n";
    cout << "Minimum value is " << findMin(v,n) << endl;
    cout << " Enter the element " ;
    cin >> x;

    insert(n,x);
    cout << endl;
    for(int i=1;i<=n;i++) cout << v[i] <<" ";
	cout << endl;
	return 0;
}