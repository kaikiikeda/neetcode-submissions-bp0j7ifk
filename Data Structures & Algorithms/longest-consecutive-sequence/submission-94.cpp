class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int longest = 0;
        unordered_set<int> numSet;
        for (const auto &n : nums)
        {
            numSet.insert(n);
        }

        for (const auto &n : numSet)
        {
            if (!numSet.count(n-1))
            {
                int length = 1;
                while (numSet.count(n+length))
                {
                    length ++;
                }
                longest = max(longest, length);
            }
        }
        return longest;
    }
};
