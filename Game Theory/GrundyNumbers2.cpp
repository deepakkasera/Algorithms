#include <bits/stdc++.h>
using namespace std;
int calculateMex(set<int> s)
{
	int Mex = 0;

	while(s.find(Mex) != s.end())
		Mex++;
	
	return Mex;
}
int calculateGrundy(int n)
{
	if(n == 0)
		return 0;
	if(n == 1)
		return 1;
	if(n == 2)
		return 2;
	if(n == 3)
		return 3;
	set<int> s;
	for(int i=1;i<=3;i++){
		s.insert(calculateGrundy(n-i));
	}
	return calculateMex(s);
}
int main(int argc, char const *argv[])
{
	int n;
	cout << "Enter the value of n\n";
	cin >> n;
	cout << "Grundy Number is " << calculateGrundy(n) << endl;
	return 0;
}