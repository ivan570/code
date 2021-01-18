// casting
#include <iostream>

class parent {
public:
	void whoAmI() {
		std::cout << "i am parent" << std::endl;
	}
	virtual ~parent() = default;
};

class son : public parent {
public:
	void whoAmI() {
		std::cout << "i am son" << std::endl;
	}
	virtual ~son() = default;

};

class daugther : public parent {
public:
	void whoAmI() {
		std::cout << "i am daugther" << std::endl;
	}
	virtual ~daugther() = default;

};

int main() {

	parent* mom = new daugther();
	/*
	*
	*	do work
	*	faltu work
	*	Tutorialskeyboard_arrow_down
Studentkeyboard_arrow_down
Courses
Jobskeyboard_arrow_down

Sign In
Sign In
Home
Courses
Algorithmskeyboard_arrow_down
Data Structureskeyboard_arrow_down
Languageskeyboard_arrow_down
Interview Cornerkeyboard_arrow_down
GATEkeyboard_arrow_down
CS Subjectskeyboard_arrow_down
Studentkeyboard_arrow_down
Jobskeyboard_arrow_down
GBlog
Puzzles
What's New ?
Basicsexpand_more
C++ Programming Language
Introduction to C++ Programming Language
Setting up C++ Development Environment
C++ Programming Basics
C++ Data Types
Variables in C++
Loops in C and C++
Decision Making in C / C++ (if , if..else, Nested if, if-else-if )
Basic Input/Outputexpand_more
Operatorsexpand_more
Arraysexpand_more
Stringsexpand_more
Functionsexpand_more
Pointers & Referencesexpand_more
Object Oriented Programmingexpand_more
Constructors & Destructorsexpand_more
Exception Handlingexpand_more
File Handlingexpand_more
Standart Template Library (STL)expand_more
ADVERTISEMENT
C++ Data Types
Last Updated: 14-10-2020
All variables use data-type during declaration to restrict the type of data to be stored. Therefore, we can say that data types are used to tell the variables the type of data it can store. Whenever a variable is defined in C++, the compiler allocates some memory for that variable based on the data-type with which it is declared. Every data type requires a different amount of memory.
 



Data types in C++ is mainly divided into three types: 
 

Primitive Data Types: These data types are built-in or predefined data types and can be used directly by the user to declare variables. example: int, char , float, bool etc. Primitive data types available in C++ are: 
Integer
Character
Boolean
Floating Point
Double Floating Point
Valueless or Void
Wide Character
Derived Data Types: The data-types that are derived from the primitive or built-in datatypes are referred to as Derived Data Types. These can be of four types namely: 
Function
Array
Pointer
Reference
Abstract or User-Defined Data Types: These data types are defined by user itself. Like, defining a class in C++ or a structure. C++ provides the following user-defined datatypes: 
Class
Structure
Union
Enumeration
Typedef defined DataType
This article discusses primitive data types available in C++. 
 

Integer: Keyword used for integer data types is int. Integers typically requires 4 bytes of memory space and ranges from -2147483648 to 2147483647. 
 
Character: Character data type is used for storing characters. Keyword used for character data type is char. Characters typically requires 1 byte of memory space and ranges from -128 to 127 or 0 to 255. 
 
Boolean: Boolean data type is used for storing boolean or logical values. A boolean variable can store either true or false. Keyword used for boolean data type is bool. 
 
Floating Point: Floating Point data type is used for storing single precision floating point values or decimal values. Keyword used for floating point data type is float. Float variables typically requires 4 byte of memory space. 
 
Double Floating Point: Double Floating Point data type is used for storing double precision floating point values or decimal values. Keyword used for double floating point data type is double. Double variables typically requires 8 byte of memory space. 
 
void: Void means without any value. void datatype represents a valueless entity. Void data type is used for those function which does not returns a value. 
 
Wide Character: Wide character data type is also a character data type but this data type has size greater than the normal 8-bit datatype. Represented by wchar_t. It is generally 2 or 4 bytes long. 
 
 



Datatype Modifiers

As the name implies, datatype modifiers are used with the built-in data types to modify the length of data that a particular data type can hold. 
 



Data type modifiers available in C++ are: 
 

Signed
Unsigned
Short
Long
Below table summarizes the modified size and range of built-in datatypes when combined with the type modifiers:
 

DATA TYPE	SIZE (IN BYTES)	RANGE
SHORT INT	2	-32,768 TO 32,767
UNSIGNED SHORT INT	2	0 TO 65,535
UNSIGNED INT	4	0 TO 4,294,967,295
INT	4	-2,147,483,648 TO 2,147,483,647
LONG INT	8	-2,147,483,648 TO 2,147,483,647
UNSIGNED LONG INT	8	0 TO 4,294,967,295
LONG LONG INT	8	-(2^63) TO (2^63)-1
UNSIGNED LONG LONG INT	8	0 TO 18,446,744,073,709,551,615
SIGNED CHAR	1	-128 TO 127
UNSIGNED CHAR	1	0 TO 255
FLOAT	4	 
DOUBLE	8	 
LONG DOUBLE	12	 
WCHAR_T	2 OR 4	1 WIDE CHARACTER
Note : Above values may vary from compiler to compiler. In the above example, we have considered GCC 32 bit.
We can display the size of all the data types by using the sizeof() operator and passing the keyword of the datatype as argument to this function as shown below: 
 

CPP
filter_none
edit
play_arrow

brightness_4
// C++ program to sizes of data types
#include<iostream>
using namespace std;
 
int main()
{
    cout << "Size of char : " << sizeof(char) 
      << " byte" << endl;
    cout << "Size of int : " << sizeof(int)
      << " bytes" << endl;
    cout << "Size of short int : " << sizeof(short int) 
      << " bytes" << endl;
    cout << "Size of long int : " << sizeof(long int) 
       << " bytes" << endl;
    cout << "Size of signed long int : " << sizeof(signed long int)
       << " bytes" << endl;
    cout << "Size of unsigned long int : " << sizeof(unsigned long int) 
       << " bytes" << endl;
    cout << "Size of float : " << sizeof(float) 
       << " bytes" <<endl;
    cout << "Size of double : " << sizeof(double) 
       << " bytes" << endl;
    cout << "Size of wchar_t : " << sizeof(wchar_t) 
       << " bytes" <<endl;
     
    return 0;
}
Output: 
 

Size of char : 1 byte
Size of int : 4 bytes
Size of short int : 2 bytes
Size of long int : 8 bytes
Size of signed long int : 8 bytes
Size of unsigned long int : 8 bytes
Size of float : 4 bytes
Size of double : 8 bytes
Size of wchar_t : 4 bytes


This article is contributed by Harsh Agarwal. If you like GeeksforGeeks and would like to contribute, you can also write an article using contribute.geeksforgeeks.org or mail your article to contribute@geeksforgeeks.org. See your article appearing on the GeeksforGeeks main page and help other Geeks.
Please write comments if you find anything incorrect, or you want to share more information about the topic discussed above.
 

Rated as one of the most sought after skills in the industry, own the basics of coding with our C++ STL Course and master the very concepts by intense problem-solving.




Recommended Posts:
Difference between fundamental data types and derived data types
Interesting facts about data-types and modifiers in C/C++
What happen when we exceed valid range of built-in data types in C++?
Calculate range of data types using C++
Understanding Data Attribute Types | Qualitative and Quantitative
Uninitialized primitive data types in C/C++
User defined Data Types in C++
Different types of Coding Schemes to represent data
Derived Data Types in C++
Data types in Java
Data Types in C
C++ default constructor | Built-in types
Introduction of Smart Pointers in C++ and It's Types
Ways to arrange Balls such that adjacent balls are of different types
Extended Integral Types (Choosing the correct integer size in C/C++)
Types of Exception in Java with Examples
Program to find all types of Matrix
Types of Operating Systems
Types of Literals in C/C++ with Examples
Types of Operator Overloading in C++
ADVERTISEMENT


Improved By : Naman-Bhalla, Abhi rex, adityamalik8087, glitch_09, whysodarkbro

Article Tags : 
C++
Mathematical
School Programming
Strings
C Basics
CBSE - Class 11
CPP-Basics
Data Type
school-programming
Practice Tags : 
Strings
Mathematical
Data Type
CPP

thumb_up
154


 
1.3

Based on 171 vote(s)
Improve Article  
Please write to us at contribute@geeksforgeeks.org to report any issue with the above content.
Post navigation
Previous
first_page Missing characters to make a string Pangram
Next
last_pageDecision Making in C / C++ (if , if..else, Nested if, if-else-if )




Writing code in comment? Please use ide.geeksforgeeks.org, generate link and share the link here.


Load Comments
ADVERTISEMENT

ADVERTISEMENT
auto
Most popular in C++
Vector in C++ STL
Initialize a vector in C++ (5 different ways)
Virtual Function in C++
rand() and srand() in C/C++
Converting Strings to Numbers in C/C++

Most visited in Mathematical
Find the smallest number whose digits multiply to a given number n
Program for Fibonacci numbers
Sieve of Eratosthenes
Write a program to print all permutations of a given string
Counting Sort

ADVERTISEMENT
GeeksforGeeks
room
5th Floor, A-118,
Sector-136, Noida, Uttar Pradesh - 201305
email
feedback@geeksforgeeks.org
Company
About Us
Careers
Privacy Policy
Contact Us
Learn
Algorithms
Data Structures
Languages
CS Subjects
Video Tutorials
Practice
Courses
Company-wise
Topic-wise
How to begin?
Contribute
Write an Article
Write Interview Experience
Internships
Videos
@geeksforgeeks , Some rights reserved
	*/


	daugther* pinky = dynamic_cast<daugther*>(mom);
	if (pinky)
		std::cout << "pinky is daugther" << std::endl;
	else
		std::cout << "pinky is not daugther" << std::endl;

	son* not_pinky = dynamic_cast<son*>(mom);
	if (not_pinky)
		std::cout << "not_pinky is son" << std::endl;
	else
		std::cout << "not_pinky is not son" << std::endl;

	return 0;
}