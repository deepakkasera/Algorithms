#include <bits/stdc++.h>
using namespace std;
int calculateMex(set<int> s)
{
	int mex=0;
	while(s.find(mex) != s.end())
		mex++;
	return mex;
}
int calculateGrundy(int n,int *Grundy)
{
	if(n == 0)
		return 0;

	if(Grundy[n] != -1)
		return Grundy[n];

	set<int> s;
	s.insert(calculateGrundy(n/2,Grundy));
	s.insert(calculateGrundy(n/3,Grundy));
	s.insert(calculateGrundy(n/6,Grundy));

	Grundy[n] = calculateMex(s);
	return Grundy[n];
}
int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	int Grundy[n+1];
	memset(Grundy,-1,sizeof(Grundy));
	cout << "Grundy Number " << calculateGrundy(n,Grundy) << endl;
	return 0;
}