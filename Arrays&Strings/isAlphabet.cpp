#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	string s;
	cin >> s;
	int n = s.length();
	// char temp[n];
	// int k = 0;
	// for(int i = 0; i < n; i++){
	// 	if((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')){
	// 		// cout << s[i] << " is alphabet\n";
	// 		temp[k++] = s[i];
	// 	}
	// }
	// // cout<<temp<<endl;
	// int l=0,r=k-1;
	// while(l < r){
	// 	swap(temp[l],temp[r]);
	// 	l++;
	// 	r--;
	// }
	// // cout<<temp<<endl;
	// int i=0,j=0;
	// while(i < n && j < k){
	// 	if((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')){
	// 		s[i] = temp[j];
	// 		i++;
	// 		j++;
	// 	}
	// 	else i++;
	// }
	// cout<<s<<endl;
	int l = 0,r = n-1;
	while(l < r){
		if(!((s[l] >= 'a' && s[l] <= 'z') || (s[l] >= 'A' && s[l] <= 'Z'))){
			l++;
		}
		else if(!((s[r] >= 'a' && s[r] <= 'z') || (s[r] >= 'A' && s[r] <= 'Z'))){
			r--;
		}
		else{
			swap(s[l] , s[r]);
			l++;
			r--;
		}
	}
	cout << s << endl;
	return 0;
}