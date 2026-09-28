class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> numset;

        for (auto n : nums)
        {
            if (numset.count(n))
            {
                return true;
            }
            numset.insert(n);
        }
        return false;
    }
};