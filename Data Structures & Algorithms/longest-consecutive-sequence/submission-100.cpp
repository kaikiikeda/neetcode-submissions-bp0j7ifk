class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int longest = 0;
        unordered_set<int> numSet;
        for (auto n : nums)
        {
            numSet.insert(n);
        }

        for (auto n : numSet)
        {
            int length = 0;
            if (!numSet.count(n-1))
            {
                length = 1;
                while (numSet.count(n + length))
                {
                    length++;
                }
                longest = max(longest, length);
            }
        }
        return longest;
    }
};
