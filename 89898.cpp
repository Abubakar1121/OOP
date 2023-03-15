#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

// Student Class
class Student
{

public:
	string StudentID;
	string StudentName;
	int passed;//number of passed courses.
	string Courses[40];//will store course codes. course code is string
	double Grades[40];//indexes are corresponding to the courses array

	Student() {
		//null constructor;
	};
	Student(string id, string name, int pass) {
		StudentID = id;
		StudentName = name;
		passed = pass;
	}
	
	void addPassedCourse(string courseCode, double grade) {
		//?
	}
	void calculateCGPA(int no_of_courses) {
		float o_marks;
		float sum = 0;
		int count = 1;
		cout << "Enter the marks for each course obtained" << endl;
		for (int i = 1; i <= no_of_courses; i++)
		{
			cout << "Subject no: " << count++ << endl;
			cin >> o_marks;
			sum += o_marks;
		}
		float t_marks = no_of_courses;
		float avg = (sum / no_of_courses);
		cout << "Expected CGPA: [ " << avg << " ] out of 100" << endl;
	}


};
//student class inhertied into course;
class Course :public Student
{
public:
	string CourseCode;
	string CourseName;
	string Semester;
	string Teacher;
	Course() {
		CourseCode = "NULL";
		CourseName = "NULL";
		Semester = "NULL";
	    Teacher = "NULL";
	};
	Course(string code, string c_name, string sem, string t) {
		CourseCode = code;
		CourseName = c_name;
		Semester = sem;
		Teacher = t;
	}

	friend class save_data;
};

class save_data:public Student
{


	//Application has its global data and functions here
	Student students[100];//maximum hundred students
	Course courses[20];//maximum 20 courses
	int nos = 0;
	int noc = 0;
public:
	void loadStudentData()
	{
		//Student Data
		ifstream input("students.txt",ios::in);

		string line;
		getline(input, line, '\n');//ignore first line

		while (getline(input, line, '\n')) //from 2nd line. One Line. Continue till end of file
		{
			stringstream linestream(line);//convert the string line to a stream so that we can use getline

			string stdID;
			getline(linestream, stdID, ',');//student ID
			string stdName;

			getline(linestream, stdName, ',');//student Name
			string stdPassed;

			getline(linestream, stdPassed, ',');//student passsed courses
			int stdPassedCourses;
			stringstream temp(stdPassed);
			temp >> stdPassedCourses;

			Student s(stdID, stdName, stdPassedCourses);
			students[nos] = s;
			//		cout<<students[nos].StudentName<<endl;

			string course;
			string str_grade;
			double grade;
			for (int i = 0; i < stdPassedCourses; i++)
			{
				getline(linestream, course, ',');
				getline(linestream, str_grade, ',');
				stringstream tempgrade(str_grade);
				tempgrade >> grade;
				//			cout<<course<<"--"<<grade<<endl;
				students[nos].Courses[i] = course;
				students[nos].Grades[i] = grade;
			}
			nos++;
		}
		input.close();
	}

	//Course Data
	void loadCourseData()
	{
		ifstream input2("courses.txt");

		string line2;
		getline(input2, line2, '\n');//ignore first line

		string courseCode;
		string courseName;
		string sem;
		string teacher;

		while (getline(input2, line2, '\n')) //from 2nd line. One Line. Continue till end of file
		{
			stringstream linestream2(line2);//convert the string line to a stream so that we can use getline

			getline(linestream2, courseCode, ',');//courseCode
			getline(linestream2, courseName, ',');//courseName
			getline(linestream2, sem, ',');//sem
			getline(linestream2, teacher, ',');//teacher

			Course c(courseCode, courseName, sem, teacher);
			courses[noc] = c;
			noc++;
			//		cout<<courses[noc].CourseName<<endl;
		}
		input2.close();
	}


	void saveCourseData()
	{
		ofstream output("courses.txt");
		output << "course_code,course_name,semester,teacher" << endl;
		for (int i = 0; i < noc; i++)
		{
			output << courses[i].CourseCode << "," << courses[i].CourseName << "," << courses[i].Semester << "," << courses[i].Teacher;
			if (i != noc - 1)
			{
				output << endl;
			}
		}
		cout << "Course Data Saved" << endl;
		output.close();
	}

	void saveStudentData()
	{
		ofstream output("students.txt");
		output << "StudentID, Name, Number_of_passed_courses,coursecode,grade_point......" << endl;
		for (int i = 0; i < nos; i++)
		{
			output << students[i].StudentID << "," << students[i].StudentName << "," << students[i].passed << ",";
			for (int j = 0; j < students[i].passed; j++)
			{
				output << (string)(students[i].Courses[j]) << "," << students[i].Grades[j];
				if (j != students[i].passed - 1)
				{
					output << ",";
				}
			}

			if (i != nos - 1)
			{
				output << endl;
			}
		}
		cout << "Student Data Saved" << endl;
		output.close();
	}
	void option_menu() {
		cout << "Enter the choice from menu option." << endl;
		cout << "1-Add New Student" << endl;
		cout << "2-Delete Student" << endl;
		cout << "3-Add New Course" << endl;
		cout << "4-Delete Course" << endl;
		cout << "5-Add Passed Course for an Student" << endl;
		cout << "6-Print Student CGPA" << endl;
		cout << "7-Print Student List" << endl;
		cout << "8-Print Course List" << endl;
		cout << "0-Exit" << endl << endl;

	}
};
int main()
{
	
	string s_name,s_id;
	int passed;
	int x=1;
	Student s1;
	Course c1;
	save_data d1;
	cout << "+----------------------------------------------+" << endl;
	cout << "|   Welcome to Student Management System       |" << endl;
	cout << "+----------------------------------------------+" << endl;
	cout << "|    * Loading Data from Files                 | " << endl;
	d1.loadStudentData();
	cout << "|    * Student Data Loaded                     |" << endl;
	d1.loadCourseData();
	cout << "|    * Course Data Loaded                      |" << endl;
	cout << "+----------------------------------------------+" << endl;

	while ( x != 0)
	{
		d1.option_menu();
		cin >> x;
		switch (x)
		{
		case 1:
			cout << "Enter the Student Id" << endl;
			cin >> s_id;
			cout << "Enter the Student Name" << endl;
			cin >> s_name;
			cout << "Enter the Student course passed" << endl;
			cin >> passed;
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			break;
		case 6:

			cout << "Enter the number of courses passed" << endl;
			int c;
			cin >> c;
			s1.calculateCGPA(c);
			break;
		case 7:
			break;
		case 8:
			break;
		case 9:
			return 0;
			break;
		default:
			cout << "Invalid Command!!" << endl;
			break;
		}

		d1.saveStudentData();//save data before exiting
		d1.saveCourseData();
	} 


	return 0;
}
