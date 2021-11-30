#include <iostream>

using namespace std;

class Employee {
public:
    virtual int earning(int hour) const = 0;

protected:
    const static long int salary = 14000000;
};

class FullTime : public Employee {
public:
    int earning(int hour) const override;

private:
    const static int working_hour = 140;
};

int FullTime::earning(int hour) const {
    return salary + (salary / working_hour) * 3 / 2 * (working_hour - hour);
}

class PartTime : public Employee {
public:
    int earning(int hour) const override;
};

int PartTime::earning(int hour) const {
    return salary * hour;
}

