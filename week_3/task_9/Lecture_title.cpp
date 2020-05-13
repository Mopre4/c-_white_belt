#include "iostream"
#include "string"
using namespace std;

struct Specialization{
    explicit Specialization(const string new_name){
        name = new_name;
    }
    string name;
};

struct Course{
    explicit Course(const string new_name){
        name = new_name;
    }
    string name;
};

struct Week{
    explicit Week(const string new_name){
        name = new_name;
    }
    string name;
};

struct LectureTitle {
    string specialization;
    string course;
    string week;

    LectureTitle(const Specialization &new_specialization,
                const Course &new_course,
                const Week &new_week){
        specialization = new_specialization.name;
        course = new_course.name;
        week = new_week.name;
    }

};

int main(){
    LectureTitle title(
            Specialization("C++"),
            Course("White belt"),
            Week("4th")
    );

}