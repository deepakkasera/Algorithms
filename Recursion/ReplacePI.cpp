#include <bits/stdc++.h>
using namespace std;
// set<string> st;
// set<string>::iterator it;
std::vector<string> st;
std::vector<string>::iterator it;
void replacePI(string s,int i,std::vector<string> &st){
    if(s[i] == '\0'){
        st.push_back(s);
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
    cin.ignore();
    while(n--){
        string s;
        getline(cin,s);
        replacePI(s,0,st);
    // cout << s << endl;
    }
    for(it = st.begin(); it != st.end(); it++){
            cout << *it << endl;
    }
    return 0;
}