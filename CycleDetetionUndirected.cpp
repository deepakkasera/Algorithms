#include <bits/stdc++.h>
using namespace std;
std::vector<int> v[100];
bool visited[100];
void initialize(){
	for(int i=0;i<100;i++)   
		visited[i]=false;
}
bool isCyclic(int s,int parent){
	visited[s]=true;
	for(int i=0;i<v[s].size();i++){
		if(!visited[v[s][i]]){
			if(isCyclic(i,v[s]))
				return true;
		}
		if(v[s][i]!=parent)
			return true;
	}
	return false;
}
int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
	int nodes,edges,x,y;
	cin>>nodes>>edges;
	for(int i=0;i<edges;i++){
		cin>>x>>y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	initialize();
	for(int i=1;i<=nodes;i++){
		if(!visited[i]){
			if(isCyclic(i,-1)) {
				cout<<"graph contains cycle";
				return 0;
			}
		}
		cout<<"graph doesn't contain cycle";
		return 0;
	}
}
