#include <bits/stdc++.h>
using namespace std;
void printAllSubsets(std::vector<int> &v,int n){
	for(int i=0;i < (1 << n);i++){
		if(i==0) cout << "NULL";
		for(int j=0;j<n;j++){
           if(i & (1 << j)){
           	cout << v[j] << " ";
           }
		}
		cout << endl;
	}
}
int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	std::vector<int> v(n);
	for(int i=0;i<n;i++) cin >>v[i];
	printAllSubsets(v,n);
	return 0;
}