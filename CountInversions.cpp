#include <bits/stdc++.h>
using namespace std;
int countInversions(std::vector<int> &v,int n){
	int count =0;
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(v[i]>v[j]) count++;
		}
	}
	return count;
}
int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	std::vector<int> v(n);
	for(int i=0;i<n;i++) cin >> v[i];
    cout << countInversions(v,n) << endl;
	return 0;
}