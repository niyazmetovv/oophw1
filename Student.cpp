#include <iostream>
#include <string>
#include <vector>
#include "Student.h"
#include "Course.h"

using namespace std;

int Student::getId() {
    return id;
}

string Student::getName() {
    return name;
}

vector<int>& Student::getEnrolledCourses() {
    return enrolledCourses;
}

bool Student::takesCourse(Course& course) {
    for (int i = 0; i < enrolledCourses.size(); i++) {
        if (enrolledCourses[i] == stoi(course.getId())) {
            return true;
        }
    }
    return false;
}

bool Student::takeCourse(Course& course) {
    if (!takesCourse(course)) {
        if (course.getCredits() < MAX_ALLOWED_CREDITS) {
            enrolledCourses.push_back(stoi(course.getId()));
            return true;
        }
    }
    return false;
}

void Student::dropCourse(Course& course) {
    for (int i = 0; i < enrolledCourses.size(); i++) {
        if (enrolledCourses[i] == stoi(course.getId())) {
            enrolledCourses.erase(enrolledCourses.begin() + i);
            break;
        }
    }
}

void Student::printDetails() {
    cout << "Student ID: " << getId() << ", Name: " << getName() << endl;
    cout << "Enrolled Courses: ";
    for (int enrolledCourse : enrolledCourses) {
        cout << enrolledCourse << " ";
    }
    cout << endl;
}
