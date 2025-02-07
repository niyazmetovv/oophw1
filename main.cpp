#include <iostream>
#include <string>
#include <vector>
#include "Student.h"
#include "Course.h"
#include "LMS.h"

using namespace std;

int main() {
    string nLMS;
    getline(cin, nLMS);
    LMS lms(nLMS);

    vector<Student> students;
    vector<Course> courses;

    int nSt;
    cin >> nSt;
    cin.ignore();

    for (int i = 0; i < nSt; i++) {
        int id;
        string name;
        cin >> id >> name;
        students.emplace_back(id, name);
        lms.addStudent(students.back());
    }

    int nc;
    cin >> nc;

    for (int i = 0; i < nc; i++) {
        string id, name;
        int credit;
        cin >> id >> name >> credit;
        courses.emplace_back(id, name, credit);
        lms.addCourse(courses.back());
    }

    int a;
    cin >> a;

    for (int i = 0; i < a; i++) {
        int sID;
        string cID;
        cin >> sID >> cID;

        int indexOfStudent = -1, indexOfCourse = -1;

        for (int j = 0; j < courses.size(); j++) {
            if (cID == courses[j].getId()) {
                indexOfCourse = j;
                break;
            }
        }
        if (indexOfCourse == -1) continue;

        for (int j = 0; j < students.size(); j++) {
            if (sID == students[j].getId()) {
                indexOfStudent = j;
                break;
            }
        }
        if (indexOfStudent == -1) continue;

        lms.addStudentToCourse(lms.getStudents(indexOfStudent), lms.getCourses(indexOfCourse));
    }

    lms.printDetails();
    return 0;
}
