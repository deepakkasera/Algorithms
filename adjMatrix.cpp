#include<bits/stdc++.h>
using namespace std;
bool a[10][10];
void initialize(){
	for(int i=0;i<n;i++){
	   for(int j=0;j<n;j++){
	       a[i][j]=false;
	   }
	}
}
int main(){
	int x,y,edges,nodes;
	cin>>n;
    initialize();
    cin>>nodes;
    cin>>edges;
    for(int i=0;i<edges;i++){
        cin>>x>>y;
        a[x][y]=true;
    }
    return 0;

}