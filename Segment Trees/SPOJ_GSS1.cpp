#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int maxisum[100000];
int sum[100000];
int maxlsum[100000];
int maxrsum[100000];
int a[50000];
int n,m;

void set(int node,int val){
	sum[node] = maxisum[node] = maxlsum[node] = maxrsum[node] = val;
}

void calc(int node){
	sum[node] = sum[2*node] + sum[2*node + 1];
	maxlsum[node] = max(maxlsum[2*node] , sum[2*node] + maxlsum[2*node+1]);
	maxrsum[node] = max(maxrsum[2*node+1], sum[2*node+1] + maxrsum[2*node]);
    maxisum[node] = max(max(maxisum[2*node], maxisum[2*node+1]),
                        maxrsum[2*node] + maxlsum[2*node+1]);
}


void build_tree(int node,int l,int r){
	if(r-l == 1){
		set(node,a[l]);
	}
	else{
		int m = l + (r - l + 1)/2;

		build_tree(2*node,l,m);
		build_tree(2*node + 1,m,r);
		calc(node);
	}
}

int query(int begin,int end){
	
}

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
	ci.tie(NULL);
	cin>>n;
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	cin>>m;
	return 0;
}