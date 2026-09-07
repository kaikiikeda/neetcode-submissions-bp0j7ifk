class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> prev;

        for (const auto &n : nums)
        {
            if (prev.count(n))
            {
                return true;
            }
            prev.insert(n);
        }
        return false;
    }
};