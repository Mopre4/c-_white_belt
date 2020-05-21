#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <vector>

using namespace std;

struct Student{
    string name;
    string last_name;
    int day;
    int month;
    int year;
};

using namespace std;
int main(){
    vector <Student> students;
    Student student;
    int N;
    string new_name, new_last_name;
    int new_day, new_month, new_year;
    cin >> N;
    for(int i = 0; i < N ; i++ ){
        cin >> new_name >> new_last_name >> new_day >>
        new_month >> new_year;
        student.name = new_name;
        student.last_name = new_last_name;
        student.day = new_day;
        student.month = new_month;
        student.year = new_year;
        students.push_back(student);
    }
    int M;
    cin >> M;
    string request;
    int student_number;
    for(int i = 0; i < M ; i++){
        cin >> request >> student_number;
        --student_number;
        if(request == "name" && student_number >=0 && student_number < N){
            cout << students[student_number].name << " " <<
                    students[student_number].last_name<< endl;
        } else if (request == "date" && student_number >=0 && student_number < N){
            cout << students[student_number].day << "." <<
                    students[student_number].month << "." <<
                    students[student_number].year << endl;
        } else cout << "bad request" <<endl;
    }
    return 0;
}