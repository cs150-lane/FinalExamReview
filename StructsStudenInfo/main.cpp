#include <iostream>
#include <fstream>

using namespace std;

struct StudentInfo {
	int mId;
	int mEntryYear;
	double mGpa;
};

int readStudentInfo (StudentInfo sStudents[]);

int getGPAData(const StudentInfo sStudents[], const int numStudents,
							 const double gpa);

int main () {
	int numStudents; 
	int numGPA; 
	StudentInfo sStudents[1000];

	numStudents = readStudentInfo(sStudents);

	// sample function call with gpa = 3.20

	cout << "Number of students with GPA of 3.20 is "
		   << getGPAData(sStudents, numStudents, 3.20);

	return EXIT_SUCCESS;
}

int readStudentInfo (StudentInfo sStudents[]) {
	int numStudents = 0; 
	int tempId;
	int tempEntryYear;
	double tempGPA;;
	ifstream inputFile;

	inputFile.open("student.txt");

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