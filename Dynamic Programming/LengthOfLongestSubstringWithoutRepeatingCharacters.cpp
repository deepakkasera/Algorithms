#include <bits/stdc++.h>
#define MAX 256
using namespace std;
int function(string str){
	int curr_len = 1,prev_index;
	int n = str.length();
	int max_len = 1;
	std::vector<int> visited(MAX);
	for(int i=0;i<MAX;i++)
		visited[i]=-1;
	visited[str[0]] = 0;
	for(int i=1;i<n;i++){
		prev_index = visited[str[i]];
		if(prev_index == -1 || i - curr_len > prev_index){
			curr_len++;
		}
		else{
			if(max_len < curr_len)
				max_len = curr_len ;
			
			curr_len = i - prev_index;
		}
		visited[str[i]] = i ; 
	}
	max_len = max(curr_len,max_len);
	return max_len;
}
int main(int argc, char const *argv[])
{
	int t;
	cin >> t;
	string str;
	while(t--){
		cin >> str ;
		cout << function(str) << endl; 
	}
	return 0;
}