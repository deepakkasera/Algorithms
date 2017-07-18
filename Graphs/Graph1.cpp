#include <iostream>
#include <list>
using namespace std;
class Graph {
	int V;
	list<int> *l;

public:
	Graph(int v) {
		V = v;
		l = new list<int>[v];
	}

	void addEdge(int u,int v,bool bidir=true){
		l[u].push_back(v);
		if(bidir){
			l[v].push_back(u);
		}
	}

	void printList() {
		for(int i = 0; i < V; i++) {
			cout << i << "-->";
			for(auto it : l[i]) {
				cout << it << ",";
			}
			cout<<endl;
		}
	}

};
int main(int argc, char const *argv[])
{
	Graph g(6);
	g.addEdge(0,1);
	g.addEdge(0,2);
	g.addEdge(0,3);
	g.addEdge(2,3);
	g.addEdge(3,4);
	g.addEdge(4,5);
	g.printList();
	cout<<endl;
	return 0;
}