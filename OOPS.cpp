#include <iostream>
using namespace std;
class Room{
	int length;
	int width;
public:
	Room(){
		length = 0;
		width = 0;
	}

	Room(int val = 8){
		length = val;
		width = val;
	}

	void display(){
		cout << length << " " << width << endl;
	}
};
int main(int argc, char const *argv[])
{
	Room obj (10);
	obj.display();
	// Room obj2(12,8);
	return 0;
}