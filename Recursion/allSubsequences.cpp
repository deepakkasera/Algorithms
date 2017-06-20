#include <bits/stdc++.h>
using namespace std;
set<string> st;
set<string>::iterator it;
void allSubseq(char input[],char output[],int i,int j,set<string> &st){
    if(input[i] == '\0'){
        output[j] = '\0';
        string str(output);
        st.insert(output);
        // cout << output << endl;
        return;
    }
    
    //include ith character
    output[j] = input[i];
    allSubseq(input,output,i+1,j+1,st);
    
    //exclude ith character
    allSubseq(input,output,i+1,j,st);
}
int main(){
    int n;
    cin >> n;
    while(n--){
        char input[25];
        char output[25];
        cin >> input;
        allSubseq(input,output,0,0,st);
        for(it = st.begin(); it != st.end(); it++)
            cout << *it << endl;
        st.clear();
    }
    return 0;
}