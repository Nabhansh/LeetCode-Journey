class Solution {
public:
    int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
        if (start > destination)
            swap(start, destination);

        int clockwise = 0;
        int total = 0;

        for (int d : distance)
            total += d;

        for (int i = start; i < destination; i++)
            clockwise += distance[i];

        return min(clockwise, total - clockwise);
    }
};