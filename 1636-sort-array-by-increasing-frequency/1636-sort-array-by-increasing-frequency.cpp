class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int> frequency;

        for (int value : nums)
            ++frequency[value];

        sort(nums.begin(), nums.end(),
             [&](int a, int b) {
                 if (frequency[a] != frequency[b])
                     return frequency[a] < frequency[b];

                 return a > b;
             });

        return nums;
    }
};