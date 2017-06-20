#include <bits/stdc++.h>
using namespace std;
void func(char input[],int i){
	if(input[i] == '\0'){
		cout << input << endl;
		return;
	}
	//Recursive Case
	if(input[i]=='3'&&input[i+1]=='.'&&input[i+2]=='1'&&input[i+3]=='4'){
		int j=i+4;
		input[i] = 'p';
		input[i+1] = 'i';
		while(input[j] != '\0'){
			input[j-2] = input[j];
			j++;
		}
		input[j-2] = '\0';
		func(input,i+2);
	}
	else{
		func(input,i+1);
	}
}
int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	while(n--){
		char input[25];
		cin.ignore();
		cin.getline(input,22);
		func(input,0);
	}
	return 0;
}