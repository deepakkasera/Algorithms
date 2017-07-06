#include <iostream>
#include <stack>
#include <climits>
using namespace std;
int getMaxArea (int a[] , int n) {
	int i = 0 , tp;
	int area = 0;
	int max_area = INT_MIN;
	stack<int> s;
	while (i < n) {
		if (s.empty() || a[s.top()] <= a[i]) {
			s.push(i++);
		}
		else{
			tp = s.top();
			s.pop();
			area = a[tp] * (s.empty() ? i : (i - s.top() - 1));
			max_area = max(max_area , area);
		}
	}
	while(!s.empty()) {
		tp = s.top();
		s.pop();
		area = a[tp] * (s.empty() ? i : (i - s.top() - 1));
		max_area = max(max_area , area);
	}
	return max_area;
}
int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}
	cout << getMaxArea(a,n) << endl;
	return 0;
}