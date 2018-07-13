/* When Constructor and Destructor functions are executed */

#include <iostream>
using namespace std;

class base {
	public:
		base() {cout << "Constructing base\n"; }
		~base() {cout << "Destructing base\n"; }
};

class derived: public base{
	public:
		derived() { cout << "constructing derived\n";}
		~derived() { cout << "Destructing derived\n";}
};

int main()
{
	derived ob;

	return 0;
}
