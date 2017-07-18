#include <iostream>
#include <algorithm>
#include <set>
#include <queue>
#include <vector>
using namespace std;
  
int N,K,A,B,C[100000]	;
vector<int> G[100000];
  
queue<int> Q;
vector<int>::iterator it;
long long colour(int root) {
    C[root] = 1;
    Q.push(root);
    long long result = 1;
    while(!Q.empty()) {
        int u = Q.front();
        Q.pop();
        for(it = G[u].begin(); it != G[u].end(); it++) {
            int v = *it;
            if(C[v]==0) {
                C[v] = 1;
                result++;
                Q.push(v);
            }
        }
    }
    return result;
}
  
int main() {
    cin >> N >> K;
    for(int i = 0; i < K; i++) {
        cin >> A >> B;
        G[A].push_back(B);
        G[B].push_back(A);
    }
    long long result = 0;
    long long sum = 0;
    for(int i = 0; i < N; i++)
        if(C[i]==0) {
            long long x = colour(i);
            result += sum*x;
            sum += x;
    }
    cout << result << endl;
}