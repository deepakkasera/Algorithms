#include <bits/stdc++.h>
using namespace std;
//Iterative approach for Binary Search
int binarySearchIterative(int a[],int n,int item){
	int left=0;
	int right=n-1;
	while(left<=right){
    int middle=(left+right)/2;
    if(item<a[middle]) 
    	right=middle-1;
    else if(item>a[middle])
    	left=middle+1;
    else return middle;
    }
    return -1;
}
//Recursive approach for Binary Search
int binarySearchRecursive(int a[],int left,int right,int item){
    int middle=(left+right)/2;
    if(left>right)  return -1;
    if(item == a[middle])  return middle;
    else if(item < a[middle])  return binarySearchRecursive(a,left,middle-1,item);
    else return binarySearchRecursive(a,middle+1,right,item);
}
//Finding first occurence of an element in a sorted array 
int firstOccurence(int a[],int n,int item){
    int left=0;
    int right=n-1;
    int result=-1;
    while(left<=right){
    int middle=(left+right)/2;
    if(item==a[middle]){
        result=middle;
        right=middle-1;
    }
    else if(item<a[middle]) 
        right=middle-1;
    else if(item>a[middle])
        left=middle+1;
    }
    return result;   
}
//Finding last occurence of an element in a sorted array
int lastOccurence(int a[],int n,int item){
    int left=0;
    int right=n-1;
    int result=-1;
    while(left<=right){
    int middle=(left+right)/2;
    if(item==a[middle]){
        result=middle;
        left=middle+1;
    }
    else if(item<a[middle]) 
        right=middle-1;
    else if(item>a[middle])
        left=middle+1;
    }
    return result;   
}
//Count number of occurences of an element in sorted array (Linear Search) O(n)
int countOccurencesLinear(int a[],int n,int item){
     int count=0;
     for(int i=0;i<n;i++)
        if(a[i]==item) count++;
     return count;
}
//Count number of occurences of an element in sorted array (Binary Search) O(logn)
int countOccurencesBinary(int a[],int n,int item){
   int i=firstOccurence(a,n,item);
   int j=lastOccurence(a,n,item);
   return j-i+1;
}
int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
	int n,x;
	cin>>n;
	int a[n];
	cout<<"Enter a sorted array";
	for(int i=0;i<n;i++)  cin>>a[i];
    cout<<"Enter the number u want to search";
    cin>>x;
    cout<<binarySearchIterative(a,n,x)<<"\n";
    cout<<binarySearchRecursive(a,0,n-1,x )<<"\n";
    cout<<"First occurence of item x is ";
    cout<<firstOccurence(a,n,x)<<"\n";
    cout<<"last occurence of item x is ";
    cout<<lastOccurence(a,n,x)<<"\n";
    cout<<x<<" occurs "<<countOccurencesLinear(a,n,x)<<" times\n";
	cout<<x<<" occurs "<<countOccurencesBinary(a,n,x)<<" times";
    return 0;
}
