#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	std::vector<pair<int, int > > v;
	int x,y;
	for(int i = 0; i < n; i++){
		cin >> x >> y;
		v.push_back(make_pair(x,y));
	}
	sort(v.begin() , v.end());
	stack<pair <int , int > > s;
	s.push(v[0]);
	for(int i = 1; i < n; i++){
		pair<int , int> p = s.top();
		s.pop();
		if(p.second > v[i].first) {
			p.second = v[i].second;
			s.push(p);
		}
		else{
			s.push(p);
			s.push(v[i]);
		}
	}
	std::vector<pair<int,int> > ans;
	while(!s.empty()){
		pair<int, int> p = s.top();
		s.pop();
		// cout << p.first << " " << p.second << endl;
		ans.push_back(p);
 	}
 	cout << "Answer \n";
 	sort(ans.begin() , ans.end());
 	for(int i = 0; i < ans.size(); i++){
 		cout << ans[i].first  << " " << ans[i].second << endl;;
 	}
 	cout<<endl;
	return 0;
}