/*CS 161 Assignment 7: Arrays
Filename: a07.cpp
Author:   Pierce Heyerdahl
Date:     6/7/2017
Summary:  Takes scores and names from file "grades.txt" and calculates and outputs their averages score and letter grade.

Functions:
void grading(const int list[][5], int listSize, double list2[]) = calculates student's average score and stores it in a seperate array
void letterGrade(double list[], char list2[]) = calculates student's letter grade and stores it in a seperate array
void output(string list[], char list2[], double list3[]) = outputs all students' names, averages and letter grade

Input variables:
ifstream inFile = the file where the scores are located
string fileName = user inputed location of file
string studentNames[10] = array where the student's names are stored
int studentScores[10][5] = array where the student's scores are stored

Output variables:
double studentAverages[10] = array where the student's average scores are stored
char studentLetterGrades[10] = array where the student's letter grades are stored

Equations:
if (!inFile.is_open()) than the program displays and error and exits
while (inFile && studentNums < 10) names and scores are read from the inFile and stored in two seperate arrays
in void grading(const int list[][5], int listSize, double list2[]) for (row = 0; row < listSize; row++) the function calculates the average score and places it in a seperate array
in void letterGrade(double list[], char list2[]) for (int i = 0; i < 10; i++) the function checks each average and places its letter grade in a seperate array
in void output(string list[], char list2[], double list3[]) for (int i = 0; i < 10; i++) the function outputs the student's name, average score, and letter grade
*/

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
using namespace std;

void grading(int list[][5], int listSize, double list2[]);
void letterGrade(double list[], char list2[]);
void output(string list[], char list2[], double list3[]);

int main()
{
	ifstream inFile;
	string fileName;
	string studentNames[10];
	int studentScores[10][5];
	int studentNums = 0;
	int rowCount = 0;
	double studentAverages[10];
	char studentLetterGrades[10];
	
	cout << "Enter Filename" << endl; // gets file location from user
	getline(cin, fileName);
	cout << endl;
	inFile.open(fileName);

	if (!inFile.is_open()) // validate that file was found
	{
		cout << "Error: No File Detected" << endl << endl;
		exit(1);
	}

	while (inFile && studentNums < 10) // reads student's names and scores from file and stores in seperate arrays
	{
		inFile >> studentNames[studentNums];
		studentNums++;

		for (int x = 0; x < 5; x++)
		{
			inFile >> studentScores[rowCount][x];
		}

		rowCount += 1;
	}

	inFile.close(); // closes file
	
	grading(studentScores, 10, studentAverages); 
	letterGrade(studentAverages, studentLetterGrades); 
	cout << setprecision(1) << fixed;
	output(studentNames, studentLetterGrades, studentAverages); 

	return 0;
}

void grading(int list[][5], int listSize, double list2[]) // function to calculate student's averages 
{
	int row, col;
	double sum;
	
	for (row = 0; row < listSize; row++)
	{
		sum = 0;
		for (col = 0; col < 5; col++)
		{
			sum = sum + list[row][col];
		}
		list2[row] = sum / 5;
	}
}

void letterGrade(double list[], char list2[]) // function to calculate student's letter grades
{
	for (int i = 0; i < 10; i++)
	{
		if (list[i] >= 90)
		{
			list2[i] = 'A';
		}
		else if (list[i] >= 80)
		{
			list2[i] = 'B';
		}
		else if (list[i] >= 70)
		{
			list2[i] = 'C';
		}
		else if (list[i] >= 60)
		{
			list2[i] = 'D';
		}
		else
		{
			list2[i] = 'F';
		}
	}
}

void output(string list[], char list2[], double list3[]) // function that outputs names, averages, and letter grades
{
	cout << left << setw(10) << "Name" << setw(8) << "Average" << setw(4) << "Grade" << endl;

	for (int i = 0; i < 10; i++)
	{
		cout << left << setw(10) << list[i] << setw(8) << list3[i] << setw(4) << list2[i] << endl;
	}

	cout << endl;
}