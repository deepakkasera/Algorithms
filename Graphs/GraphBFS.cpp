#include <bits/stdc++.h>
using namespace std;

#define um unordered_map<T,list<T> > 
template <typename T>
class Graph {
	um m;

public:
	void addEdge(T u, T v,bool bidir = true) {
		m[u].push_back(v);
		if(bidir){
			m[v].push_back(u);
		}
	}

	void printAdjList() {
		for(auto it = m.begin(); it != m.end(); it++) {
			
			cout << it->first << "=> ";

			for(auto j : it->second) {
				cout << j << ",";
			}

			cout << endl;
		}
	}

	void BFS(T src) {
		queue<T> q;
		unordered_map<T,bool> visited;
		unordered_map<T,int> dist;
		unordered_map<T,T> parent;

		q.push(src);
		visited[src] = true;
		dist[src] = 0;

		while(!q.empty()) {
			T temp = q.front();
			q.pop();
			cout << temp << "-->";
			for(auto j = m[temp].begin();j!=m[temp].end();j++){
				if(!visited[*j]){
					dist[*j] = dist[temp] + 1;
					parent[*j] = temp; 
					visited[*j] = true;
					q.push(*j);
				}
			}
		}

		cout << "Distance\n";
		for(auto it = m.begin(); m.end(); it++) {
			cout << it->first << " " << dist[it->first] << endl;
		}
	}

};
int main(int argc, char const *argv[])
{
	Graph<string> g;
	
	g.addEdge("Amritsar","Delhi");
	g.addEdge("Amritsar","Jaipur");
	g.addEdge("Jaipur","Delhi");
	g.addEdge("Jaipur","Mumbai");
	g.addEdge("Agra","Delhi");
	g.addEdge("Bhopal","Delhi");
	g.addEdge("Mumbai","Bhopal");
	
	g.printAdjList();

	cout<<endl;
	string city;
	cout << "Enter the city for BFS traversal\n";
	cin >> city;
	g.BFS(city);
	cout << endl;
	return 0;
}