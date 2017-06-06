#include <bits/stdc++.h>
using namespace std;
int calculateMex(set <int> s)
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
	set <int> s;

	for(int i=1;i<=n;i++){
		s.insert(calculateGrundy(n-i));
	}
	return calculateMex(s);
}

int main(int argc, char const *argv[])
{
	int n;
	cout << "Enter the value of n\n";
	cin >> n;
	cout << "Grundy number of "<<  n  << " is " << calculateGrundy(n) << endl;
	return 0;
}