#include <iostream>
#include <istream>
#include <stdio.h>
#include <conio.h>
#include <string>
#include <fstream>
void login();
void main_menu();
void gpa(float*, char*, float, float, float, float, float);
void create_record();
void display_record();
void display_specific();
void modify_record();
void change_pass();
void delete_record();
using namespace std;
char grade;
float cp_marks, calculus_marks, english_marks, ict_marks, physics_marks;
float  cgpa, percentage;
float totalmarks = 500;
int n;
struct birthday
{
	int day;
	int month;
	int year;
};
struct student
{
	char name[50], Class[40]; // cstring , character array used //
	char grade;
	birthday b;
	int enroll;
	float cgpa;
} s, * ptr = &s;
int main()
{

	system("color 3f");
	login();
	_getch();
}
void main_menu()
{
	int op;
	char x;
	do
	{
		cout << " \n \n \n ";
		cout << " \t \t ";
		cout << " ----------------------------------------------------------" << endl;
		cout << " \t \t ";
		cout << "\t   STUDENT RECORD SYSTEM WITH GPA CALCULATOR " << endl;
		cout << " \t \t ";
		cout << " ----------------------------------------------------------" << endl;
		cout << "\n \t Enter your choice  \n";
		cout << "\t 1 for gpa calculation \n";
		cout << "\t 2 for creating student record \n";
		cout << "\t 3 for displaying overall record \n";
		cout << "\t 4 for displaying specific record \n";
		cout << "\t 5 for modifying the record \n";
		cout << "\t 6 for changing the username & password \n";
		cout << "\t 7 for deleting the record \n";
		cout << " \t ";
		cin >> op;
		switch (op)
		{
		case 1:
			fflush(stdin);
			cout << "\n Enter the marks in Computer out of 100 :  ";
			cin >> cp_marks;
			cout << " \n Enter the marks in Calculus out of 100 :  ";
			cin >> calculus_marks;
			cout << "\n Enter the marks in English out of 100 :  ";
			cin >> english_marks;
			cout << "\n Enter the marks in ICT out of 100 :  ";
			cin >> ict_marks;
			cout << "\n Enter the marks in Physics out of 100 :  ";
			cin >> physics_marks;
			fflush(stdin);
			gpa(&cgpa, &grade, cp_marks, calculus_marks, english_marks, ict_marks, physics_marks);
			cout << "\n cgpa : " << cgpa;
			cout << "\n grade : " << grade;
			break;
		case 2:
			create_record();
			break;
		case 3:
			display_record();
			break;
		case 4:
			display_specific();
			break;
		case 5:
			modify_record();
			break;
		case 6:
			change_pass();
			break;
		case 7:
			delete_record();
			break;
		default: cout << "\n Invalid choice \n";
		}
		cout << "\n do you want to continue ? \n \n";
		cout << " Press y or Y for yes & n or N for No \n";
		cin >> x;
		if (x == 'y' || x == 'Y')
		{
			system("cls");
		}
		else if (x == 'n' || x == 'N')
		{
			exit(0);
		}
	} while (x == 'y' || x == 'Y');
}
void gpa(float* ptr, char* pt, float a, float b, float c, float d, float e)
{
	float totalmarks = 500, cgpa;
	char grade;
	float percentage;
	percentage = (a + b + c + d + e) / totalmarks;
	*ptr = percentage * 4;

	if (*ptr >= 3.5)
	{
		*pt = 'A';

	}
	else if (*ptr >= 3 && *ptr < 3.5)
	{
		*pt = 'B+';
	}
	else if (*ptr >= 2.5 && *ptr < 3)
	{
		*pt = 'B';

	}
	else if (*ptr >= 2 && *ptr < 2.5)
	{
		*pt = 'C';

	}
	else if (*ptr >= 1.5 && *ptr < 2)
	{
		*pt = 'D';

	}
	else
	{
		*pt = 'F';
	}

}

void login()
{
	string username, uname;
	int pass, pass1;
	char x = 'y';
	while (x == 'y' || x == 'Y')
	{
		cout << "\n Username : ";
		cin >> username;
		cout << "\n Password : ";
		cin >> pass;
		ifstream read;
		read.open("user_name.txt");
		getline(read, uname);
		read.close();
		ifstream password;
		password.open("pass.txt");
		password >> pass1;
		password.close();
		if (username == uname && pass == pass1)
		{
			system("cls");
			main_menu();
		}
		else {

			cout << " \n Inavlid login \n";
			cout << " do you want to continue ? \n";
			cout << " press Y or y for yes & n or N for No : \n";
			cin >> x;

		}
		if (x == 'y' || x == 'Y')
		{
			system("cls");
		}
		else
		{
			exit(0);
		}

	}
}

