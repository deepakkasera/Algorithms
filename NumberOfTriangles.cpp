#include <bits/stdc++.h>
using namespace std;
//COmplexity is O(n^3)
int numberOfTriangles(std::vector<int> &v,int n){
	int count=0;
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			for(int k=j+1;k<n;k++){
				if(v[i]+v[j] > v[k] && v[j]+v[k]>v[i] && v[i]+v[k]>v[j]){
					count++;
					cout << "{" << v[i] <<"," <<  v[j] <<"," << v[k] <<"}" << endl;
				}
			}
		}
	}
	return count;
}
//Better solution
//Complexity is O(n^2)
int numberOfTrianglesOptimized(std::vector<int> &v,int n){
	int count=0;
	sort(v.begin(),v.end());
	for(int i=0;i<n;i++){
		int j=i+1;
		int k=j+1;
		for(j;j<n-1;j++){
			while(k<n && v[i]+v[j]>v[k]) k++;
			count += (k-j-1);
		}
	}
	return count;
}
int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	std::vector<int> v(n);
	for(int i=0;i<n;i++){
		cin >> v[i];
	}
	cout << "Number of triangles possible is " << numberOfTriangles(v,n) << endl;
	cout << "Number of triangles possible is " << numberOfTrianglesOptimized(v,n) << endl;
	return 0;
}