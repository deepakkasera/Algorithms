#include <bits/stdc++.h>
using namespace std;
std::vector<int> v[100000];
bool visited[100000];
int connectedComponents=0;
void dfs(int node){
	visited[node] = true;
	for(int i=0;i<v[node].size();i++){
		if(!visited[v[node][i]])
			dfs(v[node][i]);
	}
}
int main(int argc, char const *argv[])
{
	int nodes,edges;
	cin>>nodes>>edges;
	for(int i=0;i<edges;i++)
	{
		int a,b;
		cin>>a>>b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	memset(visited,false,sizeof(visited));
	for(int i=1;i<=nodes;i++)
	{
		if(!visited[i]){
			dfs(i);
			connectedComponents++;
		}
	}
	cout << connectedComponents << endl;
	return 0;
}