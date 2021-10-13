#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

struct Student{
	string name;
	string id;
	float moadel;
};

void getValue(vector<Student> &);
void avg(vector<Student>);

int main() {
	vector<Student> students(5);
	getValue(students);
	avg(students);
}

void getValue(vector<Student> &students){
	for(int i=0; i<students.size(); i++){
		cin >> students[i].name >> students[i].id >> students[i].moadel;
	}
}

void avg(vector<Student> students){
	float sum=0;
	for (int i=0; i<students.size(); i++){
		sum += students[i].moadel;
	}
	cout << "The average of " << students.size() << " students grades is: " <<  sum/students.size() << endl;
}
