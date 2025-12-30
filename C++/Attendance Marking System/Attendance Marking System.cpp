#include <iostream>
#include <string>
using namespace std;

struct Attendance {
    string date;
    bool present = false;
};

struct Student {
    string name;
	Attendance attendances[365];
};

Student students[100];
int student_count = 0;
int date_count = 0;

void teacher_dashboard();
void student_dashboard();
void add_student();
void mark_attendance();
void view_attendance_report();

void main_menu()
{
    while (true) {
        int choice;
        cout << "*******************************" << endl;
        cout << "*  Attendance Marking System  *" << endl;
        cout << "*******************************" << endl;
        cout << "1. Teacher Dashboard" << endl;
        cout << "2. Student Dashboard" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Redirecting to Teacher Dashboard..." << endl;
            teacher_dashboard();
            break;
        case 2:
            cout << "Redirecting to Student Dashboard..." << endl;
            student_dashboard();
            break;
        case 3:
            cout << "Exiting the system. Goodbye!" << endl;
            exit(0);
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    }
}

void teacher_dashboard()
{
    const string pw="admin123";
	string input_pw;
    int choice;
	cout << "Enter Teacher Password: ";
	cin >> input_pw;
    if (input_pw == pw) {
        while (true) {
            cout << "--- Teacher Dashboard ---" << endl;
            cout << "1. Add Student" << endl;
            cout << "2. Mark Attendance" << endl;
            cout << "3. View Attendance Report" << endl;
            cout << "4. Logout" << endl;
            cout << "Enter your choice: ";
            cin >> choice;
            switch (choice) {
            case 1:
                add_student();
                break;
            case 2:
                mark_attendance();
                break;
            case 3:
                view_attendance_report();
                break;
            case 4:
                cout << "Logging out from Teacher Dashboard..." << endl;
                return;
            default:
                cout << "Invalid choice. Returning to main menu." << endl;
            }
        }
    }
    else {
        cout << "Incorrect Password. Access Denied." << endl;
    }
}

void add_student()
{
    string name;
    cout << "Enter Student Name to Add: ";
    getline(cin >> ws, name);
    cout << "Student " << name << " added successfully." << endl;
    if (student_count<100){
        students[student_count].name = name;
        student_count++;
    }
    else {
        cout << "Student limit reached. Cannot add more students." << endl;
	}
    return;
}

void mark_attendance()
{
    string date;
    cout << "Enter Date (DD-MM-YYYY): ";
    cin >> date;
    cout << "Marking attendance for " << date << endl;
    for (int i = 0; i < student_count; i++) {
        char status;
        cout << "Is " << students[i].name << " present? (y/n): ";
        cin >> status;
        students[i].attendances[date_count].date = date;
		students[i].attendances[date_count].present = (status == 'y' || status == 'Y');
    }
	date_count++;
}

void view_attendance_report()
{
    cout << "--- Attendance Report ---" << endl;
    for (int i = 0; i < student_count; i++) {
        cout << "Student: " << students[i].name << endl;
        for (int j = 0; j < date_count; j++) {
            if (!students[i].attendances[j].date.empty()) {
                cout << "Date: " << students[i].attendances[j].date
                    << " - " << (students[i].attendances[j].present ? "Present" : "Absent") << endl;
            }
        }
        cout << "-------------------------" << endl;
    }
}

void student_dashboard()
{
    string name;
    cout << "--- Student Dashboard ---" << endl;
    cout << "Enter your name: ";
	getline(cin >> ws, name);
	for (int i = 0; i < student_count; i++) {
        if (students[i].name == name) {
            cout << "Attendance Record for " << name << ":" << endl;
            for (int j = 0; j < date_count; j++) {
                if (!students[i].attendances[j].date.empty()) {
                    cout << "Date: " << students[i].attendances[j].date
                        << " - " << (students[i].attendances[j].present ? "Present" : "Absent") << endl;
                }
            }
            return;
        }
    }
    cout << "Student not available." << endl;
}

int main()
{
    main_menu();
    return 0;
}


