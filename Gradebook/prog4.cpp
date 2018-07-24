//Barthelemy Peter
// 4-27-17
// Gradebook
// Info read in from a text file
//Output student first and lastname (include SID #) grades and the percentage of the score in each category and final score 
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip> 

	
using namespace std;

const string space= "   ";


struct crsInfo
	{
		double SID; 
		string last_name;
		string first_name;
		string email;
		double quizzes[7];
		double exams[3];
		double programs[5];
		double final;
	};
	
string grade_check(double score);
void grab_student_info(int numOfStudents, string& first_name, string& last_name, double& SID, string& email, double quiz[], double program[], double exam[], double& final);
void info(string& first_name, string& last_name, double& SID, string& email);
void results(double quiz[],const int quiz_total[],double program[],const int program_total[], double exam[],const int exam_total[], double& final,const int final_total);
double pecentage(int num, double category[],const int total);
double Best_of_Three(double exam[],const int exam_total[]);

int main()
{
	crsInfo student;
	double course_grade;
	double qz_percent;
	double prog_percent;
	double exam_percent;
	double final_percent;
	double qz_ans = 0;
	double ex_ans = 0;
	int prog_ans = 0;
	int fin_ans = 0;
	
	//The following declaration provides total possible point that can be earned while grading the results of student scores
	const int quiz_total[7]= {5, 50, 5, 18, 20, 16, 10};
	
	for(int i = 0; i < 7; i++)
		qz_ans += quiz_total[i]; 
		 
	const int exam_total[3]={100, 100, 20};
	
	for(int j = 0; j < 3; j++)
		ex_ans += exam_total[j];
	
	const int prog_total[5]= {20, 20, 20, 20, 20} ;
	
	for(int k = 0; k < 5; k++)
		prog_ans += prog_total[k];
		
	const int final_total = 200;
	fin_ans = final_total;
	// end of total points declaration
	
	// Grading Guide for layout design purposes and also to provide information on how a student's results are graded				
	char border = ' ';
	
	cout << setfill(' ');
	cout << endl << setw(30)<< "WELCOME TO THE GRADEBOOK"<< endl << endl;
	cout << setw(11) << "Programs " << setw(24) << "30% of grade"<<endl;
	cout << setw(19) << "Homework/Quizzes " << setw(16) << "25% of grade"<< endl;
	cout << setw(18) << "Exams(best 2/3) "<< setw(17) << "25% of grade"<< endl;
	cout << setw(8) << "Final "<< setw(27) << "20% of grade"<<endl;
	
	cout << setfill('=');
	cout << setw(37) << border << endl;
	cout << setfill(' ');

	
	cout << setw(7) << "Total" << setw(20) << "100%" << endl << endl;
	
	cout << setfill('-');
	
	cout << setw(65)<< border<< endl ;
	cout << "Letter grades will be assigned according to the following scale"<< endl << endl;
	cout << space << "A >= 93%, A- >= 89%, B+ >= 86%, B >= 83%, B- >= 79%,"<< endl;
	cout << space << "C+ >= 76%, C >= 73%, C- >= 69%, D >= 60%, F < 60%" << endl; 
	cout << setw(65)<< border<< endl << endl;
	// End of Grading guide 
	
	
	for(int i = 1; i <= 5; i++)
	{
	grab_student_info(i, student.first_name, student.last_name, student.SID,student.email, student.quizzes, student.programs, student.exams, student.final);
	
	info(student.first_name, student.last_name, student.SID, student.email);
	
	results(student.quizzes, quiz_total,student.programs, prog_total, student.exams , exam_total, student.final, final_total);
	cout << endl;
	
	qz_percent = pecentage(7, student.quizzes,qz_ans);
	prog_percent = pecentage(5, student.programs,prog_ans);
	exam_percent = Best_of_Three(student.exams,exam_total);
	final_percent = student.final/fin_ans*100;
	course_grade = (qz_percent*25+prog_percent*30+exam_percent*25+final_percent*20)/100;
	cout << "Quiz Total = "<<qz_percent <<"%" <<endl;
	cout << "Program Total = " <<prog_percent <<"%"<<endl;
	cout << "Exam Total = " <<exam_percent <<"%"<<endl;
	cout << "Final Total = "<< final_percent <<"%"<<endl<<endl;
	cout <<space << space << "FINAL COURSE SCORE = "<<course_grade<<"%";
	cout <<space << space << "FINAL COURSE GRADE = "<<grade_check(course_grade)<< endl<<endl<<endl;

	}	
				
	return 0;
}

