#include <iostream>
#include <ctime>

using namespace std;

const string months[] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun",
                         "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
const string days[] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri",
                       "Sat"};

class Date {
private:
    string month;
    string day;
    int date;
    int year;
public:
    Date() {
        const int BASE_YEAR = 1900;
        time_t timer;
        tm *time;
        std::time(&timer);
        time = localtime(&timer);

        date = time->tm_mday;
        month = months[time->tm_mon];
        day = days[time->tm_wday];
        year = time->tm_year + BASE_YEAR;
    }

    Date(int d, int m, int y) {
        date = d;
        month = months[m - 1];
        year = y;
    }

    string dateToString() {
        string dateStr = to_string(this->date) + " " + month + " " + to_string(year);
        return dateStr;
    }

    void printToday() {
        cout << "Today: "
             << this->day << " " << this->date << "" << " "
             << this->month << " " << this->year << endl;
    }

    // Destructor
    ~Date() {}
};

