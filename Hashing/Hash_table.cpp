#include <bits/stdc++.h>
#include "Hash.h"
using namespace std;
int main(int argc, char const *argv[])
{
	HashTable<int> h(13);
	h.insert("apple",10);
	h.insert("mango",50);
	h.insert("guava",70);
	h.insert("orange",80);
	h.insert("papaya",10);
	h.insert("pineapple",100);

	return 0;
}