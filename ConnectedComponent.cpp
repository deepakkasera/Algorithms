#include <bits/stdc++.h>
using namespace std;
std::vector<int> v[100];
bool visited[100];
void initalize(){
      for(int i=0;i<100;i++)
      	visited[i]=false;
}
void dfs_recursive(int s){
	visited[s]=true;
	cout<<s<<" ";
	for(int i=0;i<v[s].size();i++){
		if(!visited[v[s][i]])
			dfs_recursive(v[s][i]);
	}
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    int nodes,edges,x,y;
    cin>>nodes>>edges;
    for(int i=0;i<edges;i++){
    	cin>>x>>y;
    	//undirected graph
    	v[x].push_back(y);
    	v[y].push_back(x);
    }
    for(int i=1;i<=nodes;i++){
    	cout<<"Adjacency list of node "<<i<<" is ";
    	for(int j=0;j<v[i].size();j++){
    		if(j == v[i].size()-1 )    cout<<v[i][j]<<"\n";
    		else cout<<v[i][j]<<"-->";
    	}
    }
    initalize();
    int connected=0;
    for(int i=1;i<=nodes;i++){
    	if(!visited[i]){
    		dfs_recursive(i);
            connected++;

    	}
    }
    cout<<"\n"<<    connected;
	return 0;
}