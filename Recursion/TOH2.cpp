#include<bits/stdc++.h>
using namespace std;
int ans=0;
void tower_of_hanoi(int n,char src,char helper,char dest){
    if(n==0){
        return;
    }
    tower_of_hanoi(n-1,src,dest,helper);
    cout << "Moving ring "<< n << "th from " << src << " to " << dest << endl;
    ans++;
    tower_of_hanoi(n-1,helper,src,dest);
    return;
}
int main(){
    int n;
    cin >> n;
    tower_of_hanoi(n,'T1','T3','T2');
    cout << ans << endl; 
    return 0;
}