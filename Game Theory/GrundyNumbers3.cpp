#include <bits/stdc++.h>
using namespace std;
int calculateMex(set<int> s)
{
	int mex = 0;
	while(s.find(mex) != s.end())
		mex++;
	return mex;
}
int calculateGrundy(int n)
{
	if(n == 0)
		return 0;

	if(n == 1) 
		return 1;
	
	set<int> s;
	
	s.insert(calculateGrundy(n/2));
	s.insert(calculateGrundy(n/3));
	s.insert(calculateGrundy(n/6));
	
	return calculateMex(s);
}
int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	int Grundy[n+1];
	memset (Grundy, -1, sizeof (Grundy));
	cout << "Grundy Number is " << calculateGrundy(n) << endl;
	return 0;
}