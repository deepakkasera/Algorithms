#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	int n;
	cin >> n ;
	std::vector<int> v(n);
	for(int i=0;i<n;i++) cin >> v[i];
	int countZeroes = count(v.begin(),v.end(),0);
    int countOnes = n - countZeroes;
    int left[n],right[n];
    std::vector<int> zeroes;
    for(int i=0;i<n;i++)
    	left[i]=right[i]=0;
    int cnt=0,x;
    for(int i=0;i<n;i++){
    	if(v[i] == 1){
    		cnt++;
    		x=i;
    	}
    	else{
    		zeroes.push_back(i);
    		if(x == i-1)
    			left[i] = cnt;
            cnt = 0;    			
    	}
    }
    for(int i=0;i<zeroes.size();i++){
    	if(i+1 < zeroes.size())
    		right[zeroes[i]] = left[zeroes[i+1]];
    	else right[zeroes[i]] = count(v.begin() + zeroes[i], v.end(),1);
    }
    for(int i=0;i<n;i++){
    	cout << left[i] << " " << right[i] ;
    	cout << endl;
    }
    int ans = INT_MIN;
    for(int i=0;i<zeroes.size();i++){
    	ans = max(ans,left[zeroes[i]]+right[zeroes[i]]+1);
    }
    //cout << ans << endl ;
	return 0;
}