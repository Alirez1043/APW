#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

class Date {
public:
    Date(int d, int m, int y);

    Date();

    void set_date(int d, int m, int y);

    bool operator==(const Date &date) const;

    friend ostream &operator<<(ostream &stream, const Date &date);

    Date &operator++(int);
    Date &operator++();

    Date &operator=(const string &date);

    int get_day() const { return day; }

    int get_month() const { return month; }

    int get_year() const { return year; }


private:
    int day;
    int month;
    int year;
};

Date::Date(int d, int m, int y) {
    //constructor
    set_date(d, m, y);
}

Date::Date() {
    //default constructor
    set_date(1, 1, 1390);
}


bool is_leap_year(int year) {
    int r = year % 33;
    return r == 1 || r == 5 || r == 9 || r == 13 || r == 17 || r == 22 || r == 26 || r == 30;
}

int max_day_for_month(int m, int y) {
    if (m < 7)
        return 31;
    else if (m < 12)
        return 30;
    else if (m == 12)
        return is_leap_year(y) ? 30 : 29;
    else
        abort();
}

void Date::set_date(int d, int m, int y) {
    if (y < 0 || m < 1 || m > 12 || d < 1 || d > max_day_for_month(m, y))
        abort();

    day = d;
    month = m;
    year = y;
}

bool Date::operator==(const Date &date) const {
    return day == date.day && month == date.month && year == date.year;
}

ostream &operator<<(ostream &stream, const Date &date) {
    stream << date.day << '/' << date.month << '/' << date.year << endl;
    return stream;
}

Date &Date::operator++() {
    day++;
    if (day > max_day_for_month(month, year)) {
        day = 1;
        month++;
        if (month > 12) {
            month = 1;
            year++;
        }
    }
    return *this;
}

Date &Date::operator++(int) {
    return ++(*this);
}

int days_between(Date d1, Date d2) {
    // Assuming d1 is not later than d2
    int count = 1;
    while (!(d1 == d2)) {
        d1++;
        count++;
    }
    return count;
}

Date str_to_date(string s) {
    //TODO: Handle formatting errors
    int slash_pos = s.find('/'); //3/12/1394 => slash_pos=1
    int d = stoi(s.substr(0, slash_pos)); //=> d=3
    s = s.substr(slash_pos + 1);//=>s=12/1394
    slash_pos = s.find('/');//=>slash_pos=2
    int m = stoi(s.substr(0, slash_pos));//=>m=12
    int y = stoi(s.substr(slash_pos + 1));//=>y=1394

    return Date{d, m, y};
}

Date &Date::operator=(const string &strDate){
    *this = str_to_date(strDate);
    return *this;
}


int main() {
    Date a(1,2,1380);
    cout << a;
    Date b = a;
    Date d;
    d = "1/1/1390";
    Date c = (((++a)++)++)++;
    cout << a << b << c << (c==a) << "  " << (c==b) << endl;
    cout << d;
}

