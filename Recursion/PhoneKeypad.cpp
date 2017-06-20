#include<iostream>
#include<cstring>
using namespace std;

string s[] = {"","","ABC","DEF","GHI"};

void phoneKeypad(char *input,char *output,int i,int j){
    if(input[i]=='\0'){
        output[j]='\0';
        cout<<output<<endl;
        return;
    }
    if(input[i]=='1'||input[i]=='0'){
        phoneKeypad(input,output,i+1,j);
    }
    ///Some Possiblities
    int digit = input[i]-'0';
    for(int k=0;k<s[digit].length();k++){
        output[j] = s[digit][k];
        phoneKeypad(input,output,i+1,j+1);
    }

}

int main(){

    char input[10];
    cin>>input;

    char output[10];

    phoneKeypad(input,output,0,0);


return 0;
}