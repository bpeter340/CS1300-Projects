//Barthelemy Peter
//05-28-17
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

int double_Num(int& temp_1);
int reversed_Num(int temp_2);
int raised_Num(int temp_3 , int x);
int combined_Num(int temp_4);
int digit_Count(int temp_5);
void triple_Check(int temp_6);
void prime_Number(int num);
int ten_Check(int num);
string space = "   "; 


int main()
{
	int manip;
	int x;
	srand(time(0));
	manip= rand() % 100;
	
	
		for(int i=0; i==10; i++)
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
		cin >> x;
		cout << endl;
		switch (x)
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
		manip = raised_Num(manip, x);
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
		manip = digit_Count(manip);
		cout <<space<< manip;
		prime_Number(manip);
		break;
		
	case 7:
		cout <<space<< "If the value of '"<<manip<<"' is a three digit number and the last digit is less than or equal to 4"
		 << endl <<space<< "the first two digits will be raised to the power of the last digit " << endl << endl;
		triple_Check(manip);
		cout <<space<< manip;
		prime_Number(manip);
		break;
	
	case 0:
		return 0;
	
	default:
		 cout <<space<< "Invalid input" << endl;
	}	
	}
	while(x);	
	
	return 0;
}

int double_Num(int& temp_1)
{
	int num = 2 * temp_1;
	num = ten_Check(num);
	return num;
}

int raised_Num(int temp_3, int x)
{
	bool isFound;
	isFound = true;
	int val;
	
	while(isFound)
	{	
		cout <<space;
		cin >> x;
			if (x >= 2 && x <= 4 )	
			{
				cout << endl;
				cout <<space<< temp_3 << " raised to the power of " << x << " = ";  
				cout << pow(temp_3,x) << endl << endl;
				isFound = false;
				val = pow(temp_3,x);
			}
			else 
			{
				isFound = false;
				cout <<space<<"The value entered is not valid, use only numbers 2, 3, or 4" <<endl << endl;
			}
	}
	
		val= ten_Check(val);
	return val;	
}

int reversed_Num(int temp_2)
{
	int new_Num = 0;
	while(temp_2 > 0)
	{
		new_Num = new_Num*10 + (temp_2 % 10);
		temp_2 = temp_2/10;
	}
		new_Num= ten_Check(new_Num);
	return new_Num;
}

int combined_Num(int temp_4)
{
	int sum = 0;
	while(temp_4 > 0)
	{
		sum += temp_4 % 10;
		temp_4 /= 10;
	} 
		sum = ten_Check(sum);
	return sum;
}

int digit_Count(int temp_5)
{
	int digits;
	int x;
	int y;
	int val ;
	int num;
	num = temp_5; 
	
	while(temp_5 != 0)	
	{
		temp_5 /= 10;
		digits++;
	}
		if (digits == 2)
		{
			x = num/10 % 10;
			y = num % 10;
			val = pow(x,y);
			cout <<space<< "When " << x << " is raised to the power of " << y <<" the new value = " << val << endl <<endl;
		}
		else
			cout <<space<< "The number in the previous step is not a two digit number" << endl;
		
		val = ten_Check(val);
	return val;
}

void triple_Check(int temp_6)	
{
	int num_2;
	int digits_2;
	int x;
	int y;
	int z;
	int val;
	int num;

	num_2 = temp_6;
	
	while (temp_6 != 0)
	{
		temp_6 /= 10;
		digits_2++;
	}

	x = num_2/100 % 10;
	y = num_2/10 % 10;
	z = num_2 % 10;	
		if (digits_2 == 3 && z <= 4)
		{
			
				cout <<space<< x <<" raised to the power of "<< z << " = " << pow(x,z) <<endl;
				num = pow(x,z);
				prime_Number(num); 
				cout <<space<< y <<" raised to the power of " << z << " = "  << pow(y,z) <<endl;
				num = pow(y,z);
				prime_Number(num);
		}
		else if (digits_2 != 3)		
				cout <<space<< "The number is not a three digit number "<< endl;
		else if (z > 4)
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
