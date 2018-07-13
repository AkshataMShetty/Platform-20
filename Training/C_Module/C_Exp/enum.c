#include <stdio.h>

/*enum CyclicPrefixType_t {
		NORMAL = 31414,
		EXTENDED
};
*/
/*void func (enum CyclicPrefixType_t x) {
		printf ("%d\n", x);
}*/

int main (void) {
enum CyclicPrefixType_t {
		NORMAL = 31414,
		EXTENDED
};
		enum CyclicPrefixType_t cpType = EXTENDED;
//		func (cpType);
		printf("bf func\n");	
		void func (enum CyclicPrefixType_t x) {
			printf ("%d\n", x);
		}
		func(cpType);		
		printf("after func\n");
		return 0;
}