void create_record()
{

	cout << "\n for how many students you want to create a record ? \n";
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		fflush(stdin);
		cout << "\n Enter the name of student  : ";
		cin.get(s.name, 50);
		fflush(stdin);
		cout << " \n Enter the class & section  : ";
		cin.get(s.Class, 40);
		fflush(stdin);
		cout << "\n Enter the enrollment of the student  : ";
		cin >> ptr->enroll;
		fflush(stdin);
		cout << "\n Enter date of birth : ";
		cin >> ptr->b.day >> s.b.month >> ptr->b.year;
		fflush(stdin);
		cout << "\n Enter the cgpa :  ";
		cin >> ptr->cgpa;
		fflush(stdin);
		cout << "\n Enter the grade : ";
		cin >> ptr->grade;
		cout << endl;
		ofstream write;
		write.open("student_record.txt", ios::app);
		write << "\n Name of the student : " << s.name << endl;
		write << " Class of the student : " << s.Class << endl;
		write << " Enrollment of the student : " << ptr->enroll << endl;
		write << " Date of Birth of the student : " << ptr->b.day << "/" << s.b.month << "/" << s.b.year << endl;
		write << " CGPA of student : " << ptr->cgpa << endl;
		write << " Grade of student : " << ptr->grade << endl << endl;
		write.close();
	}
}

void display_record()
{
	string name;

	ifstream read;
	read.open("student_record.txt");
	if (read.is_open())
	{
		while (!read.eof())
		{
			getline(read, name);
			cout << name << endl;
		}
		read.close();
	}
	else
		cout << "\n Unable to open file " << endl;

}

void delete_record()
{
	ofstream del;
	string s = "";
	del.open("student_record.txt");
	if (del.is_open())
	{
		del << s;
		cout << "\n Record deleted \n";
	}
	else
		cout << "\n Unable to open the file \n";
}

void modify_record()
{
	int id;
	cout << "\n Enter the id you want to modify : ";
	cin >> id;
	if (id == s.enroll)
	{
		cout << " \n id found : \n";
		cout << " Name of the student : ";
		cin >> s.name;
		cout << "\n Class of the student : ";
		cin >> s.Class;
		cout << "\n Enrollment of the student : ";
		cin >> ptr->enroll;
		cout << "\n Date of Birth of the student : ";
		cin >> ptr->b.day >> s.b.month >> s.b.year;
		cout << "\n CGPA of student : ";
		cin >> ptr->cgpa;
		cout << " Grade of student : ";
		cin >> ptr->grade;
	}
}


void change_pass()
{
	string username, uname;
	int pass, pass1;
	cout << "\n Enter the current username : ";
	cin >> username;
	cout << "\n Enter current password : ";
	cin >> pass;
	ifstream read;
	read.open("user_name.txt");
	if (read.is_open())
	{
		getline(read, uname);
		read.close();
	}
	else
	{
		cout << "\n Unable to open the file \n";
	}
	ifstream reead;
	reead.open("pass.txt");
	if (reead.is_open())
	{
		reead >> pass1;
		reead.close();
	}
	else
	{
		cout << "\n Unable to open the file \n";
	}
	if (uname == username && pass == pass1)
	{
		ofstream write;
		string user;
		write.open("user_name.txt");
		if (write.is_open())
		{
			cout << "\n Enter the new username : ";
			cin >> user;
			write << user;
			write.close();
			cout << "\n username successfully changed \n";
		}
		else
		{
			"\n Unable to open the file \n";
		}

		int passw;
		ofstream wriite;
		cout << "\n Enter the new password : ";
		cin >> passw;
		wriite.open("pass.txt");
		if (wriite.is_open())
		{
			wriite << passw;
			wriite.close();
			cout << "\n password successfully changed \n";
		}
		else
		{
			cout << "\n Unable to open the file \n";
		}
	}
	else
	{
		cout << "\n Incorrect username or password! Try Again : ";
	}

}
void display_specific()
{
	int id;
	cout << "\n Enter the id you want to search : ";
	cin >> id;
	if (id == s.enroll)
	{
		cout << " \n id found : \n";
		cout << " Name of the student : " << s.name << endl;
		cout << " Class of the student : " << s.Class << endl;
		cout << " Enrollment of the student : " << ptr->enroll << endl;
		cout << " Date of Birth of the student : " << ptr->b.day << "/" << s.b.month << "/" << s.b.year << endl;
		cout << " CGPA of student : " << ptr->cgpa << endl;
		cout << " Grade of student : " << ptr->grade << endl << endl;
	}

}
