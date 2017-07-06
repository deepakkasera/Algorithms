#include <bits/stdc++.h>
using namespace std;

class TrieNode
{
public:
	char data;
	bool isTerminal;
	unordered_map<char,TrieNode*> m;

	//Constructor
	TrieNode(char d) {
		data = d;
		isTerminal = false;
	}

};

class Trie{
public:
	TrieNode* root;
	
	Trie() {
		root = new TrieNode('\0');
	}

	void addWord(char *word){
		TrieNode* temp = root;

		for(int i = 0; word[i] != '\0'; i++){
			char ch = word[i];
			auto it = temp->m.find(ch);
			if(it == temp->m.end()){
				TrieNode* childNode = new TrieNode(ch);
				temp->m[ch] = childNode;
				temp = childNode;
			}
			else{
				temp = it->second;
			}
		}
		temp->isTerminal = true;
	}
	
	bool search(char *word){
		TrieNode* temp = root;
		for(int i = 0; word[i] != '\0'; i++){
			char ch = word[i];
			auto it = temp->m.find(ch);
			if(it == temp->m.end()){
				return false;
			}
			else{
				temp = it->second;
			}
		}
		return temp->isTerminal;
	}

};

int main(int argc, char const *argv[])
{
	char words[][10] = {"apple" , "ape" , "no" , "not" , "news"};
	char searchWords[][10] = {"ape" , "not" , "new" , "nots" , "mango" , "abc"};
	
	Trie t;
	for(int i = 0; i < 5; i++){
		t.addWord(words[i]);
	} 
	
	// cout << searchWords[0] << endl;
	for(int i = 0; i <6; i++){
		if(t.search(searchWords[i])){
			cout << searchWords[i] << " FOUND\n";
		}
		else{
			cout << searchWords[i] << " NOT FOUND\n";
		}
	}

	return 0;
}