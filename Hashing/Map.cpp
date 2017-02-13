#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	std::map<string,int> m;
	m["apple"] = 100;
	m.insert(make_pair("pineapple",150));
	m.insert(make_pair("orange",110));
	m.insert(make_pair("pine",140));
	m.insert(make_pair("pear",180));
	std::map<string,int>::iterator it;
	for(it=m.begin();it!=m.end();it++){
		cout << it->first << " " << it->second << endl; 
	}
	if (m.count("pine") > 0){
		cout << "pine is present\n";
	}
	else{
		cout << "pine not present\n";
	}
	string fruit;
	cout << "Enter the fruit to be searched\n";
	cin >> fruit;
	if(m.count(fruit) > 0){
		cout << fruit << " is present " << "and the price is " << m[fruit] << endl;
	}
	else cout << fruit << " not present\n";
	m.erase("apple");
	cout << "Map after removing apple is \n";
	for(it=m.begin();it!=m.end();it++){
		cout << it->first << " " << it->second << endl; 
	}
	return 0;
}