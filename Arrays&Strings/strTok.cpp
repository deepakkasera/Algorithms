#include <iostream>
#include <cstring>
using namespace std;
int main(int argc, char const *argv[])
{
	char input[100] = "hey, this is something new";
	char* token = strtok(input , " ");
	while(token != NULL){
		cout << token << endl;
		token = strtok(NULL , " ");
	}
	return 0;
}