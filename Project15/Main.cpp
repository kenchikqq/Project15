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

    
    cout << "������� ����� ������ (����, ������, �������): " << endl;
    cout << "����: ";
    cin >> startTime.hours;
    cout << "������: ";
    cin >> startTime.minutes;
    cout << "�������: ";
    cin >> startTime.seconds;

    
    cout << "������� ����� ���������� (����, ������, �������): " << endl;
    cout << "����: ";
    cin >> endTime.hours;
    cout << "������: ";
    cin >> endTime.minutes;
    cout << "�������: ";
    cin >> endTime.seconds;

    
    double totalCost = calculateCost(startTime, endTime, costPerMinute);

    
    cout << "��������� ����� �������: " << totalCost << " ������." << endl;

    return 0;
}