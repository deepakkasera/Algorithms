#include <bits/stdc++.h>
using namespace std;
class Student{
	static int count;
	string name;

public:
	void addStudent(string name){
		this->name = name;
		count++;
	}

	void showDetails(){
		cout << "Student name is " << name << endl;
		cout << "Total Student " << count << endl;
	}
};
int Student::count;
int main(int argc, char const *argv[])
{
	Student s1,s2;
	s1.addStudent("deepak");
	s1.showDetails();
	s2.addStudent("abc");
	s2.showDetails();
	return 0;
}