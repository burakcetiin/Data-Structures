#include <iostream>
#include <vector>
#include <algorithm>  
#include <string>
#include <fstream>
using namespace std;

//Contains the features of exam
class Exam
{
public:

	Exam(string _type, string _date, string _time) {
		type = _type;
		date = _date;
		time = _time;
	};
	Exam() {
	}
	~Exam() {
	};

	void setType(string _type) {
		type = _type;
	}
	string getType() {
		return type;
	}
	void setDate(string _date) {
		date = _date;
	}
	string getDate() {
		return date;
	}
	void setTime(string _time) {
		time = _time;
	}
	string getTime() {
		return time;
	}

private:
	string type, date, time;
};

//Contains the course code and a list of Exam objects
class Course
{
public:
	Course(string _code) {
		code = _code;
	};
	Course() {
	}
	~Course() {
	};

	//Adds a new Exam object to the exams list
	void add(Exam exam) {
		exams.push_back(exam);
	}

	void deleted(Exam exam, int i) {
		exams.erase(exams.begin() + i);
	}

	void printExams() {
		for (int i = 0; i < exams.size(); i++) {
			cout << exams.at(i).getType() << "   "
				<< exams.at(i).getDate() << "   "
				<< exams.at(i).getTime();
		}
	}

	void setCode(string _code) {
		code = _code;
	}
	string getCode() {
		return code;
	}

private:
	string code;
	vector<Exam> exams;
};

//Contains a list of Course objects
class ExamTable : public Course
{
public:
	ExamTable(){
	};
	~ExamTable() {
	};

	//Adds a new Course object to the exams list
	void add(Course course) {
		courses.push_back(course);
		cout << "Course added." << endl;
	}

	//Deletes the Course object from the exams list
	void deleted(Course course, int i) {
		courses.erase(courses.begin()+i);
		cout << "Course deleted." << endl;
	}

	void print() {
		cout << "Course" << "   "
			<< "Type" << "   "
			<< "Date" << "   "
			<< "Time" << endl;

		for (int i = 0; i < courses.size(); i++) {
			cout << courses.at(i).getCode() << "   ";
			courses.at(i).printExams();
			cout << endl;
		}
	}

	void read() {

		ifstream file;

		file.open("exams.txt");

		string line;
		while (getline(file, line)) {
			courses.push_back(line);
		}

		file.close();
	}

	void write() {
		ofstream MyFile("exams.txt");

		for (int i = 0; i < courses.size(); i++)
		{
			MyFile << courses[i] << endl;
		}
	

		MyFile.close();
	}

	void sorted() {
		sort(courses.begin(), courses.end());
		
		for (int i = 0; i < courses.size(); i++) 
			cout << i+1 << ". " << courses.at(i).getCode() << endl;			
	}

private:
	vector<Course> courses;
};

int main()
{
	Course course;
	Exam exam;
	ExamTable examtable;

	int user_choice = 0;
	string code;

	cout << "1. Display table" << endl
		<< "2. Add new course" << endl
		<< "3. Delete existing course" << endl
		<< "4. Add exam to existing course" << endl
		<< "5. Delete existing exam" << endl
		<< "6. Exit" << endl;

	while (user_choice != 6)
	{
		cout << "\nYour choice: ";
		cin >> user_choice;

		if (user_choice == 1)
		{
			examtable.print();
		}
		else if (user_choice == 2)
		{
			cout << "Enter course code: ";
			cin >> code;
			Course tmp(code);
			examtable.add(tmp);
		}
		else if (user_choice == 3)
		{
			cout << "Available courses: " << endl;
			examtable.sorted();

			int i;
			cout << "Which course: ";
			cin >> i;			
			examtable.deleted(course, i);
		}
		else if (user_choice == 4)
		{
			cout << "Available courses: " << endl;
			examtable.sorted();
			string ty, d, t;			

			cout << "Enter exam type, date and time: ";
			cin >> ty >> d >> t;
			Exam tmp(ty, d, t);	
			course.add(tmp);
		}
		else if (user_choice == 5)
		{
			cout << "Available exams: " << endl;
			examtable.sorted();

			int i;
			cout << "Which exam: ";
			cin >> i;
			course.deleted(exam, i);
		}
		else 
		{
			examtable.read();
			examtable.write();
			break;
		}			
	}
	cout << "Bye!";
}