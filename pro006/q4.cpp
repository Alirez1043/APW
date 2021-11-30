#include <iostream>
#include <vector>

using namespace std;

class EmployeeException : public exception {
public:
    explicit EmployeeException(string err);

    const char *what() const noexcept override;

private:
    string m_error;
    int m_working_hour;
};

EmployeeException::EmployeeException(string err) {
    m_error = err;
}

const char *EmployeeException::what() const noexcept {
    return m_error.c_str();
}

class Employee {
public:
    Employee(string name);
    
    virtual int earning(int hour) const = 0;

protected:
    string m_name;
};

Employee::Employee(string name) {
    m_name = name;
}

class FullTime : public Employee {
public:
    FullTime(string name);

    int earning(int hour) const override;

private:
    const static long m_salary = 14000000;
    const static int m_working_hour = 140;
};

int FullTime::earning(int hour) const {
    if (hour < 0) {
        throw EmployeeException("Full time minus working hour");
    } else if (hour < 140) {
        throw EmployeeException("Full time employee less than 140 hours work");
    }
    return m_salary + (m_salary / m_working_hour) * 3 / 2 * (m_working_hour - hour);
}

FullTime::FullTime(string name) : Employee(name) {}

class PartTime : public Employee {
public:
    PartTime(string name);

    int earning(int hour) const override;

private:
    // It's likely different from full time employee's salary
    const static long m_salary_per_hour = 200000;
};

int PartTime::earning(int hour) const {
    if (hour < 0) {
        throw EmployeeException("Part time minus working hour");
    }
    return m_salary_per_hour * hour;
}

PartTime::PartTime(string name) : Employee(name) {};

int main() {
    FullTime test("test");
    Employee *Test = &test;
    Employee *ali = new FullTime("Ali");
    Employee *reza = new PartTime("reza");
    Employee *ahmad = new PartTime("ahmad");
    Employee *sara = new FullTime("sara");
    vector<Employee *> employees{ali, reza, ahmad, sara, Test};
    for (auto &employee: employees) {
        cout << employee->earning(140) << endl;
        delete employee;
    }
}
