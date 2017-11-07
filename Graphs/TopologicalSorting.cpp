#include <bits/stdc++.h>
#define ll long long;
using namespace std;
class Graph{
	int V;
	list<int> *adjList;

public:
	Graph(int v){
		V = v;
		adjList = new list<int>[V];
	}

	void addEdge(int u,int v,bool bidir=true){
		adjList[u].push_back(v);
		if(bidir) {
			adjList[v].push_back(u);
		}
	}

	void printList() {
		for(int i = 0; i < V; i++) {
			cout << i << "-->";
			for(auto u : adjList[i]) {
				cout << u << ",";
			}
			cout<<endl;
		}
	}
	
	void topologicalSortHelper(int v,bool *visited,stack<int> &s){
		visited[v] = true;

		for(int u : adjList[v]) {
			if(visited[u] == false) {
				topologicalSortHelper(u , visited , s);
			}
		}
		s.push(v);
	}

	void topologicalSort() {
		stack<int> s;
		bool* visited = new bool[V];
		for(int i = 0; i < V; i++){
			visited[i] = false;
		}

		for(int i = 0; i < V; i++){
			if(!visited[i]) {
				topologicalSortHelper(i , visited , s);
			}
		}
		while(!s.empty()){
			cout << s.top() << " ";
			s.pop();
		}
		cout<<endl;
	}
};
int main(int argc, char const *argv[])
{
	Graph g(6);
	g.addEdge(5,2,false);
	g.addEdge(5,0,false);
	g.addEdge(4,0,false);
	g.addEdge(4,1,false);
	g.addEdge(3,1,false);
	g.addEdge(2,3,false);
	g.printList();
	cout << "Topological Sort is ";
	g.topologicalSort();
	return 0;
}