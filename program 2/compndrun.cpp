#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>

using namespace std;
const int rows = 20;
const int columns = 5;
const int SIZE = 100;
float list_manip[SIZE];
ifstream inFile;
ofstream outFile;

void builder();
void input();
void increasing_list_manip();
float maxValue();
float minValue();
void decreasing_list_manip();
float sum(float list_manip[], int num);
float variance(float average);
char space = ' ';

int main()
{
	
	inFile.open("Array.txt");
	outFile.open("arrayout.txt");
	
	input();
	
	float largest = maxValue();
	float smallest = minValue();
	float total = sum(list_manip, SIZE);	
	float average = total / SIZE;	
	float var = variance(average);
	float standard_Dev = sqrt(var);
	
	cout << endl;
	increasing_list_manip();
	
//Used to organize output in rows and columns
//Also used to organize values in an output file
	for (int i= 0; i < rows; i++)
	{
		for (int j= 0; j < columns; j++)
			{
			cout << left << setw(10) << list_manip[i*5+j] ;
			outFile << left << setw(10) << list_manip[i*5+j] << space;
			}
		cout << endl;
		outFile << endl;
	}
	cout << endl << endl;
	outFile << endl << endl;
	
	cout << "The largest value in the list_manip of numbers is:  " << largest << endl;
	outFile << "The largest value in the list_manip of numbers is:  " << largest << endl;
	cout << "The smallest value in the list_manip of numbers is:  " << smallest << endl << endl; 
	outFile << "The smallest value in the list_manip of numbers is:  " << smallest << endl << endl;
	
	
	
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
	
	cout << "This is the average of the list_manip  " << average << endl;
	outFile << "This is the average of the list_manip  " << average << endl;
	cout << "This is the variance of the list_manip  " << var << endl;
	outFile <<  "This is the variance of the list_manip  " << var << endl;
	cout << "This is the standard deviation of the list_manip  " << standard_Dev << endl << endl;
	outFile <<  "This is the standard deviation of the list_manip  " << standard_Dev << endl << endl;
	
		
	inFile.close();
	outFile.close();
	return 0;
}

//Function sorts the array from largest to smallest 
void decreasing_list_manip()
{
	int temp;
	int smallestIndex;
	int location;
	int i;
	
	for (i = 0; i < SIZE - 1 ; i++) // these are the numbers for input
	{
		smallestIndex = i;
		
		for (location = i + 1; location < SIZE; location++)
			if (list_manip[smallestIndex] > list_manip[location])
				smallestIndex = location;
				
			temp = list_manip[smallestIndex];
			list_manip[smallestIndex] = list_manip[i];
			list_manip[i] = temp;
	}
}

//Function finds the Largest value in the stored array
// Very Buggy
float maxValue()
{
	float MAX;
	for (int i = 1; i < SIZE; i++)
	{
		if (list_manip[i] > list_manip[i-1])
			MAX = list_manip[i];
	//	else
	//		MAX = list_manip[i-1];
	}
	return MAX;	
}

//Function finds the smallest value in the stored array 
// Very buggy
float minValue()
{
	float MIN;
	for (int i = 1; i < SIZE ; i++)
		{
		if (list_manip[i] < list_manip[i-1])
			MIN = list_manip[i];
		} 
	return MIN;
}

//Function sorts the list from smallest to largest
void increasing_list_manip()
{
	int temp;
	int smallestIndex;
	int location;
	int i;
	
	for (i = 0; i < SIZE - 1 ; i++) // these are the numbers for input
	{
		smallestIndex = i;
		
		for (location = i + 1; location < SIZE; location++)
			if (list_manip[smallestIndex] > list_manip[location])
				smallestIndex = location;
				
			temp = list_manip[smallestIndex];
			list_manip[smallestIndex] = list_manip[i];
			list_manip[i] = temp;
		
	}
	
}

//Function gets input from a test file
void input()
{
	for (int i = 0; i < SIZE; i++)
		inFile >> list_manip[i];
}

//Function finds the sum of all stored values
float sum(float list_manip[], int num)
{
	float answer = 0;
	for (int i = 0 ; i < SIZE; i++)
	{
		answer += list_manip[i];
	}
	return answer;
}

//Function used to calculate the variance of the stored numbers
float variance(float average)
{
	float temp, ans, root;
	float var= 0;
	for (int i = 0; i < SIZE; i++)
		{
			temp = pow((list_manip[i] - average), 2);
			var += temp; 
		}
	ans = var /(SIZE - 1);
	return ans;
		
}

