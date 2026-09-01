class Solution {
public:
    int minNumberOfHours(int initialEnergy, int initialExperience, vector<int>& energy, vector<int>& experience) {
        int hours = 0;
        int e = initialEnergy;
        int x = initialExperience;

        for (int i = 0; i < energy.size(); i++) {
            if (e <= energy[i]) {
                int need = energy[i] + 1 - e;
                hours += need;
                e += need;
            }

            if (x <= experience[i]) {
                int need = experience[i] + 1 - x;
                hours += need;
                x += need;
            }

            e -= energy[i];
            x += experience[i];
        }

        return hours;
    }
};