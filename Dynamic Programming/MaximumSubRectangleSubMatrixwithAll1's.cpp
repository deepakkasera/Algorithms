#include <bits/stdc++.h>
using namespace std;
int maximumHistogramArea(std::vector<int> &v,int n){
	int tp,area=0,maxArea=0,i=0;
	stack<int> s;
	while(i < n){
		if(s.empty() || v[s.top()] <= v[i]) 
			s.push(i++);
		else {
			tp = s.top();
			s.pop();
			if(s.empty()){
				area = v[tp]*i;
			}
			else {
				area = v[tp]*(i-s.top()-1);
			}
			if(maxArea < area) maxArea = area;
		}
	}
	while(!s.empty()){
		tp = s.top();
		s.pop();
		if(s.empty())  
			area = v[tp]*i;
		else area = v[tp]*(i-s.top()-1);
		if(maxArea < area) maxArea=area;
	}
	return maxArea;
}
int maximumRectangleSubmatrix(std::vector<std::vector<int> > &v,int rows,int cols){
	std::vector<std::vector<int> > dp(rows,std::vector<int>(cols));
    int ans=0;
    for(int i=0;i<rows;i++){
    	ans = maximumHistogramArea(v[i],cols);
    	for(int j=0;j<cols;j++){
    	    if(i != rows-1){
    	      if(v[i+1][j] == 1) v[i+1][j] += v[i][j];
    	      else continue;
    	    }
    	    else if(i == rows-1){
    	    	if(v[i][j] == 1) v[i][j] += v[i-1][j];
    	    	else continue;
    	    }
    	}
    }
    return ans;
}
int main(int argc, char const *argv[])
{
	int rows,cols;
	cout << "Enter the number of rows and columns \n";
	cin >> rows >> cols ;
	std::vector<std::vector<int> > v(rows,std::vector<int>(cols));
	for(int i=0;i<rows;i++){
		for(int j=0;j<cols;j++){
			cin >> v[i][j] ;
		}
	}
	cout << "Size of the maximum Rectangle is " << maximumRectangleSubmatrix(v,rows,cols) << endl;
	return 0;
}