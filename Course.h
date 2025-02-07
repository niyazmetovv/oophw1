#ifndef COURSE_H
#define COURSE_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Student;

class Course {
private:
    string id;
    string name;
    int credits;
    vector<int> students;

public:
    Course(string courseId, string courseName, int courseCredits) {
        this->id = courseId;
        this->name = courseName;
        this->credits = courseCredits;
    };
    string getId();
    string getName();
    int getCredits();
    bool hasStudent(Student& student);
    void addStudent(Student& student);
    void dropStudent(Student& student);
    void printDetails();
    vector<int>& getEnrolledStudents();
};

#endif // COURSE_H
