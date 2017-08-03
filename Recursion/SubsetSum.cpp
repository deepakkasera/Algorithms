#include <bits/stdc++.h>

using namespace std;
std::vector<std::vector<int> > subsetSum(int a[],int n,int si,int target,int currentSum)
{

	std::vector<std::vector<int> > myResult;

	if(si == n){
		if(currentSum == target){
			std::vector<std::vector<int> > v;
			std::vector<int> x;
			v.push_back(x);

			return v;
		}
		else{
			std::vector<std::vector<int> > v;

			return v;
		}
	}


	//exclude

	std::vector<std::vector<int> > exc = subsetSum(a,n,si+1,target,currentSum);

	for(auto i : exc){
		myResult.push_back(i);
	}

	//include

	std::vector<std::vector<int> > inc = subsetSum(a,n,si+1,target,currentSum+a[si]);

	for(auto i : inc){
		i.push_back(a[si]);

		myResult.push_back(i);
	}

	return myResult;


}
int main(int argc, char const *argv[])
{
	int a[] = {1,2,3,4,5};
	int n  = sizeof(a)/sizeof(int);
	std::vector<std::vector<int> > v;
	std::vector<int>::iterator it;
	v = subsetSum(a,n,0,5,0);
	for(int i  = 0; i < v.size(); i++){
		for(it = v[i].begin(); it != v[i].end(); it++){
			cout << *it << ",";
		}
		cout << endl;
	}
	return 0;
}