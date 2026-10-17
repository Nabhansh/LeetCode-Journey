class Solution {
public:
    string dayOfTheWeek(int day, int month, int year) {
        vector<string> days = {
            "Sunday", "Monday", "Tuesday", "Wednesday",
            "Thursday", "Friday", "Saturday"
        };

        vector<int> monthDays = {
            31, 28, 31, 30, 31, 30,
            31, 31, 30, 31, 30, 31
        };

        int total = 0;

        for (int y = 1971; y < year; y++) {
            total += 365;

            if ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0)
                total++;
        }

        for (int m = 1; m < month; m++) {
            total += monthDays[m - 1];

            if (m == 2 &&
                ((year % 4 == 0 && year % 100 != 0) ||
                 year % 400 == 0))
                total++;
        }

        total += day - 1;

        return days[(total + 5) % 7];
    }
};