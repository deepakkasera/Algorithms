#include <bits/stdc++.h>
using namespace std;
long long int sum(long long int n){
  if(n == 0) return 0;
  return (n%10 + sum(n/10));
}
long long int sumString(string s){
  int len = s.length();
  long long int sum=0;
  if(len == 0) return 0;
  for(int i=0;i<len;i++)
    sum += (s[i]-'0');
  return sum ;
}
int main(){
  string s;
  int k;
  cin >> s >> k ;  
  long long int ans = k * sumString(s);
  while(ans/10 != 0){
    ans = sum(ans);
  }
  cout << ans << endl ;
  return 0;
}