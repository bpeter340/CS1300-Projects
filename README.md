# CS1300-Projects

###### This repository contains a series of projects I have completed while taking CS1300 at Indiana Tech.

# Program 2

###### Program 2 Objective
Design and implement a program which will read in a text file that will fill an array of 100 random integers.

- [x] Print the array out in five columns (on screen and to a file)
- [x] Find the largest value – print with labels
- [x] Find the smallest value – print with labels
- [x] Print the array out in five columns starting at the highest index and going to the smallest index (reverse from a)
- [x] Calculate the mean, standard deviation, variance of the set of values
- [x] Print the answers calculated in step e with appropriate labels

## Design Documents
Design and implement a program which will read in a text file that will fill an array of 100 random integers. This array must then be sorted from smallest to largest, and vice versa. The maximum and minimum as well as standard deviation, variance and average of the array should then be calculated. The absolute output of this information should be replicated in a text file simultaneously.

Pre-conditions:
- No user input
- All data comes from text file
- Mostly functions containing for loops will be used

Post-conditions:
- Average, variance, standard dev., min and max will be calculated
- All output should replicate to a text file
- Array data is manipulated, for loops, and functions are manipulated to produce output
- Data is clear, nicely formatted and visible to users

# Program 3

###### Program 3 Objective

Write a program that uses a random number generator to generate a two digit positive intergerand allows the user to perform one or more of the following operations:

- [x] Double the number.
- [x] Reverse the digits of the number.
- [x] Raise the number to the power of 2, 3, or 4.
- [x] Sum the digits of the number.
- [x] If the number is a two digit number, then raise the first digit to the power of the second digit.
- [x] If the number is a three digit number and the last digit is less than or equal to 4, then raise the first two digits to the power of the last digit.

## Design Documents
Design and implement a program that manipulates random numbers and is semi-interactive with the user. The program should function in menu format, giving the user options as the follow the flow of the program. Be sure to make each operation dependent on the operations of the previous step.

Pre-conditions:
- User input is minimal
- Initial number is generated at random
- Program executes primarily using functions
- Each operation is dependent on the value of the previous operation
- Global variables are not allowed
- Values being processed are numbers greater or equal to 0 and less than 100

Post-conditions:
- All operations of the program work
- Data is well organized
- Output is accurate

# Program 4

###### Program 4 Objective

Write a program that reads the information for 5 students from a text file to populate a professors gradebook. Data for each student should be nicely formatted and displayed. Perform the folloing operations:
- [x] Calculate total quiz, program, exam, and final scores
- [x] Weigh grades accordingly
- [x] Take best 2 of 3 test scores
- [x] Determine letter grade associated with final scores

## Design Document
Design and implement a program that takes user input from a text file that inputs student identification and course scores. Scores should then be manipulated to calculate the weighted final score and the final score should be used to find the course grade.


Pre-conditions:
- User input comes from a text file
- Program restricts user input
- Information for 5 students are provided
- Data input is accurate
- A struct is used to store user data
- Best 2 of 3 exams can be found 

Post-conditions:
- Final course score and course grade are displayed and labeled
- Output is easy to follow
- Output accurately grades student’s work
- Students’ information is displayed separately and legibly


