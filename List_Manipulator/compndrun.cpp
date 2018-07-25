#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>

using namespace std;

const int SIZE = 100;
const int rows = 20;
const int columns = 5;
double list_manip[SIZE];
char space = ' ';


void get_input();
void list_sort(bool &check_sort);
double maxValue(bool check_sort);
double minValue(bool check_sort);
double sum_array(double list_manip[], int listSize);
double get_variance(double average);


int main()
{
	ofstream outFile;
	outFile.open("storedOutput.txt");
	
	
	bool check_sort = false;
	
	get_input();
	list_sort(check_sort);	

	double largest_value = maxValue(check_sort);
	double smallest_value = minValue(check_sort);
	double total = sum_array(list_manip, SIZE);	
	double average = total / SIZE;	
	double variance = get_variance(average);
	double standard_Dev = sqrt(variance);
	
	
	cout << endl;
	

	
//Used to organize output in columns in both th console window and text file
	for (int i= 0; i < rows; i++)
	{
		for (int j= 0; j < columns; j++)
			{
			cout << left << setw(10) << list_manip[i*columns+j] ;
			outFile << left << setw(10) << list_manip[i*columns+j] << space;
			}
		cout << endl;
		outFile << endl;
	}
	cout << endl << endl;
	outFile << endl << endl;
	
	cout << "The largest value in the list of numbers is:  " << largest_value << endl;
	outFile << "The largest value in the list of numbers is:  " << largest_value << endl;
	cout << "The smallest value in the list of numbers is:  " << smallest_value << endl << endl; 
	outFile << "The smallest value in the list of numbers is:  " << smallest_value << endl << endl;
	
	
	
	for (int i= 20; i > 0 ; i--)
	{
		int k = 0;
		for (int j= 5; j > 0 ; j--)
			{	
			++k;
			cout << left << setw(10) << list_manip[i*5-k] << space ;
			outFile << left << setw(10) << list_manip[i*5-k] << space ;
			}
		cout << endl;
		outFile << endl;
	}
	cout << endl << endl;
	outFile << endl << endl;
	
	cout << "This is the average of the list  " << average << endl;
	outFile << "This is the average of the list  " << average << endl;
	cout << "This is the variance of the list  " << variance << endl;
	outFile <<  "This is the variance of the list  " << variance << endl;
	cout << "This is the standard deviation of the list  " << standard_Dev << endl << endl;
	outFile <<  "This is the standard deviation of the list  " << standard_Dev << endl << endl;
	
		

	outFile.close();
	
	return 0;
}


//Function finds the Largest value in the stored array
double maxValue(bool check_sort)
{
	double MAX;
	
	if(check_sort)
		MAX = list_manip[SIZE-1];
	
	return MAX;	
}

//Function finds the smallest value in the stored array 
double minValue(bool check_sort)
{
	int MIN;
	
	if(check_sort)
		MIN = list_manip[0];

	return MIN;
}

//Function sorts the list from smallest to largest
//Will more that likely replace by bubble sort due to inefficiency
void list_sort(bool &check_sort)
{
	int temp;
	int smallestIndex;
	int location;
	
	for (int i = 0; i < SIZE - 1 ; i++) 
	{
		smallestIndex = i;
		
		for (location = i + 1; location < SIZE; location++)
			if (list_manip[smallestIndex] > list_manip[location])
				smallestIndex = location;
				
			temp = list_manip[smallestIndex];
			list_manip[smallestIndex] = list_manip[i];
			list_manip[i] = temp;
		
	}
	
	check_sort = true;
}

//Function gets input from a test file
void get_input()
{
	ifstream inFile;
	inFile.open("input_list.txt");
	
	for (int i = 0; i < SIZE; i++)
		inFile >> list_manip[i];
		
	inFile.close();
}

//Function finds the sum of all stored values
double sum_array(double list_manip[], int listSize)
{
	double answer = 0;
	for (int i = 0 ; i < SIZE; i++)
	{
		answer += list_manip[i];
	}
	return answer;
}

//Function used to calculate the variance of the stored numbers
double get_variance(double average)
{
	double item, variance;
	double summation = 0;
	for (int i = 0; i < SIZE; i++)
		{
			item = pow((list_manip[i] - average), 2);
			summation += item; 
		}
	variance = summation /(SIZE - 1);
	return variance;		
}

