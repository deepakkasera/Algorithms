// #include <bits/stdc++.h>
// using namespace std;
// void printSpiral(int a[][12],int m,int n)
// {
// 	int startRow = 0, endRow = m-1;
// 	int startCol = 0, endCol = n-1;
// 	while(startRow <= endRow && startCol <= endCol){
// 		for(int i = startCol; i <= endCol; i++){
// 			cout << a[startRow][i] << ", ";
// 		}
// 		startRow++;
		
// 		for(int i = startRow; i <= endRow; i++){
// 			cout << a[i][endCol] << ", ";
// 		}
// 		endCol--;

// 		for(int i = endCol; i >= startCol; i--){
// 			cout << a[endRow][i] << ", ";
// 		}
// 		endRow--;

// 		for(int i = endRow; i >= startRow; i--){
// 			cout << a[i][startCol] << ", ";
// 		}
// 		startCol++;
// 	}
// }
// int main(int argc, char const *argv[])
// {
// 	int a[12][12] = {0};
// 	int m,n;
// 	cin >> m >> n;
// 	int value = 1;
// 	for(int i = 0; i < m; i++){
// 		for(int j = 0; j < n; j++){
// 			// a[i][j] = value++;
// 			// cout << a[i][j] << " ";
// 			cin >> a[i][j];
// 		}
// 		// cout << '\n';
// 	}
// 	printSpiral(a,m,n);
// 	cout << "END\n";
// 	return 0;
// }


#include <bits/stdc++.h>
using namespace std;
void printSpiral(int a[][12],int m,int n){
	int sr = 0, er = m-1;
	int sc = 0, ec = n-1;

	while(sr <= er && sc <= ec){

		//Print staring row from sc to ec
		for(int i = sc;i <= ec; i++){
			cout << a[sr][i] << " ";
			// cout<<"hey1 ";
		}
		sr++;

		//Print ending column from sr to er
		for(int i = sr; i <= er; i++){
			cout << a[i][ec] << " ";
		}
		ec--;

		//Print er from ec to sc
		if(er >= sr){
			for(int i = ec; i>=sc; i--){
			cout << a[er][i] << " ";
			// cout<<"hey";
		}
		er--;
		}

		//Print sc from er to sr
		if(ec >= sc){
			for(int i = er; i >= sr; i--){
				cout << a[i][sc] << " ";
			}
			sc++;
		}
	}
}
int main(){
	int a[12][12] = {0};
	int m,n;
	cin>>m>>n;
	// int a[m][n];
	int x = 1;
	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
			a[i][j] = x++;
			cout << a[i][j] << " ";
		}
		cout<<endl;
	}
	printSpiral(a,m,n);
	cout<<endl;
}