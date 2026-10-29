class Solution {
public:
    char slowestKey(vector<int>& releaseTimes, string keysPressed) {
        int maximum = releaseTimes[0];
        char answer = keysPressed[0];

        for (int i = 1; i < releaseTimes.size(); i++) {
            int duration = releaseTimes[i] - releaseTimes[i - 1];

            if (duration > maximum ||
                (duration == maximum && keysPressed[i] > answer)) {
                maximum = duration;
                answer = keysPressed[i];
            }
        }

        return answer;
    }
};