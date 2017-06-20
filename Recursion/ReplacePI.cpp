#include <bits/stdc++.h>
using namespace std;
set<string> st;
set<string>::iterator it;
void replacePI(string s,int i,set<string> &st){
    if(s[i] == '\0'){
        st.insert(s);
        return;
    }
    //Rec case
    if(s[i]=='3'&&s[i+1]=='.'&&s[i+2]=='1'&&s[i+3]=='4'){
        s[i] = 'p';
        s[i+1] = 'i';
        int j = i+4;
        while(s[j] != '\0'){
            s[j-2] = s[j];
            j++;
        }
        replacePI(s.substr(0,s.length()-2),i+2,st);
    }
    else{
        replacePI(s,i+1,st);
    }
}
int main(int argc, char const *argv[])
{
    int n;
    cin>>n;
    while(n--){
        string s;
        cin.ignore();
        getline(cin,s);
        replacePI(s,0,st);
        for(it = st.begin(); it != st.end(); it++){
            cout << *it << endl;
        }
        st.clear();
    // cout << s << endl;
    }
    return 0;
}