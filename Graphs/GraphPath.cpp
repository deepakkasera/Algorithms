#include <bits/stdc++.h>
#define um unordered_map<T,list<T> >
using namespace std;
template<typename T>
class Graph{
	um m;

public:

	void addEdge(T u,T v,bool bidir = true){
		m[u].push_back(v);
		if(bidir) {
			m[v].push_back(u);
		}
	}

	void printEdgeList() {
		for(auto it = m.begin(); it!=m.end(); it++){
			cout << it->first << " ";
			for(auto i : it->second) {
				cout << i << ", ";
			}
		}
		cout << endl;
	}

	void bfs(T src,T dest) {
		unordered_map <T , bool> visited;
		unordered_map <T,T> parent;
		unordered_map <T,int> dist;
 		
 		queue<T> q;
		visited[src] = true;
		q.push(src);
		dist[src] = 0;
		parent[src] = src;

		while(!q.empty()) {
			T temp = q.front();
			q.pop();

			for(auto it : m[temp]){
				if(!visited[it]){
					parent[it] = temp;
					dist[it] = dist[temp]+1;
					visited[it] = true;
					q.push(it);
				}
			}
		}

		for(auto it = m.begin(); it!=m.end(); it++){
			cout << it->first << "  " << dist[it->first]<<endl;
		}

		cout << "Path between city " << src << " and " << dest << " is "<<endl;
		T temp = dest;
		while(temp != src) {
			cout << temp << "<--";
			temp = parent[temp];
		}
		cout<<src<<endl;
		cout<<endl;
	}

	void dfsHelper(T node,unordered_map<T,bool> &visited){
		visited[node] = true;
		cout << node << "-->";

		for(auto it = m[node].begin(); it != m[node].end(); it++){
			if(!visited[*it]){

				dfsHelper(*it,visited);

			}
		}
	}

	void dfs(T src) {
		unordered_map<T,bool> visited;

		dfsHelper(src,visited);
	}

};
int main(int argc, char const *argv[])
{	
	// graph<int> g;
	// graph<int> g;
	// g.addEdge(1,2);
	// g.addEdge(1,3);
	// g.addEdge(2,3);
	// g.addEdge(3,5);
	// g.addEdge(4,5);
	// g.addEdge(1,6);
	// g.addEdge(2,6);
	// g.printPath(1,6);
	Graph<string> g;
	
	g.addEdge("Amritsar","Delhi");
	g.addEdge("Amritsar","Jaipur");
	g.addEdge("Jaipur","Delhi");
	g.addEdge("Jaipur","Mumbai");
	g.addEdge("Agra","Delhi");
	g.addEdge("Bhopal","Delhi");
	g.addEdge("Mumbai","Bhopal");
	string city1,city2;
	cin>>city1>>city2;
	g.bfs(city1,city2);
	cout<<"DFS traversal is \n";
	g.dfs(city1);
	return 0;
}