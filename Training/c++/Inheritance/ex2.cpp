/**
  *we cannot access base class members 
  *when we give private in the derived class

  *This program gives an error
**/

#include <iostream>
using namespace std;

class base {
	int i,j;
	public:
		void set(int a, int b){
			i = a;
			j = b;
		}

		void show(){
			cout << i << " " << j << "\n";
		}
};

class derived : private base {
	int k;
	public:
		derived(int x){
			k = x;
		}

		void showk(){
			cout << k << "\n";
		}
};

int main()
{
	derived ob(3);

	ob.set(1,2); //access member of base
	ob.show(); //access member of base

	ob.showk(); //uses memeber of derived class

	return 0;
}
