#include <bits/stdc++.h>
using namespace std;
void towerOfHanoi(int n,char src,char helper,char dest)
{
	//Base Case
	if(n == 0)
		return;

	//Recursive Case
	towerOfHanoi(n-1,src,dest,helper);
	cout << "Move " <<  n << "th disk from " << src << " to " << dest << endl;
	towerOfHanoi(n-1,helper,src,dest);
}
int main(int argc, char const *argv[])
{
	int n;
	cout << "Enter number of disks\n";
	cin >> n;
	towerOfHanoi(n,'A','B','C');
	string s;
	cout << "Enter a string\n";
	cin.ignore();
	getline(cin,s);
	cout << s << endl;
	return 0;
}