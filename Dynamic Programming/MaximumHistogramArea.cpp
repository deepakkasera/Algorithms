#include <bits/stdc++.h>
using namespace std;
//Time Complexity is Size of the O(n)
//Space Complexity is O(n) {Size of the stack}
int maximumHistogram(std::vector<int> &v,int n){
	stack<int> s;
	int area=0,max_area=0;
	int tp;
	int i=0;
	while(i < n){
		if(s.empty() || v[s.top()] <= v[i])
			s.push(i++);
		else {
			tp = s.top();
			s.pop();
			area = v[tp]*(s.empty() ? i : i - s.top() - 1);
			if(max_area < area) max_area = area;
		}
	}
	while(!s.empty()){
		tp = s.top();
		s.pop();
		area = v[tp]*(s.empty() ? i : i - s.top() - 1);
		if(max_area < area) max_area = area;
	}
	return max_area;
}
int main(int argc, char const *argv[])
{
	int n;
	cout << "Enter the number of elements ";
	cin>>n;
	std::vector<int> v(n);
	for(int i=0;i<n;i++) cin >> v[i];
	cout << "Maximum area for the given histogram is " << maximumHistogram(v,n) << "\n"	;
	return 0;
}