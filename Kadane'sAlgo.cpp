#include <bits/stdc++.h>
using namespace std;
int kadane(std::vector<int> &v,int n){
    int current_max=v[0],global_max=v[0];
    int start = 0,end = 0,s = 0;
    for(int i=1;i<n;i++){
     if ( v[i] > current_max + v[i]) current_max = v[i],s = i ;
     else current_max += v[i]; 	
   	 // current_max = max(v[i],current_max + v[i]);
   	if(global_max < current_max) {
   		global_max = current_max;
   		start = s;
   		end = i;
    }
   }
   cout << "Starting index of maximum sum subarray is " << start <<"\n";
   cout << "Ending index of maximum sum subarray is " << end <<"\n";
   cout << "Subarray is \n"; 
   for(int i=start;i<=end;i++) cout << v[i] << " " ;
   cout <<"\n";
   cout << "Maximum sum is\n";
       return global_max;
}
// int kadane(std::vector<int> &v,int n){
// 	int current_max = 0,global_max = INT_MIN;
//  	for(int i=0;i<n;i++){
//  		current_max += v[i];
//  		if(current_max < 0) current_max =0;
//  		if(current_max > global_max) global_max = current_max; 
//         if(current_max < 0) current_max = 0;
// 	}
// 	return global_max;
// }
int main(int argc, char const *argv[])
{
	int n;
	cout << "Enter the number of elements\n";
	cin >> n;
    std::vector<int> v(n);
    for (int i = 0; i < n; ++i) cin >> v[i] ;
    	cout << kadane(v,n) << endl;
	return 0;
}