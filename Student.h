#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>
#include <vector>
#include "Course.h"

using namespace std;

class Student {
private:
    int id;
    string name;
    vector<int> enrolledCourses;
    static const int MAX_ALLOWED_CREDITS = 18;

public:
    Student(int id, string name) {
        this->id = id;
        this->name = name;
    };

    int getId();
    string getName();
    vector<int>& getEnrolledCourses();
    bool takesCourse(Course& course);
    bool takeCourse(Course& course);
    void dropCourse(Course& course);
    void printDetails();
};

#endif // STUDENT_H
