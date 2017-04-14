#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;

typedef pair<int,int> iPair;

class Graph
{
	int V;
	std::vector<iPair> *v;
public:
	Graph(int V){
		this->V = V;
		v = new vector<iPair>[V];
	}

	void addEdge(int a,int b,int d){
		v[a].push_back(make_pair(b,d));
		v[b].push_back(make_pair(a,d));
	}

	void shortestPath(int src);
};

void Graph::shortestPath(int src){
	priority_queue < iPair , std::vector<iPair> , greater<iPair> > pq;
	std::vector<int> distance(V,INF);

	pq.push(make_pair(0,src));
	distance[src] = 0;
	while(!pq.empty()){
		int u = pq.top().second;
		pq.pop();

		for(int i=0;i<v[u].size();i++){
			int vertex = v[u][i].first;
			int dist = v[u][i].second;

			if(distance[vertex] > dist + distance[u]){
				distance[vertex] = dist + distance[u];
				pq.push(make_pair(distance[vertex],vertex));
			} 
		}
	}

	cout << "Shortest path of all the nodes from " << src << " node is\n";
	for(int i=0;i<V;i++){
		cout << i << " "  << distance[i] << endl;
	}
}

int main(int argc, char const *argv[])
{
	int V=9;
	Graph g(V);

	g.addEdge(0, 1, 4);
    g.addEdge(0, 7, 8);
    g.addEdge(1, 2, 8);
    g.addEdge(1, 7, 11);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 8, 2);
    g.addEdge(2, 5, 4);
    g.addEdge(3, 4, 9);
    g.addEdge(3, 5, 14);
    g.addEdge(4, 5, 10);
    g.addEdge(5, 6, 2);
    g.addEdge(6, 7, 1);
    g.addEdge(6, 8, 6);
    g.addEdge(7, 8, 7);
 
    g.shortestPath(0);
	return 0;
}