//
//  main.cpp
//  Program1Calculator
//
//  Created by Nicholas Sullivan on 2/6/18.
//  Copyright © 2018 Nicholas Sullivan. All rights reserved.
//

#include <iostream>
#include <iomanip>
#include <stdlib.h>

using namespace std;

/*

 Nicholas Sullivan
 COMPE260
 821661666
 1/26/18

 */

 //Declare all of the pointer variables globally for use with functions.
float *op1Ptr, *op2Ptr;
char *op3Ptr, *ynPtr;
bool *exitPtr, *validPtr;

//Function prototype for function that checks for NULL pointers.
bool ptrMemAllocSuccess();

//Function prototype for function that deletes allocated memory.
void deleteAllocMem();

int main()
{

	//Anonymous Variables
	op1Ptr = new (nothrow) float;
	op2Ptr = new (nothrow) float;
	op3Ptr = new (nothrow) char;
	ynPtr = new (nothrow) char;
	exitPtr = new (nothrow) bool;
	validPtr = new (nothrow) bool;

	if (ptrMemAllocSuccess());
	else { return 0; }

	//Do-While loop for main calculator.
	do
	{
		//Instructions to use calculator.
		cout << ""
			"*****************************************************\n"
			"*                                                   *\n"
			"*                                                   *\n"
			"*                                                   *\n"
			"*       Welcome to the Calculator!                  *\n"
			"*       Enter your operator.                        *\n"
			"*       Then enter your operands.                   *\n"
			"*       Your result will be displayed.              *\n"
			"*       Make as many calculations as you wish.      *\n"
			"*                                                   *\n"
			"*                                                   *\n"
			"*                                                   *\n"
			"*****************************************************\n"
			<< endl;

		//Initialize all values.
		*op1Ptr = 0.0f;
		*op2Ptr = 0.0f;
		*op3Ptr = '\0';
		*ynPtr = '\0';
		*exitPtr = false;
		*validPtr = true;

		//Prompt user for operands and operators.
		do
		{
			*validPtr = true;
			cout << "Enter your operator: +,-,*,/" << endl;
			cin >> *op3Ptr;
			if ((*op3Ptr == '+') || (*op3Ptr == '-') || (*op3Ptr == '*') || (*op3Ptr == '/'))
			{
				//if valid operator, cout operator, clear cin and continue.
				cout << "Operator: " << *op3Ptr << endl;
				cin.clear(); //found from http://www.dynamicguru.com/tips/cpp-check-if-input-is-valid-data-type-using-cin-fail/
				cin.ignore(999, '\n');
			}
			else
			{
				//if invalid input, clear cin and restart this loop.
				cin.clear(); //found from http://www.dynamicguru.com/tips/cpp-check-if-input-is-valid-data-type-using-cin-fail/
				cin.ignore(999, '\n');
				cout << "Error: Please only enter one of the operators: +,-,*,/" << endl;
				*validPtr = false;
			}
		} while (!*validPtr);

		do
		{
			*validPtr = true;
			cout << "Enter your first operand (must be a real number)." << endl;
			cin >> *op1Ptr;
			if (!cin)
			{
				//if invalid input, clear cin and restart this loop.
				cin.clear(); //found from http://www.dynamicguru.com/tips/cpp-check-if-input-is-valid-data-type-using-cin-fail/
				cin.ignore(999, '\n');
				cout << "Error: Input must be a real number." << endl;
				*validPtr = false;
			}
			else {
				//cout number, clear cin, and continue.
				cout << "First Operand: " << *op1Ptr << endl;
				cin.clear(); //found from http://www.dynamicguru.com/tips/cpp-check-if-input-is-valid-data-type-using-cin-fail/
				cin.ignore(999, '\n');
			}
		} while (!*validPtr);

		do
		{
			*validPtr = true;
			cout << "Enter your second operand (must be a real number)." << endl;
			cin >> *op2Ptr;

			//if statements depending on user's input and operator.
			if (!cin)
			{
				//if invalid input, clear cin and restart this loop.
				cin.clear(); //found from http://www.dynamicguru.com/tips/cpp-check-if-input-is-valid-data-type-using-cin-fail/
				cin.ignore(999, '\n');
				cout << "Error: Input must be a real number." << endl;
				*validPtr = false;
			}
			else if (*op3Ptr == '+')
			{
				cout << "Second Operand: " << *op2Ptr << endl;
				cout << "Sum: " << *op1Ptr << " + " << *op2Ptr << " = " << *op1Ptr + *op2Ptr << endl;
			}
			else if (*op3Ptr == '-')
			{
				cout << "Second Operand: " << *op2Ptr << endl;
				cout << "Difference: " << *op1Ptr << " - " << *op2Ptr << " = " << *op1Ptr - *op2Ptr << endl;
			}
			else if (*op3Ptr == '*')
			{
				cout << "Second Operand: " << *op2Ptr << endl;
				cout << "Product: " << *op1Ptr << " * " << *op2Ptr << " = " << (*op1Ptr)*(*op2Ptr) << endl;
			}
			else if (*op3Ptr == '/')
			{
				if (*op2Ptr == 0)
				{
					//If trying to divide by zero, re-prompt (zero as first operand is ok. ie 0/1 = 0).
					cin.clear(); //found from http://www.dynamicguru.com/tips/cpp-check-if-input-is-valid-data-type-using-cin-fail/
					cin.ignore(999, '\n');
					cout << "Error: Do not divide by zero." << endl;
					*validPtr = false;
				}
				else {
					cout << "Second Operand: " << *op2Ptr << endl;
					cout << "Quotient: " << *op1Ptr << " / " << *op2Ptr << " = " << (*op1Ptr) / (*op2Ptr) << endl;
				}
			}
			else {
				cin.clear(); //found from http://www.dynamicguru.com/tips/cpp-check-if-input-is-valid-data-type-using-cin-fail/
				cin.ignore(999, '\n');
				cout << "Error: Please only enter one of the operators: +,-,*,/" << endl;
				*validPtr = false;
			}

		} while (!*validPtr);

		do
		{
			//Prompt user to do another calculation or quit.
			*validPtr = true;
			cin.clear(); //found from http://www.dynamicguru.com/tips/cpp-check-if-input-is-valid-data-type-using-cin-fail/
			cin.ignore(999, '\n');
			cout << "Do you want to make another calculation? Y/N" << endl;
			cin >> *ynPtr;

			if ((*ynPtr == 'Y') || (*ynPtr == 'y'))
			{
				//Continue main loop if yes.
			}
			else if ((*ynPtr == 'N') || (*ynPtr == 'n'))
			{
				//Negate condition so main loop exits and delete allocated memory.
				*exitPtr = true;
			}
			else
			{
				//if input is not valid re-prompt.
				cout << "Please only enter Y/N" << endl;
				*validPtr = false;
			}
		} while (!*validPtr);

	} while (!*exitPtr);

	deleteAllocMem();
	return 0;
}

//Method to check for NULL pointers. (found from http://www.cplusplus.com/reference/new/nothrow/)
bool ptrMemAllocSuccess()
{
	if (!op1Ptr || !op2Ptr || !op3Ptr || !ynPtr || !exitPtr || !validPtr)
	{
		cout << "***A Pointer Returned NULL Pointer! Process Terminated.***" << endl;
		return false;
	}
	else {
		cout << "***All Pointer Memory Allocation Successful! No NULL Pointers Returned.***\n" << endl;
		return true;
	}
}

//Function that deletes allocated memory.
void deleteAllocMem()
{
	delete op1Ptr;
	delete op2Ptr;
	delete op3Ptr;
	delete ynPtr;
	delete exitPtr;
	delete validPtr;
}
