#include <bits/stdc++.h>
using namespace std;
int squareRoot(int x){
	if(x == 0 || x==1) return x;
	int ans,start=1,end=x;
	while(start <= end){
		int middle = (start+end)/2;
		if(middle*middle == x) return middle;
		else if(middle*middle < x) start = middle+1,ans=middle;
		else if(middle*middle > x) end = middle-1;
	}
	return ans;
}
int cubeRoot(int x){
	if(x == 0 || x == 1) return x;
	int ans,start=1,end=x;
	while(start < end) {
		int middle = (start+end)/2;
		if(middle*middle*middle == x) return middle;
		else if (middle*middle*middle < x){
			start = middle+1;
			ans = middle;
		} 
		else if(middle*middle*middle > x) end = middle-1;
	}
	return ans;
}
int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
    cout << squareRoot(n) << endl;
    cout << cubeRoot(n) <<endl;
	return 0;
}