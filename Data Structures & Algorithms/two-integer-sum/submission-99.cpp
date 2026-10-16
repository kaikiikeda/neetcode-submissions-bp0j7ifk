class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> prevmap;

        for (int i = 0; i < nums.size(); ++i)
        {
            int n = nums[i];
            int diff = target - n;
            if (prevmap.count(diff))
            {
                return {prevmap[diff], i};
            }
            prevmap[n] = i;
        }
    }
};
