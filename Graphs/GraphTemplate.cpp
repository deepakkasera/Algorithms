#include <bits/stdc++.h>
using namespace std;

#define um map<T , list<T> >

template<typename T>
class Graph{
	um m;

public:
	void addEdge(T u,T v,bool bidir = true) {
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
	return 0;
}