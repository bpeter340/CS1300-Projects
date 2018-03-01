//Barthelemy Peter
// 4-27-17
// Gradebook
// Info read in from a text file
//Output student first and lastname (include ID #) grades and the percentage of the grade in each category and final grade 
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip> 

	
using namespace std;

const string space= "   ";


struct crsInfo
	{
		double SID; 
		string lName;
		string fName;
		string email;
		double quizzes[7];
		double exams[3];
		double progs[5];
		double final;
	};
	
string grade_check(double grade);
void capture(int num, string& fn, string& ln, double& ID, string& em, double qz[], double prog[], double ex[], double& fin);
void info(string& fn, string& ln, double& ID, string& em);
void results(double qz[],const int qztot[],double prog[],const int progtot[], double ex[],const int extot[], double& fin,const int fintot);
double pecentage(int num, double category[],const int total);
double Best_of_Three(double ex[],const int extot[]);

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
	
	for(int i = 1; i < 6; i++)
	{
	capture(i, student.fName, student.lName, student.SID,student.email, student.quizzes, student.progs, student.exams, student.final);
	
	info(student.fName, student.lName, student.SID, student.email);
	
	results(student.quizzes, quiz_total,student.progs, prog_total, student.exams , exam_total, student.final, final_total);
	cout << endl;
	
	qz_percent = pecentage(7, student.quizzes,qz_ans);
	prog_percent = pecentage(5, student.progs,prog_ans);
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

string grade_check(double grade)
{
	string alpha_Val;
	
	if(grade >= 93)
		alpha_Val = "A";
	else if(grade >= 89)	
		alpha_Val = "A-";
	else if(grade >= 86)
		alpha_Val = "B+";
	else if(grade >= 83)
		alpha_Val = "B";
	else if (grade >= 79)	
		alpha_Val = "B-";
	else if (grade >= 76)
		alpha_Val = "C+";
	else if (grade >= 73)
		alpha_Val = "C";
	else if (grade >= 69)
		alpha_Val =	"C-";
	else if (grade >= 60)
		alpha_Val = "D";
	else if (grade <= 60)
		alpha_Val = "F";
	return alpha_Val;						
}

void capture(int num, string& fn, string& ln, double& ID, string& em , double qz[], double prog[], double ex[], double& fin)
{
	ifstream inFile;
	inFile.open("Grades.txt");
	for(int r = 0; r < num; r++)
	{
	inFile >> fn >> ln >> ID >> em;
	for(int i = 0; i < 7; i++)
		inFile>> qz[i];
		for(int j = 0; j < 5; j++)
			inFile >> prog[j];
			for(int k = 0; k < 3; k++)
				inFile >> ex[k];
	inFile >> fin;
	}
	inFile.close();
}

void info(string& fn, string& ln, double& ID, string& em)
{
	cout << "Student's current information"<< endl << endl;
	cout << "Student name:   " << fn << " "<< ln << endl;
	cout << "Student ID#:    " << ID << endl;
	cout << "Email address:  " << em << endl << endl;
}

void results(double qz[], const int qztot[],double prog[],const int progtot[], double ex[],const int extot[], double& fin,const int fintot)
{
	cout << "Quiz Scores"<< endl;
	for (int i = 0; i < 7; i++)
		cout << qz[i]/qztot[i]*100 << space;
	cout << endl;
	cout << "Program Scores"<< endl;
	for (int j = 0; j < 5; j++)
		cout << prog[j]/progtot[j]*100 << space;
	cout << endl;	 
	cout << "Exam Scores" << endl;
	for (int k = 0; k < 3; k++)
		cout << ex[k]/extot[k]*100 << space;
	cout << endl;	
	cout << "Final Exam Score" << endl;
		cout << fin/fintot*100 << space;	
	cout << endl;	
}

double pecentage(int num, double category[],const int total)
{
	double ans = 0;
	for(int i = 0; i < num; i++)
		ans += category[i];
	
	return ans/total*100;
}

double Best_of_Three(double ex[],const int extot[])
{
	double ans[3];
	double solution = 0;
	double capture = 0;
	for(int i = 0; i < 3; i++)
		{
		ans[i] = ex[i]/extot[i]*100;
		capture += ans[i];
		}
	for(int j = 0; j < 3; j++)
	{
		if (ans[j] < ans[2-j])
			solution = ans[j];		
	}
	if(solution != 0)
		solution = (capture - solution)/200*100;	
	else if(solution == 0)
		solution = (ans[0]+ans[1])/200*100; 
	
		return solution;
}
