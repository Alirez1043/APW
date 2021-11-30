#include <iostream>
#include <vector>
using namespace std;

class Employee{
public:
    virtual int earning(int hour) const = 0;
    const static long int salary = 14000000;
};

class Organisation{
public:
    int total_earning(int avg_hrs);

private:
    vector<Employee> employees;
};

int Organisation::total_earning(int avg_hrs) {
    return Employee::salary * avg_hrs;
}

class FullTime : public Employee {
public:
    int earning(int hour) const override;

private:
    const static int std_working_hour = 140;
};

int FullTime::earning(int hour) const {
    return salary + (salary / std_working_hour) * 3 / 2 * (std_working_hour - hour);
}

class PartTime : public Employee {
public:
    int earning(int hour) const override;
};

int PartTime::earning(int hour) const {
    return salary * hour;
}




