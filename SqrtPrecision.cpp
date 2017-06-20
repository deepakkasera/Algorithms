#include<bits/stdc++.h>
using namespace std;
float squareRoot(int n,int p){
    int left = 0;
    int right = n-1;
    int middle;
    float value;
    while(left <= right){
        middle = (left + right)/2;
        if(middle*middle == n){
             value = middle;
             break;
        }
        else if(middle*middle > n){
            right = middle - 1;
        }
        else{
            value = middle;
            left = middle + 1;
        }
    }
    float inc = 0.1;
    for(int i = 1; i <= p; i++){
        while(value*value <= n){
            value += inc;
        }
        value -= inc;
        inc /= 10;
    }
    return value;
}
int main(){
    int n,p;
    cin >> n >> p;
    // int floorValue = squareRoot(n);
    cout << squareRoot(n,p) << endl;
    return 0;
}