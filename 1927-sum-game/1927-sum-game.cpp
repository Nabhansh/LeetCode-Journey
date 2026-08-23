class Solution {
public:
    bool sumGame(string num) {
        int n = num.size();
        int half = n / 2;
        int diff = 0;
        int qLeft = 0, qRight = 0;

        for (int i = 0; i < half; i++) {
            if (num[i] == '?')
                qLeft++;
            else
                diff += num[i] - '0';
        }

        for (int i = half; i < n; i++) {
            if (num[i] == '?')
                qRight++;
            else
                diff -= num[i] - '0';
        }

        if ((qLeft + qRight) % 2 == 1)
            return true;

        int qDiff = qLeft - qRight;

        if (qDiff == 0)
            return diff != 0;

        return diff + (qDiff / 2) * 9 != 0;
    }
};