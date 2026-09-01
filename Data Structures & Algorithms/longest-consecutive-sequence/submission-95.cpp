class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int longest = 0;
        unordered_set<int> num;
        for (const auto &n : nums)
        {
            num.insert(n);
        }

        for (auto &n : num)
        {
            if (!num.count(n-1))
            {
                int length = 1;
                while (num.count(n + length))
                {
                    length++;
                }
                longest = max(longest, length);
            }
        }
        return longest;
    }
};
