#include <bits/stdc++.h>
using namespace std;
void modularExponentiation(long long a,long long b,long long c){    //O(logb)
	long long ans=1;
	while(b != 0){
		if( b%2 == 1)   ans=(ans*a)%c;
		a=(a*a)%c;
		b = b/2;
	}
	cout<<ans;
}
void naiveApproach(long long a,long long b,long long c){              //O(b)
	long long ans=1;
	for(long long j=0;j<b;j++){
		ans*=a;
		ans%=c;
	}
	cout<<ans;
}
int main(int argc, char const *argv[])
{
	long long a,b,c;
	cin>>a>>b>>c;
	modularExponentiation(a,b,c);
	return 0;
}