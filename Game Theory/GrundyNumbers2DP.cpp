#include <bits/stdc++.h>
using namespace std;
int calculateMex(set<int> s)
{
	int Mex = 0;
	while(s.find(Mex) != s.end())
		Mex++;
	return Mex;
}
int calculateGrundy(int n,int grundy[])
{
	if(n == 0) 
		return 0;
	if(n == 1)
		return 1;
	if(n == 2)
		return 2;
	if(n == 3)
		return 3;
	if(grundy[n] != -1)
		return grundy[n];

	set<int> s;
	for(int i=1;i<=3;i++){
		s.insert(calculateGrundy(n-i,grundy));
	}
	grundy[n] = calculateMex(s);
	return grundy[n];
}
int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	int grundy[n+1];
	memset (grundy, -1, sizeof (grundy));
	cout << "Grundy Number is " << calculateGrundy(n,grundy) << endl;
	return 0;
}