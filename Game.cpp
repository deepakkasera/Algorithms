#include <bits/stdc++.h>
using namespace std;
int game(int a[],int i,int j){
   if(i > j ) return 0 ;
   int option1 = a[i] + min(game(a,i+2,j),game(a,i+1,j-1)) ;
   int option2 = a[j] + min(game(a,i+1,j-1),game(a,i,j-2)) ;
   return max(option1,option2) ;
}
int main(int argc, char const *argv[])
{
	int n; 
	//Enter even number of coins
	cin >> n ;
	int a[n] ;
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i] ;
	}
	cout << game(a,0,n-1) ;	
 	return 0;
}