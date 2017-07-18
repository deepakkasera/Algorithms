#include <bits/stdc++.h>
using namespace std;
class CompareDist
{
public:
    bool operator()(pair<int,int> n1,pair<int,int> n2) {
        return n1.second>n2.second;
    }
};
int main(int argc, char const *argv[])
{
	priority_queue< pair<int,int>,vector<pair<int,int> >,CompareDist> pq;
	pq.push(make_pair(10,20));
	pq.push(make_pair(7,14));
	pq.push(make_pair(30,20));
	pq.push(make_pair(40,50));
	pq.push(make_pair(12,81));
	while(!pq.empty()){
		cout << pq.top() << " ";
		pq.pop();
	}
	return 0;
}