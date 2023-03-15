#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

//############################################################# Student Class
class Student
{
	public:
		string StudentID;
		string StudentName;
		int passed;//number of passed courses.
		string Courses[40];//will store course codes. course code is string
		double Grades[40];//indexes are corresponding to the courses array

	public:
		Student();
		Student(string id, string name, int pass);
		void addPassedCourse(string courseCode, double grade);
		void calculateCGPA();
};
Student::Student()
{
}

Student::Student(string id, string name, int pass)
:StudentID(id),StudentName(name), passed(pass)
{
}

void Student::addPassedCourse(string courseCode, double grade)
{
}

void Student::calculateCGPA()
{
}


//############################################################# Course Class
class Course
{
	public:
		string CourseCode;
		string CourseName;
		string Semester;
		string Teacher;
	public:
		Course();
		Course(string code, string name, string sem, string t);
};

Course::Course()
{
}

Course::Course(string code, string name, string sem, string t)
:CourseCode(code), CourseName(name), Semester(sem), Teacher(t)
{
}


//#############################################################
//Application has its global data and functions here
Student students[100];//maximum hundred students
Course courses[20];//maximum 20 courses
int nos=0;
int noc=0;

void loadStudentData()
{
	//############################Student Data
	ifstream input("students.txt");
	
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
		temp>>stdPassedCourses;
		
		Student s(stdID, stdName, stdPassedCourses);
		students[nos]=s;
//		cout<<students[nos].StudentName<<endl;

		string course;
		string str_grade;
		double grade;
		for(int i=0;i<stdPassedCourses;i++)
		{
			getline(linestream, course, ',');
			getline(linestream, str_grade, ',');
			stringstream tempgrade(str_grade);
			tempgrade>>grade;
//			cout<<course<<"--"<<grade<<endl;
			students[nos].Courses[i]=course;
			students[nos].Grades[i]=grade;
		}
		nos++;
	}
	input.close();
}

//############################Course Data
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
		courses[noc]=c;
		noc++;
//		cout<<courses[noc].CourseName<<endl;
	}
	input2.close();
}


void saveCourseData()
{
	ofstream output("courses.txt");
	output<<"course_code,course_name,semester,teacher"<<endl;
	for(int i=0;i<noc;i++)
	{
		output<<courses[i].CourseCode<<","<<courses[i].CourseName<<","<<courses[i].Semester<<","<<courses[i].Teacher;
		if(i!=noc-1)
		{
			output<<endl;
		}
	}
	cout<<"Course Data Saved"<<endl;
	output.close();
}

void saveStudentData()
{
	ofstream output("students.txt");
	output<<"StudentID, Name, Number_of_passed_courses,coursecode,grade_point......"<<endl;
	for(int i=0;i<nos;i++)
	{
		output<<students[i].StudentID<<","<<students[i].StudentName<<","<<students[i].passed<<",";
		for(int j=0;j<students[i].passed;j++)
		{
			output<<(string)(students[i].Courses[j])<<","<<students[i].Grades[j];
			if(j!=students[i].passed-1)
			{
				output<<",";
			}	
		}
		
		if(i!=nos-1)
		{
			output<<endl;
		}
	}
	cout<<"Student Data Saved"<<endl;
	output.close();
}


int main()
{
	
	cout<<"##### Welcome to Student Management System #####"<<endl;
	cout<<"##### Loading Data from Files #####"<<endl;
	loadStudentData();
	cout<<"##### Student Data Loaded #####"<<endl;
	loadCourseData();
	cout<<"##### Course Data Loaded #####"<<endl<<endl;
	
	int x;
	do
	{
		cout<<"\n\nEnter 1-8 to select a menu option. 0 to Exit."<<endl;
		cout<<"1-Add New Student"<<endl;
		cout<<"2-Delete Student"<<endl;
		cout<<"3-Add New Course"<<endl;
		cout<<"4-Delete Course"<<endl;
		cout<<"5-Add Passed Course for an Student"<<endl;
		cout<<"6-Print Student CGPA"<<endl;
		cout<<"7-Print Student List"<<endl;
		cout<<"8-Print Course List"<<endl;
		cout<<"0-Exit"<<endl<<endl;

		cin>>x;
		if(x==1)
		{
			
		}
		else if(x==2)
		{
			
		}
		else if(x==3)
		{
			
		}
		else if(x==4)
		{
			
		}
		else if(x==5)
		{
			
		}
		else if(x==6)
		{
			
		}
		else if(x==7)
		{
			
		}
		else if(x==8)
		{
			
		}
		else if(x==0)
		{
			cout<<"Exiting"<<endl;
		}
		else
		{
			cout<<"****Wrong Input****"<<endl;
		}
	}
	while(x!=0);
	
	saveStudentData();//save data before exiting
	saveCourseData();

	return 0;
}

