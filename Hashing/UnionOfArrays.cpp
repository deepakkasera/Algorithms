#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	std::map<int,bool> m;
	int n;
	cin >> n;
	std::vector<int> v1(n);
	std::vector<int> v2(n);
	for(int i=0;i<n;i++) cin >> v1[i];
	for(int i=0;i<n;i++) cin >> v2[i];
	for(int i=0;i<n;i++){
		m[v1[i]] = true;
	}
	for(int i=0;i<n;i++){
		m[v2[i]]=true;
	}
	std::map<int , bool>::iterator it;
	for(it=m.begin();it!=m.end();it++){
		cout << it->first << " ";
	}
    return 0;
}