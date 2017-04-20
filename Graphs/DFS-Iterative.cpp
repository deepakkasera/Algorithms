#include <bits/stdc++.h>
using namespace std;
bool visited[1000000];
std::vector<int> v[100000];
void dfs(int node){
	stack<int> s;
	s.push(node);
	visited[node] = true;
	while(!s.empty())
	{
		int x = s.top();
		s.pop();
		cout << x << "-->";
		for(int i=0;i<v[x].size();i++)
		{
			if(!visited[v[x][i]]){
				s.push(v[x][i]);
				visited[v[x][i]] = true;
			}
		}
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