#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	std::vector<int> v(n);
	for(int i=0;i<n;i++) cin >> v[i];
	set<int> s;
    set<int>::iterator it;
    s.insert(v[0]);
    int inversions=0;
    for(int i=1;i<n;i++){
    	s.insert(v[i]);
    	it = s.upper_bound(v[i]);
    	inversions += distance(it,s.end());
    }
    cout << inversions << endl;
	return 0;
}