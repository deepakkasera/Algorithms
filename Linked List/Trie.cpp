#include <bits/stdc++.h>
using namespace std;
class TrieNode{
public:
	char data;
	unordered_map<char,bool> m ;
	bool isTerminal;

	TrieNode(char c){
		data = c;
		isTerminal = false;
	}
};
class Trie{
	TrieNode* root;
	Trie(){
		root = new TrieNode('/0');
	}

public:
	void addWord(char* word){
		
	}
};
int main(int argc, char const *argv[])
{
	
	return 0;
}