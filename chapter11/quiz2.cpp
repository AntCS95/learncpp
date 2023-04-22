/*
Question #2

Write the following program : 
Create a struct that holds a student’s first name and grade
(on a scale of 0 - 100).
Ask the user how many students they want to enter.
Create a std::vector to hold all of the students.
Then prompt the user for each name and grade.
Once the user has entered all the names and grade pairs,
sort the list by grade(highest first)
Then print all the names and grades in sorted order.

For the following input :

Joe
82
Terry
73
Ralph
4
Alex
94
Mark
88

The output should look like this:

Alex got a grade of 94
Mark got a grade of 88
Joe got a grade of 82
Terry got a grade of 73
Ralph got a grade of 4

You can assume that names don’t contain spaces and that input extraction
doesn’t fail.
*/

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

struct Student
{
	std::string name{};
	int grade{};
};

void getStudents(std::vector<Student> &students, int numberOfStudents)
{
	for (int i{ 0 }; i < numberOfStudents; ++i)
	{
		Student student{};
		std::cout << "Student #" << i + 1 << '\n';
		std::cout << "Name: ";
		std::cin >> student.name;
		std::cout << "Grade: ";
		std::cin >> student.grade;
		students.push_back(student);
	}
}

//bool cmp(const Type1 &a, const Type2 &b);
bool sortGrades(const Student& student1, const Student& student2)
{
	return student1.grade > student2.grade;
}


void sortStudents(std::vector<Student> &students)
{
	std::sort(students.begin(), students.end(), sortGrades);
}

void printStudents(std::vector<Student>& students)
{
	for (auto& student : students)
	{
		std::cout << student.name << " got a grade of " << student.grade;
		std::cout << '\n';
	}
}

void quiz2()
{
	//enter number of students
	std::cout << "How many students would you like to enter?: ";
	int numberOfStudents{};
	std::cin >> numberOfStudents;
	//get students input from user
	std::vector<Student> students;
	getStudents(students, numberOfStudents);
	//sort students
	sortStudents(students);
	//print students
	printStudents(students);
}