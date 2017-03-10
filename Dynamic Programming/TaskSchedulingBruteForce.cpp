#include <bits/stdc++.h>
using namespace std;
int fact(int n){
	if(n==0 || n==1) return 1;
	return n*fact(n-1);
}
int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	int cost[n][n];
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin >> cost[i][j];
		}
	}
	int assignment[n];
	//assigning ith job to ith person
	for(int i=0;i<n;i++){
		assignment[i]=i;
	}
	//there are n! ways to assign n jobs to n persons
	int minCost=INT_MAX;
	int totalCost;
	for(int i=0;i<fact(n);i++){
		totalCost=0;
		for(int j=0;j<n;j++){
			totalCost += (cost[j][assignment[j]]);
		}
		minCost = min(minCost,totalCost);
		next_permutation(assignment,assignment+n);
	}
	cout << minCost << endl;	
	return 0;
}