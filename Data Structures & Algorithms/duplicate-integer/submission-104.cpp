class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> prevmap;

        for (auto n : nums)
        {
            if (prevmap.count(n))
            {
                return true;
            }
            prevmap.insert(n);
        }
        return false;
    }
};