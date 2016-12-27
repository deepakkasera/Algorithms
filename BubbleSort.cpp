#include <bits/stdc++.h>
using namespace std;
void bubbleSort(int *arr,int n) 
{
	arr = new int[n];
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(arr[i] < arr[j]) 
				swap(arr[i],arr[j]);
		}
	}
}
int main(int argc, char const *argv[])
{
	int testcases;
	cin >> testcases;
	while(testcases--)
	{
		int n;
		cin >> n;
		int *arr = new int[n];
		for(int i =0;i<n;i++){
			arr[i] = n-i;
		}
		clock_t startTime=0;
		bubbleSort(arr,n);
		clock_t endTime = clock();
		cout <<  endTime - startTime << " for " << n <<endl;
	}
	return 0;
}