#include <iostream>

using namespace std;

struct StudentType {
    string studentFName;
    string studentLName;
    int testScore;
    char grade;
};

int main() {
    const int numStudents = 20;
    StudentType students[numStudents];
    int highestScore = 0;
    string highestScoreStudentName;

    for (int i = 0; i < numStudents; ++i) {
        cout << "Enter student " << i + 1 << "'s first name: ";
        cin >> students[i].studentFName;

        cout << "Enter student " << i + 1 << "'s last name: ";
        cin >> students[i].studentLName;

        cout << "Enter student " << i + 1 << "'s test score: ";
        cin >> students[i].testScore;

        if (students[i].testScore > highestScore) {
            highestScore = students[i].testScore;
            highestScoreStudentName = students[i].studentFName + " " + students[i].studentLName;
        }

        if (students[i].testScore >= 80) {
            students[i].grade = 'A';
        } else if (students[i].testScore >= 70) {
            students[i].grade = 'B';
        } else if (students[i].testScore >= 60) {
            students[i].grade = 'C';
        } else if (students[i].testScore >= 50) {
            students[i].grade = 'D';
        } else {
            students[i].grade = 'F';
        }

        cout << endl;
    }

    for (int i = 0; i < numStudents; ++i) {
        cout << students[i].studentFName << " " << students[i].studentLName << " - Test Score: " << students[i].testScore << ", Grade: " << students[i].grade << endl;
    }

    cout << "Student with the highest test score: " << highestScoreStudentName << " - Test Score: " << highestScore << endl;

    return 0;
}
