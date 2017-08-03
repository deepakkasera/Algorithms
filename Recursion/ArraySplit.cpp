#include <bits/stdc++.h>
#include <cstring>

using namespace std;
std::stringstream ss;
void arrayEqualSplit(int a[],int n,int si,string s1,string s2,int sg1,int sg2)
{
	if(si==n){
		if(sg1==sg2){
			cout << s1 << " & " << s2 <<endl;
			return ; 
		}
	}
	arrayEqualSplit(a,n,si + 1,s1 + std::to_string(a[si]) + ", " , s2,sg1 + a[si] , sg2);

	arrayEqualSplit(a,n,si + 1,s1, s2 + std::to_string(a[si]) + ", ", sg1 , sg2 + a[si]);
}
int main(int argc, char const *argv[])
{
	int a[] = {1,2,3,4};
	int n = sizeof(a)/sizeof(a[0]);
	string s1 = "";
	string s2 = "";
	arrayEqualSplit(a,n,0,s1,s2,0,0);
	return 0;
}