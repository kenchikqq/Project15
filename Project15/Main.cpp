#include <iostream>
#include <windows.h>
using namespace std;

struct Time {
    int hours;
    int minutes;
    int seconds;
};


double calculateCost(const Time& startTime, const Time& endTime, double costPerMinute) {
 
    int startTotalSeconds = startTime.hours * 3600 + startTime.minutes * 60 + startTime.seconds;
    int endTotalSeconds = endTime.hours * 3600 + endTime.minutes * 60 + endTime.seconds;

   
    int durationInSeconds = endTotalSeconds - startTotalSeconds;

    
    if (durationInSeconds < 0) {
        durationInSeconds += 24 * 3600; 
    }

    
    double durationInMinutes = durationInSeconds / 60.0;

    
    return durationInMinutes * costPerMinute;
}

int main() {
    setlocale(LC_ALL, "Russian");
    Time startTime, endTime;
    double costPerMinute = 2.0; 

    
    cout << "Введите время начала (часы, минуты, секунды): " << endl;
    cout << "Часы: ";
    cin >> startTime.hours;
    cout << "Минуты: ";
    cin >> startTime.minutes;
    cout << "Секунды: ";
    cin >> startTime.seconds;

    
    cout << "Введите время завершения (часы, минуты, секунды): " << endl;
    cout << "Часы: ";
    cin >> endTime.hours;
    cout << "Минуты: ";
    cin >> endTime.minutes;
    cout << "Секунды: ";
    cin >> endTime.seconds;

    
    double totalCost = calculateCost(startTime, endTime, costPerMinute);

    
    cout << "Стоимость вашей поездки: " << totalCost << " гривен." << endl;

    return 0;
}