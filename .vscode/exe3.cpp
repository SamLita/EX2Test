#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

struct Student {
    int id;
    string name;
    vector<float> scores;
};


float calculateAverage(Student student) {
    float sum = 0.0;
    for (float score : student.scores) {
        sum += score;
    }
    return sum / student.scores.size();
}

float calculateGPA(float average) {
    if (average >= 90) return 4.0;
    if (average >= 80) return 3.0;
    if (average >= 70) return 2.0;
    if (average >= 60) return 1.0;
    return 0.0;
}

string calculateGrade(float gpa) {
    if (gpa == 4.0) return "A";
    if (gpa == 3.0) return "B";
    if (gpa == 2.0) return "C";
    if (gpa == 1.0) return "D";
    return "E";
}

void printStudentStatistics(vector<Student> students) {
    cout << "------------------------------------------------------------\n";
    cout << "| Student ID | Name      | Average Score |  GPA | Grade |\n";
    cout << "------------------------------------------------------------\n";
    
    for (Student student : students) {
        float average = calculateAverage(student);
        float gpa = calculateGPA(average);
        string grade = calculateGrade(gpa);
        
        cout << "| " << setw(10) << student.id << " | " 
             << setw(10) << student.name << " | " 
             << setw(13) << fixed << setprecision(2) << average << " | " 
             << setw(4) << gpa << " | "
             << setw(6) << grade << " |\n";
    }
}

int main() {
    vector<Student> students = {
        {1, "Alice", {85.5, 90.0, 87.0}},
        {2, "Bob", {75.0, 80.0, 78.8}},
        {3, "Charlie", {91.0, 93.5, 89.0}},
        {4, "David", {68.0, 70.0, 72.0}},
        {5, "Eve", {60.0, 65.0, 63.5}}
    };
    
    printStudentStatistics(students);
    
    return 0;
}
