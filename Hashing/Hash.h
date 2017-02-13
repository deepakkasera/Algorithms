#ifndef HASHTABLE_H
#define HASHTABLE_H
#include <bits/stdc++.h>
using namespace std;

template<typename T>
class HashNode{
public:
	string key;
	T val;
	HashNode<T>* next;

	HashNode(string key,T value){
		this.key = key;
		val = value;
		next = NULL;
	}
	~HashNode(){
		if(next){
			delete next;
		}
	}
};

template<typename T>
class HashTable{
	int currentSize;
	int tableSize;

	HashNode<T>** buckets;

	int hashFunction(string key){
		int ans = 0;
		int power=1;
		int l = key.length();
		for(int i=0;i<l;i++){
			int last = l-i-1;
			ans += key[last]*power;
			ans %= tableSize;
			power = (power*37)%tableSize;
		}
		return ans%tableSize;
	}

	void rehash(){
		int oldTableSize = tableSize;
		tableSize *= 2;
		int oldSize = currentSize;
		currentSize = 0;

		HashNode<T>** oldBuckets = buckets;
		buckets = new HashNode<T>*[tableSize];

		for(int i=0;i<tableSize;i++){
			buckets[i] = NULL;
		}

		for(int i=0;i<oldTableSize;i++){
			if(oldBuckets[i] != NULL){
				HashNode<T>* temp = oldBuckets[i];
				while(temp){
					insert(temp->key,temp->val);
					temp = temp->next;

				}
				delete oldBuckets[i];
			}
		}
		delete [] oldBuckets;
	}

	public:
	HashTable(int size=7){
		currentSize = 0;
		tableSize = size;
		buckets = new HashNode<T>*[tableSize];
		for(int i=0;i<tableSize;i++){
			buckets[i] = NULL;
		}
	}

	void insert(string key,T val){
		int index = hashFunction(key);

		HashNode<T>* node = new HashNode(key,val);
		node->next = buckets[hashFunction(key)];
		buckets[hashFunction(key)] = node;
		currentSize++;

		float laodFactor = (float) currentSize/tableSize;
		if(laodFactor > 0.7){
			rehash();
		}
	}
	void printTable(){
		for(int i=0;i<tableSize;i++){
			cout << "Bucket" << i << "-->";
			if(buckets[i] != NULL){
				HashNode<T>* head = buckets[i]; 
			while(head){
				cout << head->key << "-->";
				head = head->next;
			}
		    }
		cout << endl;
	    }
    }
    T* search(string key){
    	int i = hashFunction(key);
    	if(buckets[i] != NULL){
    		HashNode<T>* temp = new buckets[i];
    		while(temp){
    			if(temp->key == key ){
    				return &(temp->val);
    			}
    			temp = temp->next;
    		}
    	}
    	return NULL;
    }
    void operator[](string key){
    	cout << *search(key) << endl;
    }
};