string grade_check(double score)
{
	string grade;
	
	if(score >= 93)
		grade = "A";
	else if(score>= 89)	
		grade = "A-";
	else if(score >= 86)
		grade = "B+";
	else if(score >= 83)
		grade = "B";
	else if (score >= 79)	
		grade = "B-";
	else if (score >= 76)
		grade = "C+";
	else if (score >= 73)
		grade = "C";
	else if (score >= 69)
		grade = "C-";
	else if (score >= 60)
		grade = "D";
	else if (score <= 60)
		grade = "F";
	return grade;						
}

void grab_student_info(int numOfStudents, string& first_name, string& last_name, double& SID, string& email , double quiz[], double program[], double exam[], double& final)
{
	ifstream inFile;
	inFile.open("Grades.txt");
	for(int r = 0; r < numOfStudents; r++)
	{
	inFile >> first_name >> last_name >> SID >> email;
	
	for(int i = 0; i < 7; i++)
		inFile>> quiz[i];
		
	for(int j = 0; j < 5; j++)
		inFile >> program[j];
		
	for(int k = 0; k < 3; k++)
		inFile >> exam[k];
		
	inFile >> final;
	}
	inFile.close();
}

void info(string& first_name, string& last_name, double& SID, string& email)
{
	cout << "Student's current information"<< endl << endl;
	cout << "Student name:   " << first_name << " "<< last_name << endl;
	cout << "Student ID#:    " << SID << endl;
	cout << "Email address:  " << email << endl << endl;
}

void results(double quiz[], const int quiz_total[],double program[],const int program_total[], double exam[],const int exam_total[], double& final,const int final_total)
{
	cout << "Quiz Scores"<< endl;
	for (int i = 0; i < 7; i++)
		cout << quiz[i]/quiz_total[i]*100 << space;
	cout << endl;
	
	cout << "Program Scores"<< endl;
	for (int j = 0; j < 5; j++)
		cout << program[j]/program_total[j]*100 << space;
	cout << endl;	 
	
	cout << "Exam Scores" << endl;
	for (int k = 0; k < 3; k++)
		cout << exam[k]/exam_total[k]*100 << space;
	cout << endl;	
	
	cout << "Final Exam Score" << endl;
		cout << final/final_total*100 << space;	
	cout << endl;	
}

double pecentage(int num, double category[],const int total)
{
	double ans = 0;
	for(int i = 0; i < num; i++)
		ans += category[i];
	
	return ans/total*100;
}

double Best_of_Three(double exam[],const int exam_total[])
{
	const int MAX_POINTS = 200;
	double result = 0;
	double ans[3];
	double lowest_exam = 0;
	double total_points = 0;
	for(int i = 0; i < 3; i++)
		{
		ans[i] = exam[i]/exam_total[i]*100;
		total_points += ans[i];
		}
		
	// Finds the smallest test score
	for(int j = 0; j < 3; j++)
	{
		if (ans[j] < ans[2-j])
			lowest_exam = ans[j];		
	}
	
	if(lowest_exam != 0)
		result = (total_points - lowest_exam)/MAX_POINTS*100;	
	else if(lowest_exam == 0)
		result = (ans[0]+ans[1])/MAX_POINTS*100; 
	
		return result;
}
