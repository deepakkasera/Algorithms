#include <bits/stdc++.h>
#define um unordered_map < T,list<T> >

using namespace std;

template <typename T>
class graph{
	um m;

public:
	
	void addEdge(T u,T v,bool bidir = true){
		m[u].push_back(v);
		if(bidir){
			m[v].push_back(u);
		}
	}

	void printAdjList() {
		for(auto it = m.begin(); it != m.end(); it++) {
			
			cout << it->first << "==>";
			for(auto i : it->first) {
				cout << i << ",";
			}

			cout << endl;

		}
	}

	void BFS(T src) {
		queue<T> q;
		unordered_map<T,bool> visited;

		q.push(src);
		visited[src] = true;

		while(!q.empty()){
			T temp = q.front();
			q.pop();
			cout << temp << " ";
			for(auto it = m[temp].begin(); it != m[temp].end(); it++){
				if(visited[*it]==false){
					q.push(*it);
					visited[*it] = true;
				}
			}
		}
		cout << endl;
	}

};
int main(int argc, char const *argv[])
{
	graph<int> g;
	g.addEdge(1,2);
	g.addEdge(1,3);
	g.addEdge(2,3);
	g.addEdge(3,5);
	g.addEdge(4,5);
	g.addEdge(1,6);
	g.addEdge(2,6);
	g.BFS(1);
	return 0;
}