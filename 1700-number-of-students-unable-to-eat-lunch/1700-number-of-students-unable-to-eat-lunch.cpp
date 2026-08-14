class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int count[2] = {0, 0};
        
        for (int x : students)
            count[x]++;
        
        for (int x : sandwiches) {
            if (count[x] == 0)
                break;
            
            count[x]--;
        }
        
        return count[0] + count[1];
    }
};