#include <bits/stdc++.h>
using namespace std;
int maze(std::vector<std::vector<int> > &v,int rows,int cols){
	if(v[0][0] == -1)  return 0;
	for(int i=0;i<rows;i++){
		if(v[i][0] == 0) v[i][0] = 1;
		else break;
	}
	for(int i=1;i<cols;i++){
		if(v[0][i] == 0 ) v[0][i] = 1;
        else break;
	}
	for(int i=1;i<rows;i++){
          for(int j=1;j<cols;j++){
             if(v[i][j] == -1) continue;
             if(v[i-1][j] > 0) v[i][j] += v[i-1][j];
             if(v[i][j-1] > 0) v[i][j] += v[i][j-1];

          }
	}
	return (v[rows-1][cols-1] > 0) ? v[rows-1][cols-1] : 0 ;
}
//Time Complexity O(r*c)
int main(int argc, char const *argv[])
{
	int r,c;
	cout << "Enter the number of rows and columns \n" ;
	cin >> r >> c;
	std::vector< std::vector<int> > v(r,std::vector<int>(c));
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			//Only -1 and 0 are allowed (0 for valid and -1 for invalid)
			cin >> v[i][j];
		}
	}
	cout << maze(v,r,c) << endl;
	return 0;
}