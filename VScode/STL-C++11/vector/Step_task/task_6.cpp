#include <iostream>
#include <string>
#include <vector>
#include <time.h>
typedef int StudentYear;
typedef double StudentAverageGrade;
typedef std::vector<int> StudentRating;
struct Student
{
    struct FullName
    {
        std::string name;
        std::string surname;
    };
    FullName fullName;
    StudentYear year;
    StudentRating rating;
    StudentAverageGrade averageGrade;
};
int main()
{
    std::vector<Student> students;
begin:
    int input;
    std::cout << "\nSelect action:\n1. Add student\n2. Show best students\nAny other number stops program...\n> ", std::cin >> input;
    switch (input)
    {
    case 1:
    {
        Student newStudent;
        std::cout << "Name: ", std::cin >> newStudent.fullName.name;
        std::cout << "Surname: ", std::cin >> newStudent.fullName.surname;
        std::cout << "Study year: ", std::cin >> newStudent.year;
        for (int i = 0; i < 5; i++)
        {
            int grade;
            std::cout << "Grade: ", std::cin >> grade;
            newStudent.rating.push_back(grade);
        }
        int sum = 0;
        for (int grade : newStudent.rating)
            sum += grade;
        newStudent.averageGrade = sum / 5.0;
        std::cout << "AverageGrade: " << newStudent.averageGrade << "\n";
        students.push_back(newStudent);
        goto begin;
        break;
    }
    case 2:
    {
        int i = 1;
        if (students.size() > 0)
        {
            double avgGrade = 0;
            for (Student student : students)
                avgGrade += student.averageGrade;
            std::cout << "Grade sum: " << avgGrade << "\n";
            avgGrade = avgGrade / students.size();
            std::cout << "Average grade: " << avgGrade << "\n";
            for (Student student : students)
                if (student.averageGrade > avgGrade)
                    std::cout << "\nStudent #" << i++ << "\nName: " << student.fullName.name << "\nSurname: " << student.fullName.surname << "\nStudy year: " << student.year << "\nAverage grade: " << student.averageGrade << "\n";
        }
        if (i == 1)
            std::cout << "No such students...\n";
        goto begin;
        break;
    }
    }
    return 0;
}