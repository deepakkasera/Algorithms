#include <bits/stdc++.h>
using namespace std;
string table[] = { " ", ".+@$", "abc", "def", "ghi", "jkl" , "mno", "pqrs" , "tuv", "wxyz" };
void keypad(char* input,char* output,int i,int j){
    if(input[i] == '\0'){
        output[j] = '\0';
        cout << output << endl;
        return;
    }
    if(input[i] == '0'){
        keypad(input,output,i+1,j);
    }
    int digit = input[i] - '0';
    for(int k = 0; k < table[digit].length(); k++){
        output[j] = table[digit][k];
        keypad(input,output,i+1,j+1);
    }
    return;
}
int main(){
    char input[15];
    cin >> input;
    char output[15];
    keypad(input,output,0,0);
    return 0;
}