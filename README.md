# phonebook
An old project I worked on, the program generates a phone book consisting of random names + numbers. 
The user can then search the book for specific first names, last names, or numbers. Written in C++ , utilizes binary search trees. 

Run program with the .exe;

	/* ReadMe
	 *
	 * General Information Regarding this Project:
	 *
	 * This project is a phonebook simulator, it generates people (nodes) with first and last names.
	 * It then assigns them a random phone number.
	 *
	 * 
	 * Each person is created by selecting a name at random from one of the two files included.
	 * (firstnames.txt & lastnames.txt)
	 *
	 * This list of people (nodes) is then entered into an AVL tree where the user can search for
	 * specific enteries (by First/Last name or Phone Number).
	 *
	 * The tree is sorted by last name alphabetically, the print function is an in order print.
	 *
	 * Insertion sort was used for testing the sorted list, the code is unused but still here.
	 *
	 * The search functions are a little hard to test, since the information is random.
	 * The easiest way to test is to print out the avl tree in the program and search for a name from the list
	 * (copy and paste).
	 *
	 * I've also included a log of the console from my testing, it is the TestingExample.txt
	 * this file is not used in the program at all since it is not intended to be.
	 *
	 * Thanks!
	 */