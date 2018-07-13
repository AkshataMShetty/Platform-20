#include "header.h"

int main (void)
{
	int choice;		//user input
	char *ptr;
	int value;
	int pos;
	int count;

	struct master *mhead = NULL;
	struct master *mnew = NULL;

	if (NULL == (ptr = (char *) malloc (sizeof (char) * MAX))) {
		perror ("Malloc failed");
		free (mhead);
		exit (EXIT_FAILURE);
	}

	while (1) {
		printf ("***MAIN MENU***\n");
		printf ("1. Creation of Lists\n");
		printf ("2. Insert operations\n");
		printf ("3. Delete operations\n");
		printf ("4. Search operations\n");
		printf ("5. Display operations\n");
		printf ("6. Exit\n");
		printf ("Enter your choice: ");

		choice = my_atoi (readinput (ptr));
		printf ("\n");

		switch (choice) {
		case 6:
		{
			my_free (mhead);
			printf ("\n");
			exit (EXIT_FAILURE);
		}
		break;
		
		case 1:
		{
			printf ("***LIST CREATION OPERATIONS***\n");
			printf ("1. Create a CDLL by inserting elements at the beginning\n");
			printf ("2. Create a CDLL by inserting elements at the end\n");
			printf ("Press any key to return to main menu\n");
			printf ("Enter your choiice: ");

			choice = my_atoi (readinput (ptr));
			printf ("\n");

			switch (choice) {
			
			case 1:
			{
				mnew = make_master (ptr);
				printf ("\n");
				if (mnew) {
					if (NULL == mhead) {
						mhead = mnew;
					} else if (mhead -> mnext == mhead && mhead -> mprev == mhead) {
						mhead -> mnext = mnew;
						mnew -> mnext = mhead;
						mhead -> mprev = mnew;
						mnew -> mprev = mhead;
						mhead = mnew;
					} else {
						mnew -> mprev = mhead -> mprev;
						mnew -> mnext = mhead;
						mhead -> mprev -> mnext = mnew;
						mhead -> mprev = mnew;
						mhead = mnew;
					}
				}
			}
			break;
			case 2:
			{
				mnew = make_master (ptr);
				printf ("\n");
				if (NULL == mhead) {
					mhead = mnew;
				} else if (mhead -> mnext == mhead && mhead -> mprev == mhead) {
					mhead -> mnext = mnew;
					mnew -> mnext = mhead;
					mhead -> mprev = mnew;
					mnew -> mprev = mhead;
				} else {
					mnew -> mprev = mhead -> mprev;
					mnew -> mnext = mhead;
					mhead -> mprev -> mnext = mnew;
					mhead -> mprev = mnew;
				}
			}
			break;
			}
		}
		break;

		case 2:
		{
			printf ("***INSERT OPERATIONS***\n");
			printf ("1. Insert a value to a particular list at the beginning of the list\n");
			printf ("2. Insert a value to a particular list at the end of the list\n");
			printf ("3. Insert a value to a particular list after a given value in that list\n");
			printf ("4. Insert a value to a particular list before a given value in that list\n");
			printf ("5. Insert a value to a particular list at a given position\n");
			printf ("Enter your choice: \n");
			choice = my_atoi (readinput (ptr));
			printf ("\n");

			count = count_masters (mhead);
			printf ("Number of lists = %d\n", count);

			switch (choice) {
			case 1:
			{
				if (count > 0) {
					printf ("Enter the list number in which element is to be inserted: ");
					pos = my_atoi (readinput (ptr));

					if (pos <= count) {
						mhead = insert_list_front (mhead, pos, ptr);
					} else {
						printf ("Invalid input\n");
					}
				} else {
					printf ("No lists to insert\n");
				}
			}
			break;
			
			case 2:
			{
				if (count > 0) {
					printf ("Enter the list number in which element is to be inserted: ");
					pos = my_atoi (readinput (ptr));

					if (pos <= count) {
						mhead = insert_list_end (mhead, pos, ptr);
					} else {
						printf ("Invalid input\n");
					}
					//display (mhead);
				} else {
					printf ("No lists to insert\n");
				}
			}
			break;
			
			case 3:
			{
				if (count > 0) {
					printf ("Enter the list number in which element is to be inserted: ");
					pos = my_atoi (readinput (ptr));

					if (pos <= count) {
						fwd_display (mhead, pos);
						printf ("Enter value after which node is to be inserted: ");
						value = my_atoi (readinput (ptr));
						mhead = insert_list_after (mhead, pos, value, ptr);
					} else {
						printf ("Invalid input\n");
					}
					//display (mhead);
				} else {
					printf ("No lists to insert\n");
				}
			}
			break;

			case 4:
			{
				if (count > 0) {
					printf ("Enter the list number in which element is to be inserted: ");
					pos = my_atoi (readinput (ptr));

					if (pos <= count) {
						fwd_display (mhead, pos);
						printf ("Enter value before which node is to be inserted: ");
						value = my_atoi (readinput (ptr));
						mhead = insert_list_before (mhead, pos, value, ptr);
					} else {
						printf ("Invalid input\n");
					}
					display (mhead);
				} else {
					printf ("No lists to insert\n");
				}
			}
			break;

			case 5:
			{
				if (count > 0) {
					printf ("Enter the list number in which element is to be inserted: ");
					pos = my_atoi (readinput (ptr));

					if (pos <= count) {
						fwd_display (mhead, pos);
						printf ("Enter the position at which node is to be inserted: ");
						value = my_atoi (readinput (ptr));
						mhead = insert_list_pos (mhead, pos, value, ptr);
					} else {
						printf ("Invalid input\n");
					}
					display (mhead);
				} else {
					printf ("No lists to insert\n");
				}
			}
			break;
			}
		}
		break;

		case 3:
		{
			if (NULL == mhead) {
				printf ("No lists to delete\n");
				break;
			}
			printf ("***DELETE OPERATIONS***\n");
			printf ("1. Delete a value in a particular list\n");
			printf ("2. Delete a node after a particular value in the list\n");
			printf ("3. Delete a node before a particular value in the list\n");
			printf ("4. Delete first node of a particular list\n");
			printf ("5. Delete last node of a particular list\n");
			printf ("6. Delete node at a given position in a given list\n");
			printf ("7. Delete a given list\n");
			printf ("Enter your choice: ");
			choice = my_atoi (readinput (ptr));
			printf ("\n");

			count = count_masters (mhead);
			printf ("Number of lists = %d\n", count);

			switch (choice) {
			case 1:
			{
				printf ("Enter the list number from which element is to be deleted: ");
				pos = my_atoi (readinput (ptr));
				if (pos <= count) {
					printf ("Enter value to be deleted: ");
					value = my_atoi (readinput (ptr));
					delete_value (&mhead, pos, value);
				} else {
					printf ("Invalid input\n");
				}
			}
			break;

			case 2:
			{
				printf ("Enter the list number from which element is to be deleted: ");
				pos = my_atoi (readinput (ptr));
				if (pos <= count) {
					printf ("Enter value whose succeeding node is to be deleted: ");
					value = my_atoi (readinput (ptr));
					delete_after (&mhead, pos, value);
				} else {
					printf ("Invalid input\n");
				}
			}
			break;

			case 3:
			{
				printf ("Enter the list number from which element is to be deleted: ");
				pos = my_atoi (readinput (ptr));
				if (pos <= count) {
					printf ("Enter value whose preceeding node is to be deleted: ");
					value = my_atoi (readinput (ptr));
					delete_before (&mhead, pos, value);
				} else {
					printf ("Invalid input\n");
				}
			}
			break;

			case 4:
			{

				if (count > 0) {
					printf ("Enter the list number from which element is to be deleted: ");
					pos = my_atoi (readinput (ptr));
					if (pos <= count) {
						delete_front (&mhead, pos);
					} else {
						printf ("Invalid input\n");
					}
				}
			}
			break;

			case 5:
			{

				if (count > 0) {
					printf ("Enter the list number from which element is to be deleted: ");
					pos = my_atoi (readinput (ptr));
					if (pos <= count) {
						delete_end (&mhead, pos);
					} else {
						printf ("Invalid input\n");
					}
				}
				
			}
			break;

			case 6:
			
				{

				if (count > 0) {
					printf ("Enter the list number from which element is to be deleted: ");
					pos = my_atoi (readinput (ptr));
					if (pos <= count) {
						printf ("Enter position at which node is to be deleted: ");
						if ((value = my_atoi (readinput (ptr))) >= 1) {
							delete_at_pos (&mhead, pos, value);
						} else {
							printf ("Invalid input\n");
						}
					} else {
						printf ("Invalid input\n");
					}
				}
			}
			break;

			case 7:
			{
				if (count > 0) {
					printf ("Enter the list number of list to be deleted: ");
					pos = my_atoi (readinput (ptr));
					
					if (pos <= count) {
						free_list (&mhead, pos);
					} else {
						printf ("Invalid input\n");
					}
				}
			}
			break;
			}
		}
		break;

		case 4:
		{
			if (NULL == mhead) {
				printf ("System of lists is empty\n");
				break;
			}
			printf ("***SEARCH OPERATIONS***\n");
			printf("1. Search for value in the list\n");
			printf("2. Search for value in the system\n");
			printf("3. Maximum in a list\n");
			printf("4. Maximum in a system\n");
			printf("5. Minimum in a list\n");
			printf("6. Minimum in a system\n");
			printf("Enter your choice: ");
			choice = my_atoi(readinput(ptr));
			printf ("\n");

			count = count_masters (mhead);
			printf ("Number of lists = %d\n", count);

			switch(choice)
			{
			case 1:
			{
				if (count > 0) {
					printf ("Enter the list number in which element is to be searched: ");
					pos = my_atoi (readinput (ptr));
					if (count >= pos) {
						printf("Enter the value to be searched: ");
						value = my_atoi(readinput (ptr));
						value = search_list_value(mhead, pos, value);

						if (value > 0) {
							printf ("Total occurrences: %d\n", value);
						} else {
							printf ("No occurrences of given value\n");
						}
					} else {
						printf ("Invalid input\n");
					}

				} else {
					printf ("No lists to insert\n");
				}
				
			}
			break;

			case 2:
			{
				printf ("Enter value to be searched: ");
				value = my_atoi (readinput (ptr));
				search_list_system (mhead, value);
			}
			break;

			case 3:
			{
				if (count > 0) {
					printf ("Enter the list number: ");
					pos = my_atoi (readinput (ptr));

					value = list_max (mhead, pos);

					printf ("Maximum value in list %d is %d\n", pos, value);
				}

			}
			break;

			case 4:
			{
				value = system_max (mhead);

				printf ("Maximum value in system is %d\n", value);
			}
			break;

			case 5:
			{
				if (count > 0) {
					printf ("Enter the list number: ");
					pos = my_atoi (readinput (ptr));

					value = list_min (mhead, pos);

					printf ("Minimum value in list %d is %d\n", pos, value);
				}
			}
			break;

			case 6:
			{
				value = system_min (mhead);

				printf ("Minimum value in system is %d\n", value);
			}
			break;
			}
		}
		break;

		case 5:
		{
			if (NULL == mhead) {
				printf ("System of lists is empty\n");
				break;
			}
			printf ("***DISPLAY OPERATIONS***\n");
			printf ("1. Forward Display\n");
			printf ("2. Reverse Display\n");
			printf ("3. System of lists:\n");
			printf ("Press any key to return to main menu\n");
			printf ("Enter your choice: \n");
			choice = my_atoi (readinput (ptr));

			count = count_masters (mhead);
			printf ("Number of lists = %d\n", count);

			switch (choice) {
			case 1:
			{
				printf ("Enter the list number to be displayed:\n");
				pos = my_atoi (readinput (ptr));

				if (pos <= count) {
					fwd_display (mhead, pos);
				} else {
					printf ("Invalid input\n");
				}
			}
			break;

			case 2:
			{
				printf ("Enter the list number to be displayed:\n");
				pos = my_atoi (readinput (ptr));

				if (pos <= count) {
					rev_display (mhead, pos);
				} else {
					printf ("Invalid input\n");
				}
			}
			break;

			case 3:
			{
				if (mhead) {
					display (mhead);
				} else {
					printf ("Empty list\n");
				}
			}
			break;
			}
		}
		break;
		}
	}
	free(ptr);
	return 0;
}
