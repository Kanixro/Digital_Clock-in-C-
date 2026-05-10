#include <iostream>
#include <windows.h>
#include <ctime>
#include <iomanip>

using namespace std;

class DigitalClock {
private:
    HANDLE hConsole;
    bool showColon;

public:
    DigitalClock() {
        hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        showColon = true;
    }

    void setColor(int color) {
        SetConsoleTextAttribute(hConsole, color);
    }

    void gotoXY(int x, int y) {
        COORD coord;
        coord.X = x;
        coord.Y = y;
        SetConsoleCursorPosition(hConsole, coord);
    }

    void drawFrame() {
        setColor(11);
        gotoXY(20, 3);
        cout << "+------------------------------+";
        gotoXY(20, 4);
        cout << "|        DIGITAL CLOCK         |";
        gotoXY(20, 5);
        cout << "+------------------------------+";
        gotoXY(20, 8);
        cout << "+------------------------------+";
        gotoXY(20, 9);
        cout << "|      Designed by             |";
        gotoXY(20, 10);
        cout << "|   Mohandes Kian Nasiri       |";
        gotoXY(20, 11);
        cout << "+------------------------------+";
    }

    void displayTime() {
        time_t now = time(0);
        tm* localTime = localtime(&now);

        int hour = localTime->tm_hour;
        int minute = localTime->tm_min;
        int second = localTime->tm_sec;

        string period = "AM";

        if (hour >= 12)
            period = "PM";

        hour = hour % 12;
        if (hour == 0)
            hour = 12;

        gotoXY(27, 6);
        setColor(14);

        cout << setw(2) << setfill('0') << hour;

        if (showColon)
            cout << ":";
        else
            cout << " ";

        cout << setw(2) << setfill('0') << minute;

        if (showColon)
            cout << ":";
        else
            cout << " ";

        cout << setw(2) << setfill('0') << second << " " << period;

        showColon = !showColon;
    }

    void run() {
        system("cls");
        drawFrame();

        while (true) {
            displayTime();
            Sleep(1000);
        }
    }
};

int main() {
    DigitalClock clock;
    clock.run();
    return 0;
}
