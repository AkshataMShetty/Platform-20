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

class derived1 : public base{
	int k;
	public:
		//derived may access base's i nad j
		void setk()
		{
			k = i * j;
		}

		void showk()
		{
			cout << k << "\n";
		}
};

class derived2 : public derived1{
	int m;
	public:
		void setm() { m = i - j;}
		void showm() { cout << m << "\n"; }
};

int main()
{
	derived1 ob1;
	derived2 ob2;

	ob1.set(2, 3); //OK, known to derived
	ob1.show(); //OK, known to derived
	ob1.setk();
	ob1.showk();

	ob2.set(3, 4); //OK, known to derived
	ob2.show(); //OK, known to derived
	ob2.setk();
	ob2.setm();
	ob2.showk();
	ob2.showm();

	return 0;
}
