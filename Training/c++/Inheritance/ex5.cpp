//This program won't compile.

#include <iostream>
using namespace std;

class base {
	protected:
		int i, j; //private to base, but accessible by derived
	public:
		void set(int a, int b){
			i = a;
			j = b;
		}

		void show(){
			cout << i << " " << j << "\n";
		}
};

//Now, all elements of base are private in derived1.
class derived1 : private base{
	int k;
	public:
		//this is legal because i and j are private to derived1
		void setk()
		{
			k = i * j;
		}

		void showk()
		{
			cout << k << "\n";
		}
};

//Access to i, j, set(), and show() not inherited.
class derived2 : public derived1{
	int m;
	public:
		//illegal because i  and j are private to derived1
		void setm() { m = i - j;} //error
		void showm() { cout << m << "\n"; }
};

int main()
{
	derived1 ob1;
	derived2 ob2;

	ob1.set(2, 3); //error
	ob1.show(); //error
	ob1.setk();
	ob1.showk();

	ob2.set(3, 4); //error
	ob2.show(); //error
	ob2.setk();
	ob2.setm();
	ob2.showk();
	ob2.showm();

	return 0;
}
