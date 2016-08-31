#include <bits/stdc++.h>
using namespace std;
std::vector< std::vector<int> > v(100);
int main(){
	int x,y,nodes,edges;
	cin>>nodes>>edges;
	for(int i=0;i<edges;i++){
		cin>>x>>y;
		v[x].push_back(y);
	}
	for(int i=1;i<=nodes;i++){
		cout<<"adjacency list of node "<<i<<":";
		for(int j=0;j<v[i].size();j++){
			if(j == v[i].size()-1)  cout<<v[i][j]<<"\n";
			else cout<<v[i][j]<<"-->";
		}
	}
	return 0;
}
