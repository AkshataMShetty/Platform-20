#include"header.h"

int main(void)
{
	char *ptr = NULL;
	int choice;
	int num;
   	int res1;
	unsigned int snum;
    unsigned int dnum;
    int src_pos;
    int des_pos;
	int pos;
	int no_of_bit;

	if(NULL == (ptr = (char*)malloc(sizeof(char)))){
		perror("buffer is full");
		exit(EXIT_FAILURE);
	}
	
	while(1){
		printf("1.program to swap source and detination bit in number\n");
		printf("2.program to swap specified bit between numbers\n");
		printf("3.To copy the bit from snum to dnum\n");
		printf("4.To toggle even or odd bits\n");
		printf("5.To test and set a bit position in a number\n");
		printf("6.To rotate left or right\n");
		printf("7.To count bit set and bit clear\n");
		printf("8.To count leading or trailing set bit\n");
		printf("9.macro using bitwise operation \n");
		printf("10.To set a bit\n");
		printf("11.program to invert bit\n");
		printf("12.program to getbit left adjusted\n" 
		"13.exit\n");
		printf("enter the choice\n");   
    	choice = my_atoi(readinput(ptr));
		validateInt(choice);
		switch(choice){
			case 1:
					printf("enter the input\n");
					num = my_atoi(readinput(ptr));
					validateInt(num);

					printf("enter the source\n");
					snum = my_atoi(readinput(ptr));
					validateInt(snum);

					printf("enter the destination\n");
					dnum = my_atoi(readinput(ptr));
					validateInt(dnum);

					printf("number to be swapped:");
					dec_to_bin(num);

					res1 = bit_swap(num,snum,dnum);

					printf("swapped bit:");
					dec_to_bin(res1);

					break;
		
			case 2:
					printf("enter the first number\n");
					snum = my_atoi(readinput(ptr));
					validateInt(snum);

					printf("enter the second number\n");
					dnum = my_atoi(readinput(ptr));
					validateInt(dnum);

					printf("enter source position\n");
					src_pos = my_atoi(readinput(ptr));
					validateInt(src_pos);

					printf("enter destination position\n");
                	des_pos = my_atoi(readinput(ptr));
					validateInt(des_pos);

					printf("source number :");
					dec_to_bin(snum);
					printf("destination number:");
					dec_to_bin(dnum);
					
					swap_bit(snum,dnum,src_pos,des_pos);	
			
					break;
		
			case 3:
					printf("enter source number\n");
					snum = my_atoi(readinput(ptr));
					validateInt(snum);

					printf("enter destination number\n");
					dnum = my_atoi(readinput(ptr));
					validateInt(dnum);

					printf("enter the number of bits\n");
					num = my_atoi(readinput(ptr));
					validateInt(num);

					printf("enter the src_pos\n");
					src_pos = my_atoi(readinput(ptr));
					validateInt(src_pos);

					printf("enter the des_pos\n");
					des_pos = my_atoi(readinput(ptr));
					validateInt(des_pos);


					printf("source number:");               
                	dec_to_bin(snum);
                	printf("destination number \n");                
                	dec_to_bin(dnum);

					res1 = bit_copy(snum,dnum,num,src_pos,des_pos);
				
					printf("after bitcopy\n");
					printf("source number:");
					dec_to_bin(snum);
					printf("destination number \n");
					dec_to_bin(res1);
								
					break;
		
			case 4: printf("1.even_bit_toggle\n");
					printf("2.odd_bit_toggle\n");
					printf("enter your choice\n");
					choice = my_atoi(readinput(ptr));
					validateInt(choice);

					switch(choice){
						case 1:
								printf("enter a number\n");
								num = my_atoi(readinput(ptr));
								validateInt(num);

								res1 = even_bit_toggle(num);
				
								printf("before toggle: ");
								dec_to_bin(num);
								printf("after toggle: ");
								dec_to_bin(res1);
							
								break;
						case 2:
								printf("enter a number\n");
								num = my_atoi(readinput(ptr));
								validateInt(num);

								res1 = odd_bit_toggle(num);
							
								printf("before toggle:");
								dec_to_bin(num);
                            	printf("after toggle:");
								dec_to_bin(res1);
							
								break;
						default:printf("invalid input\n");
					}
					break;
		
			case 5:
					printf("enter a number\n");
					num = my_atoi(readinput(ptr));
					validateInt(num);

					printf("enter the position to be tested\n");
					pos = my_atoi(readinput(ptr));
                	validateInt(pos);

					printf("before setting a bit :");
					dec_to_bin(num);

					res1 = BIT_TS(num,pos);

					printf("after setting a bit :");
					dec_to_bin(res1);
				
					break;

			case 6:
					printf("1.rotate bits to left\n");
					printf("2.rotate bits to right\n");
					printf("3.rotate bits to left by n bits.\n");
					printf("4.rotate bits to right by n bits\n");
					printf("enter your choice\n");
					choice = my_atoi(readinput(ptr));
					validateInt(choice);

					switch(choice){
						case 1:
								printf("enter a number\n");
								num = my_atoi(readinput(ptr));
								validateInt(num);

								printf("before left rotating:");
                            	dec_to_bin(num); 

								res1 = left_rotate_bits(num);
																				
           						printf("after left rotating:");
								dec_to_bin(res1);		
							
								break;
						case 2:
								printf("enter a number\n");
								num = my_atoi(readinput(ptr));
								validateInt(num);

								printf("before right rotating:");
								dec_to_bin(num);
							
								res1 = right_rotate_bits(num);
							
								printf("after right rotating:");
								dec_to_bin(res1);
							
								break;
						case 3:
								printf("enter a number\n");
                            	num = my_atoi(readinput(ptr));
								validateInt(num);

								printf("enter the number of bits to be rotated\n");
								pos = my_atoi(readinput(ptr));
								validateInt(pos);
						
								printf("before left rotatin:");
								dec_to_bin(num);
                            
								res1 = left_rotate_n_bits(num,pos);
                            
								printf("after left rotating:");
								dec_to_bin(res1);
                           
                            	break;
						case 4:
								printf("enter a number\n");
                            	num = my_atoi(readinput(ptr));
								validateInt(num);


                            	printf("enter the number of bits to be rotated\n");
                            	pos = my_atoi(readinput(ptr));
                            	validateInt(pos);

								printf("before right rotating:");
								dec_to_bin(num);

                            	res1 = right_rotate_n_bits(num,pos);
                            
								printf("after right rotating:"); 
								dec_to_bin(res1);

                            	break;
						default :printf("invalid input\n");

 					}

					break;
		
			case 7:
					printf("1.to count bit set\n");
					printf("2.to count bit clear\n");
					printf("enter your choice\n");
					choice = my_atoi(readinput(ptr));
					validateInt(choice);

					switch(choice){
						case 1:
								printf("enter a number\n");
								num = my_atoi(readinput(ptr));
								validateInt(num);
		
								res1 = count_bit_set(num);
							
								printf("count of bitset = %d\n",res1);
								break;
						case 2:
								printf("enter a number\n");
                            	num = my_atoi(readinput(ptr));
								validateInt(num);

								res1 = count_bit_clear(num);

								printf("count of bitclear = %d\n",res1);
								break;
						default: printf("invalid input\n");
					}
					break;
			case 8:
					printf("1.To count the number of leading set bit.\n");
					printf("2.To count the number of leading clear bit.\n");
					printf("3.To count the number of trailing cleared bit.\n");
					printf("4.To count number of trailing set bit.\n");
					printf("Enter your choice\n");
					choice = my_atoi(readinput(ptr));
					validateInt(choice);

					switch(choice){
						case 1:
								printf("enter a number\n");
								num = my_atoi(readinput(ptr));
								validateInt(num);

								res1 = cnt_leading_set_bits(num);
		
								printf("number of leading set bit = %d\n",res1);
							
								break;
						case 2:
								printf("enter a number\n");
                            	num = my_atoi(readinput(ptr));
								validateInt(num);

                            	res1 = cnt_leading_cleared_bits(num);

                            	printf("number of leading cleared bit = %d\n",res1);

                            	break;
						case 3:
								printf("enter a number\n");
                        	    num = my_atoi(readinput(ptr));
								validateInt(num);

                            	res1 = cnt_trailing_cleared_bits(num);

                            	printf("number of trailing cleared bit = %d\n",res1);

                            	break;
						case 4:
								printf("enter a number\n");
                            	num = my_atoi(readinput(ptr));
								validateInt(num);

                            	res1 = cnt_trailing_set_bits(num);

                            	printf("number of trailing set bit = %d\n",res1);

                            	break;
						default:printf("invalid input\n");
				}
				break;

			case 9:
					printf("1.To find maximum and minimum of two number\n");
					printf("2.To clear rightmost setbit in a number\n");
					printf("3.To clear leftmost setbit in a number\n");
					printf("4.To set rightmost cleared bit in a number\n");
					printf("5.To set leftmost cleared bit in a number\n");
					printf("6.To set bit from position 's' to 'd' in a number\n");
					printf("7.To clear bit from position 's' to 'd' in a number\n");
					printf("8.To toggle bit from position 's' to 'd' in a number\n");
					printf("enter the choice \n");
					choice = my_atoi(readinput(ptr));
					validateInt(choice);

					switch(choice){
						case 1:
								printf("enter the input1\n");
								snum = my_atoi(readinput(ptr));
								validateInt(snum);

								printf("enter the input2\n");
								dnum = my_atoi(readinput(ptr));
								validateInt(dnum);

								res1 = snum - dnum;

								printf("maximum number is = %d \n",MAXIMUM(res1,snum,dnum));
								printf("minimum number is = %d \n", MINIMUM(res1,snum,dnum));
								break;
						case 2:
								printf("enter the input\n");
								num = my_atoi(readinput(ptr));
								validateInt(num);

								printf("before rightmost setbit\n");
								dec_to_bin(num);

								res1 = CLEAR_RIGHTMOST_SETBIT(num);

								printf("cleared rightmost setbit:");
								dec_to_bin(res1);
								break;
						case 3:
								printf("enter the input\n");
                            	num = my_atoi(readinput(ptr));
								validateInt(choice);

								printf("before leftmost setbit:");
								dec_to_bin(num);

								res1 = CLEAR_LEFTMOST_SETBIT(num);

								printf("cleared leftmost setbit:");
								dec_to_bin(res1);
								break;
						case 4:
								printf("enter the input\n");
								num = my_atoi(readinput(ptr));
								validateInt(num);

								printf("before rightmost setbit:");
								dec_to_bin(num);

								res1 = SET_RIGHTMOST_CLEARBIT(num); 

								printf("after rightmost setbit:");
								dec_to_bin(res1);
								break;
						case 5:
								printf("enter the input\n");
								num = my_atoi(readinput(ptr));
								validateInt(num);

								printf("befor leftmost setbit:");
								dec_to_bin(num);

								res1 = SET_LEFTMOST_CLEARBIT(num);

								printf("after leftmost setbit");
								dec_to_bin(res1);
								break;
						case 6:
								printf("enter the input\n");
								num = my_atoi(readinput(ptr));
								validateInt(num);

								printf("enter the source position\n");
								src_pos = my_atoi(readinput(ptr));
								validateInt(src_pos);

								printf("enter the destination position\n");
								des_pos = my_atoi(readinput(ptr));
								validateInt(des_pos);

								printf("before set bit:");
								dec_to_bin(num);

								res1 = SET_BIT(num,src_pos,des_pos);
	
								printf("after set bit:");
								dec_to_bin(res1);
								break;
						case 7:
								printf("enter the input\n");
								num = my_atoi(readinput(ptr));
								validateInt(num);

								printf("enter the source position\n");
								src_pos = my_atoi(readinput(ptr));
								validateInt(src_pos);

								printf("enter the destination position\n");
								des_pos = my_atoi(readinput(ptr));
								validateInt(des_pos);

								printf("before clearbit:");
								dec_to_bin(num);
			
								res1 = CLEAR_BIT(num,src_pos,des_pos);

								printf("after clearbit:");
								dec_to_bin(res1);
								break;
						case 8:
								printf("enter the input\n");
								num = my_atoi(readinput(ptr));
								validateInt(num);

								printf("enter the source position\n");
								src_pos = my_atoi(readinput(ptr));
								validateInt(src_pos);

								printf("enter the destination position\n");
								des_pos = my_atoi(readinput(ptr));
								validateInt(des_pos);

								printf("before toggle:");
								dec_to_bin(num);

								res1 =  TOGGLE_BIT(num,src_pos,des_pos);

								printf("after toggle:");
								dec_to_bin(res1);
								break;
		
						default :
								printf("invalid input\n");
								break;
					}
					break;	
			case 10:
					printf("enter first input\n");
					snum = my_atoi(readinput(ptr));
					validateInt(snum);

					printf("enter the second input\n");
					dnum = my_atoi(readinput(ptr));
					validateInt(dnum);

					printf("enter the the source position\n");
					src_pos = my_atoi(readinput(ptr));
					validateInt(src_pos);

					printf("enter the number of bits");
					no_of_bit = my_atoi(readinput(ptr));
					validateInt(no_of_bit);

					printf("source number before setbit:");
					dec_to_bin(snum);

					res1 = setbit(snum,src_pos,no_of_bit,dnum);

					printf("source number after setbit:");
					dec_to_bin(res1);
					break;

			case 11:
					printf("enter the input\n");
					num = my_atoi(readinput(ptr));
					validateInt(num);

					printf("enter the position\n");
					pos = my_atoi(readinput(ptr));
					validateInt(pos);

					printf("enter the number of bits\n");
					no_of_bit = my_atoi(readinput(ptr));
					validateInt(no_of_bit);

					printf("before inverting:");
					dec_to_bin(num);

					res1 = invert(num,pos,no_of_bit);
	
					printf("after inverting:");
					dec_to_bin(res1);

					break;

			case 12:
					printf("enter the input\n");
                	num = my_atoi(readinput(ptr));
					validateInt(num);

                	printf("enter the position\n");
                	pos = my_atoi(readinput(ptr));
					validateInt(pos);

                	printf("enter the number of bits\n");
                	no_of_bit = my_atoi(readinput(ptr));
					validateInt(no_of_bit);

					res1 = GET_BITS(num,pos,no_of_bit);

					printf("bits :");
					dec_to_bin(res1);
					break;
		
			case 13: exit(EXIT_FAILURE);
 		
			default:printf("invlid input\n");
		}		
  	}
}
