#include <bits/stdc++.h>
using namespace std;
std::vector<int> v[100000];
bool visited[100000];
void dfs(int node){
	visited[node] = true;
	cout << node << "-->";
	for(int i=0;i<v[node].size();i++)
	{
		if(!visited[v[node][i]])
			dfs(v[node][i]);
	}
	return ;
}
int main(int argc, char const *argv[])
{
	int nodes,edges;
	cin >> nodes >> edges;
	for(int i=0;i<edges;i++){
		int a,b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	memset(visited,false,sizeof(visited));
	dfs(1);
	return 0;
}