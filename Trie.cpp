#include <bits/stdc++.h>
using namespace std;
class TrieNode
{
    public:
    	char data ;
    	bool isTerminal ;
    	map<char,TrieNode*> children ;

    TrieNode(char d){
    	data = d;
    	isTerminal =false ;
    }
	
};

class Trie
{
  public:
  	TrieNode* root ;
  	int numberOfWords ;

  Trie(){
  	root = new TrieNode('\0') ;
  	numberOfWords = 0;
  }
  void addWordHelper(char* word,TrieNode* root){
     ///Base Case
     if(word[0] == '\0'){
     	root->isTerminal = true ;
     	return ;
     }
     /// Recursive Case 
     char currentChar = word[0] ;
     TrieNode* child ;
     if(root->children.find("currentChar") == root->children.end()){
     	child =  new TrieNode(currentChar) ;
     	root->children.[currentChar] = child ;
     } 
     else {
     	child = root->children.find(currentChar)->second ;
     }
     addWordHelper(word+1,child) ;
  }
  void addWord(char* word){
    addWordHelper(word,root) ;
  }
  bool searchWord(char* word) {
  	TrieNode* currentNode = root ;
  	for(int i=0 ; word[i] != '\0' ; i++){
  		if(currentNode->children.find(word[i]) == currentNode->children.end()){
  			return false ;
  		}
        currentNode = currentNode->children.find(word[i])->second ;
  	}
  	if(currentNode->isTerminal == true){
  		return true; 
  	}
  	else return false ;
  }
};

int main(int argc, char const *argv[])
{
    int n,m;
    char words[] ;
    char searchWords[] ;
    cin >>n>>m ;
    Trie t ; 
    while(n--){
    	cin>>words ;
        t = new Trie() ;
    }
    while(m--){
    cin>>searchWords ;
    if(searchWord(searchWords)){
    	cout << searchWords << "Found" ;
    }
    else  cout << searchWords << "Not Found" ; 
    }
	return 0;
}