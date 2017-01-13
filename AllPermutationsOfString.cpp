#include <bits/stdc++.h>
using namespace std;
void allPermutations(std::vector<int> &a,int k,int n){
   int count = 0;
   if(k == n-1){
   	 for(int i=0;i<n;i++)  cout << a[i];
   	 cout << endl ;
   }
   else {
   	for(int i=k;i<n;i++){
   		swap(a[i],a[k]);
   		allPermutations(a,k+1,n);
   		swap(a[i],a[k]);
   	}
   }
}
void allPermutationsOfString(string str,int k){
   int n = str.length() ;
   if(k == n-1){
   	cout << str << endl ;
   }
   else {
   	for(int i=k;i<n;i++){
   		swap(str[i],str[k]);
   		allPermutationsOfString(str,k+1);
   		swap(str[i],str[k]);
   	}
   }
}
int main(int argc, char const *argv[])
{
	int n;
	string str;
	cout << "Enter the number of elements ";
	cin >> n ;
	std::vector<int> v(n);
	for (int i = 0; i < n; ++i)
	{
		cout << "Enter the element " ;
		cin >> v[i] ;
	}
    allPermutations(v,0,n);
    cout << "Enter a String " ;
    cin >> str ;
	cout << "Permutations of String " << endl ;
	allPermutationsOfString(str,0);
	return 0;
}