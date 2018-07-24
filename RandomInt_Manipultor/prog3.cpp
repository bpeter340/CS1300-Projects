//Barthelemy Peter
//05-28-17
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

int double_Num(int input);
int reversed_Num(int input);
int raised_Num(int input , int powerFactor);
int combined_Num(int input);
int _2_digit_num_manipulator(int input);
void special_case_manipulator(int input);
void prime_Number(int num);
int ten_Check(int num);
string space = "   "; 


int main()
{
	int manip;
	int option;
	srand(time(0));
	manip= rand() % 100;
	
	
		for(int i=0; i<10; i++)
			cout<<space;
		
//Instructions for case switch statement		
		cout << "INTEGER MANIPULATOR"<<endl << endl;
		cout <<space<<space<< "Instructions: Select an option to manipulate your current random integer"<< endl ;
		cout <<space<<space<< "Note: This program checks for prime numbers"<< endl;
		cout << endl;
		cout <<space<< "(1) Generate a random integer" << endl;
		cout <<space<< "(2) Double the number" << endl;
		cout <<space<< "(3) Reverse the digits of the number" << endl;
		cout <<space<< "(4) Raise the number to the power of 2, 3, or 4" << endl;
		cout <<space<< "(5) Sum the digits of the number" << endl;
		cout <<space<< "(6) If the number is a 2 digit number raise the first digit to the power of the second digit" << endl;
		cout <<space<< "(7) If the number is a 3 digit number and the last digit is less than or equal to four" << endl; 
		cout <<space<<space<<' '<< "the first 2 digits will be raised to the power of the last digit" << endl;
		cout <<space<< "(0) If you wish to end the program" << endl;
		cout <<endl<<space<<"This is your number: " << manip;
		prime_Number(manip);
	
//Implementation of Case Switch Statement
	do
	{	
		cout << space;
		cin >> option;
		cout << endl;
		switch (option)
	{
		case 1:
		srand(time(0));
		manip= rand() % 100;
		cout <<space<<"This is your number: "<< manip;
		prime_Number(manip);
		break;
		
	case 2:
		cout <<space<<"When '"<< manip <<"' is doubled, the new number becomes " << endl;
		manip = double_Num(manip);
		cout <<space<< manip;
		prime_Number(manip);
		break;
		
	case 3:
		cout <<space<< "When '"<< manip << "' is reversed, the new number becomes " << endl;
		manip = reversed_Num(manip);
		cout <<space<< manip;
		prime_Number(manip);
		break;
		
	case 4:
		cout <<space<< "Enter a value (2, 3, or 4) to raise " <<manip<< " to that power " <<endl;
		manip = raised_Num(manip, option);
		cout <<space<< manip;
		prime_Number(manip);
		break;
		
	case 5:
		cout <<space<< "This is the sum of the integers of "<<manip<< endl;
		manip = combined_Num(manip);
		cout <<space<< manip;
		prime_Number(manip);
		break;
		
	case 6:	
		cout <<space<< "If the value of '"<<manip<<"' is a two digit number, then the first " 
		<< endl <<space<< "digit will be raised to the power of the second digit"<< endl << endl;
		manip = _2_digit_num_manipulator(manip);
		cout <<space<< manip;
		prime_Number(manip);
		break;
		
	case 7:
		cout <<space<< "If the value of '"<<manip<<"' is a three digit number and the last digit is less than or equal to 4"
		 << endl <<space<< "the first two digits will be raised to the power of the last digit " << endl << endl;
		special_case_manipulator(manip);
		cout <<space<< manip;
		prime_Number(manip);
		break;
	
	case 0:
		return 0;
	
	default:
		 cout <<space<< "Invalid input" << endl;
	}	
	}
	while(option);	
	
	return 0;
}

int double_Num(int input)
{
	input = 2 * input;
	input = ten_Check(input);
	
	return input;
}

int raised_Num(int input, int powerFactor)
{
	bool isFound = true;
	int val;
	
	while(isFound)
	{	
		cout <<space;
		cin >> powerFactor;
			if (powerFactor >= 2 && powerFactor <= 4 )	
			{
				isFound = false;
				cout << endl;
				cout <<space<< input << " raised to the power of " << powerFactor << " = ";  
				cout << pow(input, powerFactor) << endl << endl;
				val = pow(input, powerFactor);
			}
			else 
			{
				cout <<space<<"The value entered is not valid, use only numbers 2, 3, or 4" <<endl << endl;
			}
	}
	
		val= ten_Check(val);
	return val;	
}

int reversed_Num(int input)
{
	int new_Num = 0;
	while(input > 0)
	{
		new_Num = new_Num*10 + (input % 10);
		input = input/10;
	}
		new_Num= ten_Check(new_Num);
	return new_Num;
}

int combined_Num(int input)
{
	int sum = 0;
	while(input > 0)
	{
		sum += input % 10;
		input /= 10;
	} 
		sum = ten_Check(sum);
	return sum;
}

int _2_digit_num_manipulator(int input)
{
	int countDigit = 0;
	int digit_1 = 0;
	int digit_2 = 0;
	int value; 
	
	while(input != 0)	
	{
		input /= 10;
		countDigit++;
	}
		if (countDigit == 2)
		{
			digit_1 = input/10 % 10;
			digit_2 = input % 10;
			value = pow(digit_1,digit_2);
			cout <<space<< "When " << digit_1 << " is raised to the power of " << digit_2 <<" the new value = " << value << endl <<endl;
		}
		else
			cout <<space<< "The number in the previous step is not a two digit number" << endl;
		
		value = ten_Check(value);
	return value;
}

void special_case_manipulator(int input)	
{
	int countDigit = 0;
	int digit_1 = 0;
	int digit_2 = 0;
	int digit_3 = 0;
	int num;

	while (input != 0)
	{
		input /= 10;
		countDigit++;
	}

	digit_1 = input/100 % 10;
	digit_2 = input/10 % 10;
	digit_3 = input % 10;	
		if (countDigit == 3 && digit_3 <= 4)
		{
			
				num = pow(digit_1, digit_3);
				cout <<space<< digit_1 <<" raised to the power of "<< digit_3 << " = " << num <<endl;
				prime_Number(num); 
				
				num = pow(digit_2, digit_3);
				cout <<space<< digit_2 <<" raised to the power of " << digit_3 << " = "  << pow(digit_2, digit_3) <<endl;
				prime_Number(num);
		}
		else if (countDigit != 3)		
				cout <<space<< "The number is not a three digit number "<< endl;
		else if (digit_3 > 4)
			cout <<space<< "The number contains three digits, but the last digit is not less than or equal to 4"  <<endl;
			 		
}
	
void prime_Number(int num)
{
	int n = 1;
	for(int x = 2; x < num - 1;  x++)
	{
		if(num % x != 0)
		{
		}
		else
			n=0;

	}
	if (n==0)
		cout <<space <<" Not prime" << endl << endl;
	else
		cout <<space <<" Prime"<< endl << endl;
}

int ten_Check(int num)
{
	if (num < 10)
		{	
			cout<<space;
			cout  << num << endl << endl;
			for (int i=0; i<35; i++)
			cout << "_";
			cout << "WAIT";
			for (int i=0; i<35; i++)
			cout << "_";
			cout <<endl<<"The value '"<< num <<"' was less than 10, so 10 was automatically added to the value"<< endl;
			num += 10;
			cout <<"Your new value is "<< num << endl;
		}
	return num;
}
