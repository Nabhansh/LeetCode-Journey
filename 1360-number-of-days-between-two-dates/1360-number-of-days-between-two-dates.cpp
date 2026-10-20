class Solution {
public:
    int daysBetweenDates(string date1, string date2) {
        auto convert = [](string date) {
            int y = stoi(date.substr(0, 4));
            int m = stoi(date.substr(5, 2));
            int d = stoi(date.substr(8, 2));

            int days = 365 * y + (y - 1) / 4
                     - (y - 1) / 100 + (y - 1) / 400;

            int monthDays[] = {
                31, 28, 31, 30, 31, 30,
                31, 31, 30, 31, 30, 31
            };

            for (int i = 1; i < m; i++) {
                days += monthDays[i - 1];

                if (i == 2 &&
                    (y % 400 == 0 ||
                     (y % 4 == 0 && y % 100 != 0)))
                    days++;
            }

            return days + d;
        };

        return abs(convert(date1) - convert(date2));
    }
};