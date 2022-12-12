//**********************************************************************
// File:       main.cpp
// Author:     CS, Pacific University
// Date:       12/11/22
// Class:      CS 150-XX
// Assignment: Final Exam Review
// Purpose:    Read from file into struct, count data meeting critera
// Hours:			 0.5
//**********************************************************************

#include <iostream>
#include <fstream>
#include <string> 

using namespace std;

struct StudentInfo {
	int mId;
	int mEntryYear;
	double mGpa;
};

int readStudentInfo (StudentInfo sStudents[]);

int getGPAData (const StudentInfo sStudents[], const int numStudents,
							  const double gpa);

/***********************************************************************
Function:			readStudentInfo

Description:	read students from file into array, count students

Parameters:		sStudents   - array of students

Returned:			number of students in the array
***********************************************************************/

int main () {
	const double GPA_TO_FIND = 3.2;
	const int MAX_SIZE = 1000;

	int numStudents; 
 
	StudentInfo sStudents[MAX_SIZE];

	numStudents = readStudentInfo(sStudents);

	// sample function call with gpa = 3.2

	cout << "Number of students with GPA of " << GPA_TO_FIND << " is: "
		   << getGPAData(sStudents, numStudents, GPA_TO_FIND);

	return EXIT_SUCCESS;
}

/***********************************************************************
Function:			readStudentInfo

Description:	read students from file into array, count students

Parameters:		sStudents   - array of students

Returned:			number of students in the array
***********************************************************************/
int readStudentInfo (StudentInfo sStudents[]) {
	const string INPUT_FILE = "student.txt";
	int numStudents = 0; 
	int tempId;
	int tempEntryYear;
	double tempGPA;;
	ifstream inputFile;

	inputFile.open (INPUT_FILE);

	if (inputFile.fail ()) {
		cout << "Couldn't open file";
		exit (EXIT_FAILURE);
	}

	inputFile >> tempId >> tempEntryYear >> tempGPA;

	while (tempId != -9999) {
		sStudents[numStudents].mId = tempId;
		sStudents[numStudents].mEntryYear = tempEntryYear;
		sStudents[numStudents].mGpa = tempGPA; 

		numStudents++;  
		inputFile >> tempId >> tempEntryYear >> tempGPA;
	}

	return numStudents; 
}

/***********************************************************************
Function:			getGPAData

Description:	count number of students with given gpa

Parameters:		sStudents   - array of students 
							numStudents - number of students
							gpa         - gpa to find 

Returned:			number of students with the given gpa
***********************************************************************/
int getGPAData(const StudentInfo sStudents[], int const numStudents,
							 const double gpa) {
	int countGPA = 0;

	for (int index = 0; index < numStudents; ++index) {
		if (gpa == sStudents[index].mGpa) {
			++countGPA;
		}
	}
	return countGPA;
}