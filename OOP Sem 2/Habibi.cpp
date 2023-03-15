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
        void getData();
        void showData();
        void getpassing();
        string getID(){return StudentID;}
        
	public:
		Student();
		Student(string id, string name, int pass);
		void addPassedCourse(string courseCode, double grade);
		void calculateCGPA();
}s;
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
{   int no_of_courses;
    cout<<"Enter number of courses"<<endl;
    cin>>no_of_courses;
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

void Student::getData()
{
 cout<<"\n\nEnter Student Details......\n";
 cout<<"Enter Student ID     : "; cin>>StudentID;
 cout<<"Enter Full Name (don't use spaces)        : "; cin>>StudentName;
 cout<<"Enter passed subjects     : "; cin>>passed;
 
 cout<<endl;
}
void Student::getpassing()
{
 cout<<"\n\nEnter passed subjects ......\n";
 cout<<"Enter passed subjects     : "; cin>>passed;
 
 cout<<endl;
}
void addData()
{
 ofstream fout;
 fout.open("Students.dat",ios::binary|ios::out|ios::app);
 s.getData();
 fout.write((char*)&s,sizeof(s));
 fout.close();
 cout<<"\n\nData Successfully Saved to File....\n";
}

void Student::showData()
{
 cout<<"\n\n.......Student Details......\n";
 cout<<"Admission No.     : "<<StudentID<<endl;
 cout<<"Full Name         : "<<StudentName<<endl;
 cout<<"Passed Subjects           : "<<passed<<endl;
 cout<<endl;
}
void displayData()
{
 ifstream fin;
 fin.open("students.dat",ios::in|ios::binary);
 while(fin.read((char*)&s,sizeof(s)))
 {
  s.showData();
 }
 fin.close();
 cout<<"\n\nData Reading from File Successfully Done....\n";
}
void deleteData()
{
 string n; int flag=0;
 ifstream fin;
 ofstream fout,tout;

 fin.open("students.dat",ios::in|ios::binary);
 fout.open("TempStud.dat",ios::out|ios::app|ios::binary);
 tout.open("TrashStud.dat",ios::out|ios::app|ios::binary);

 cout<<"Enter ID Number you want to delete : ";
 cin>>n;
 
 while(fin.read((char*)&s,sizeof(s)))
 {
  if(n==s.getID())
  {
   cout<<"The Following Admission No. "<<n<<" has been moved to Trash:\n";
   s.showData();
   tout.write((char*)&s,sizeof(s));
   flag++;
  }
  else
  {
   fout.write((char*)&s,sizeof(s));
  }
 }
 fout.close();
 tout.close();
 fin.close();
 if(flag==0)
  cout<<"The Admission No. "<<n<<" not found....\n\n";
 remove("students.dat");
 rename("tempStud.dat","students.dat");
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
        void getCourse();
        void showCourse();
        string getcourseID(){return CourseCode;}
	public:
		Course();
		Course(string CourseCode, string CourseName, string Semester, string Teacher);
}c;

Course::Course()
{
}

Course::Course(string code, string name, string sem, string t)
:CourseCode(code), CourseName(name), Semester(sem), Teacher(t)
{
}
void Course::getCourse()
{
 cout<<"\n\nEnter Course Details......\n";
 cout<<"Enter Course Code:      : "; cin>>CourseCode;
 cout<<"Enter Course Name: (don't use spaces) "; cin>>CourseName;
 cout<<"Enter semester     : "; cin>>Semester;
 cout<<"Enter Teacher     : "; cin>>Teacher;
 cout<<endl;
}
void addCourse()
{
    ofstream fout;
 fout.open("courses.dat",ios::binary|ios::out|ios::app);
 c.getCourse();
 fout.write((char*)&c,sizeof(c));
 fout.close();
 cout<<"\n\nData Successfully Saved to File....\n";
}
void Course::showCourse()
{
  cout<<"\n\nEnter Course Details......\n";
 cout<<"Enter Course Code:      : " <<CourseCode<<endl;
 cout<<"Enter Course Name: "       <<CourseName<<endl;
 cout<<"Enter semester     : "     <<Semester<<endl;
   cout<<"Enter Teacher     : " <<Teacher<<endl;
   cout<<endl;
 
}
void displayCourse()
{
 ifstream fin;
 fin.open("courses.dat",ios::in|ios::binary);
 while(fin.read((char*)&c,sizeof(c)))
 {
  c.showCourse();
 }
 fin.close();
 cout<<"\n\nData Reading from File Successfully Done....\n";
}

void passedCourses()
{
 string n; int flag=0, pos;
 fstream fio;

 fio.open("students.dat",ios::in|ios::out|ios::binary);
 
 cout<<"Enter Admission Number you want to Modify : ";
 cin>>n;
 
 while(fio.read((char*)&s,sizeof(s)))
 {
  pos=fio.tellg();
  if(n==s.getID())
  {
   cout<<"The Following Admission No. "<<n<<" will be modified with new data:\n";
   s.showData();
   cout<<"\n\nNow Enter the New Details....\n";
   s.getpassing();
   fio.seekg(pos-sizeof(s));
   fio.write((char*)&s,sizeof(s));
   flag++;
  }
 }
 fio.close();
 
 if(flag==0)
  cout<<"The Admission No. "<<n<<" not found....\n\n";
}
void deleteCourse()
{
 string n; int flag=0;
 ifstream fin;
 ofstream fout,tout;

 fin.open("courses.dat",ios::in|ios::binary);
 fout.open("courseTempStud.dat",ios::out|ios::app|ios::binary);
 tout.open("courseTrashStud.dat",ios::out|ios::app|ios::binary);

 cout<<"Enter course ID you want to delete : ";
 cin>>n;
 
 while(fin.read((char*)&c,sizeof(c)))
 {
  if(n==c.getcourseID())
  {
   cout<<"The Following Admission No. "<<n<<" has been moved to Trash:\n";
   c.showCourse();
   tout.write((char*)&c,sizeof(c));
   flag++;
  }
  else
  {
   fout.write((char*)&c,sizeof(c));
  }
 }
 fout.close();
 tout.close();
 fin.close();
 if(flag==0)
  cout<<"The Admission No. "<<n<<" not found....\n\n";
 remove("courses.dat");
 rename("coursetempStud.dat","courses.dat");
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
	ifstream input("students.dat");
	
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
	ifstream input2("courses.dat");
	
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
	ofstream output("courses.dat");
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
	ofstream output("students.dat");
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
            addData();
        }
		else if(x==2)
		{   
          deleteData();
		}	
		
		else if(x==3)
		{
            addCourse();
		}
		else if(x==4)
		{
          deleteCourse();
		}
		else if(x==5)
		{
			passedCourses();
		}
		else if(x==6)
		{
			s.calculateCGPA();
		}
		else if(x==7)
		{
			displayData();
		}
		else if(x==8)
		{
			displayCourse();
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
	



	return 0;
}
