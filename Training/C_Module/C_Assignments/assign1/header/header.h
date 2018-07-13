#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#define MAX 256

//a macro to test and set a bit position in a number
#define BIT_TS(num,pos) ((num >> pos) & 1) ? num : (1 << pos) ^ num

//a macro getbits (x,p,n) that retuns (left adjusted) n-bit field of x that begins at position p
#define GET_BITS(num,pos,no_of_bits) ((num >> pos) & (~(~0 << no_of_bits)))

//To clear left most set bit in a number
#define CLEAR_LEFTMOST_SETBIT(num) (((num & 1) != 1) ? num : (num ^ 1))

//To set left most cleared bit in a number
#define SET_LEFTMOST_CLEARBIT(num) (((num & 1) != 0) ? num : (num | 1))

//To clear right most set bit in a number
#define CLEAR_RIGHTMOST_SETBIT(num) (((num & 0x80000000) == 0) ? num : (num ^ 0x80000000))

//To set right most cleared bit in a number
#define SET_RIGHTMOST_CLEARBIT(num) (((num & 0x80000000) != 0) ? num : (num | 0x80000000))

//To set bits from bit position ‘s’ to bit position ‘d’ in a given number and clear rest of the bits
#define SET_BIT(num,src_pos,des_pos) ((getbits(num,src_pos,(src_pos - des_pos + 1)) | (~(~0 << (src_pos-des_pos+1)))) << des_pos)

//To clear bits from bit position ‘s’ to bit position ‘d’ in a given number and set rest of the bits
#define CLEAR_BIT(num,src_pos,des_pos) ((num | ~(0)) ^ ((~(~(0) << (src_pos - des_pos +1))) << des_pos))

//To toggle bits from bit position ‘s’ to bit position ‘d’ in a given number
#define TOGGLE_BIT(num,src_pos,des_pos) (num ^ ((~(~(0) << (src_pos - des_pos +1))) << des_pos))

// To find min and max of two number
#define MAXIMUM(res,num1,num2) ((((res >> 31) & 1) == 1) ? num2 : num1)

#define MINIMUM(res,num1,num2)	((((res >> 31) & 1) == 1)? num1 : num2)

//To read input
char* readinput(char*);

//To convert char to integer
int my_atoi(char*);

// To swap the bit values between source and destination
int bit_swap(unsigned int,int,int);

//To convert the decimal to binary
int dec_to_bin(int);

//swap the bit values between source in snum and destination in dnum
int bit_swap2(unsigned int,unsigned int,int,int);

//To toggle even bit
int even_bit_toggle(unsigned int);

//To toggle odd bits
int odd_bit_toggle(unsigned int);

//o count set bit 
int count_bit_set(int);

//To count clear bit
int count_bit_clear(int);

//Program to rotate left
int left_rotate_bits(unsigned int);

//Program to rotate right
int right_rotate_bits(unsigned int);

//Program to rotate left by n bits
int left_rotate_n_bits(unsigned int ,int );

//Program to rotate right by n bits
int right_rotate_n_bits(unsigned int,int );

//To count leading set bit 
int cnt_leading_set_bits(int);

//To count leading cleared bits
int cnt_leading_cleared_bits(int);

//To count trailing cleared bits
int cnt_trailing_cleared_bits(int);

//To count trailing set bits
int cnt_trailing_set_bits(int);

//To copy n bits from from bit position s in snum to bit position d in dnum
int bit_copy(unsigned int,unsigned int,int,int,int);

//To get n bits right adjusted
int getbits(unsigned int,int,int);

//to set bit
int setbit(unsigned int,int,int,unsigned int);

//To invert n bits from postion p in a given number
int invert(unsigned int,int,int);

//to validate int
void validateInt(unsigned int );

//swap the bit values between source in snum and destination in dnum
int swap_bit(unsigned int,unsigned int,int,int);

