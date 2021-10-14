
#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

class Date {
public:
    Date(int d, int m, int y);
    Date();
    void set_date(int d, int m, int y);
    void print_date();
    bool equals(Date d);
    int compare(Date d);
    string day_of_week();


    int get_day() { return day; }
    int get_month() { return month; }
    int get_year() { return year; }
    void inc_one_day();
private:
    int day;
    int month;
    int year;

    int to_days();
};

Date::Date(int d, int m, int y)
{
    //constructor
    set_date(d, m, y);
}

Date::Date()
{
    //default constructor
    set_date(1, 1, 1390);
}

bool is_leap_year(int year)
{
    int r = year % 33;
    return r==1 || r==5 || r==9 || r==13 || r==17 || r==22 || r==26 || r==30;
}

int max_day_for_month(int m, int y)
{
    if (m < 7)
        return 31;
    else if (m < 12)
        return 30;
    else if (m == 12)
        return is_leap_year(y) ? 30 : 29;
    else
        abort();
}

void Date::inc_one_day()
{
    day++;
    if (day > max_day_for_month(month, year)) {
        day = 1;
        month++;
        if (month > 12) {
            month = 1;
            year++;
        }
    }
}

void Date::set_date(int d, int m, int y)
{
    if (y < 0 || m < 1 || m > 12 || d < 1 || d > max_day_for_month(m, y))
        abort();

    day = d;
    month = m;
    year = y;
}

void Date::print_date()
{
    //baraye chape tarikh
    cout << day << '/' << month << '/' << year << endl;
}

bool Date::equals(Date d) {
    //moghaieseye 2 tarikh
    return day == d.day && month == d.month && year == d.year;
}

int Date::compare(Date other) {
    int daysOfThis = this->to_days();
    int daysOfOther = other.to_days();
    if (daysOfOther < daysOfThis){
        return 1;
    }else if (daysOfOther == daysOfThis){
        return 0;
    }else{
        return -1;
    }
}

int Date::to_days() {
    int daysOfYear = 365.25 * year;
    int daysOfMonth = 0;
    if (month <= 7){
        daysOfMonth += 31 * (month-1);
    }else{
        daysOfMonth += 31*6 + (month-1) * 30;
    }

    return daysOfYear + daysOfMonth + day;
}

int days_between(Date d1, Date d2) {
    int count = 0;
    int compare = d1.compare(d2);

    if (compare == 1){
        while (!d1.equals(d2)) {
            d2.inc_one_day();
            count++;
        }
    }else if (compare == -1){
        while (!d2.equals(d1)) {
            d1.inc_one_day();
            count++;
        }
    }

    return count;
}

string Date::day_of_week() {
    int distance = days_between(Date(1, 1, 1), Date(day, month, year));
    switch (distance % 7) {
        case 0: return "Fri";
        case 1: return "Sat";
        case 2: return "Sun";
        case 3: return "Mon";
        case 4: return "Tue";
        case 5: return "Wed";
        case 6: return "Thu";
    }
}

Date str_to_date(string s) {
    //TODO: Handle formatting errors
    int slash_pos = s.find('/'); //3/12/1394 => slash_pos=1
    int d = stoi(s.substr(0, slash_pos)); //=> d=3
    s = s.substr(slash_pos + 1);//=>s=12/1394
    slash_pos = s.find('/');//=>slash_pos=2
    int m = stoi(s.substr(0, slash_pos));//=>m=12
    int y = stoi(s.substr(slash_pos + 1));//=>y=1394

    return Date(d, m, y);
}

int main()
{
    string s1 = "2/1/1";
    string s2 = "1/1/1";
    Date d1 = str_to_date(s1);
    Date d2 = str_to_date(s2);
    Date d3(1, 2, 1);

    cout << d1.day_of_week() << endl;
    cout << d2.day_of_week() << endl;
    cout << d3.day_of_week() << endl;
    return 0;

}