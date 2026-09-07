class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        for (auto n:nums)
        {
            count[n]++;
        }

        vector<vector<int>> freq(nums.size() + 1);
        for (auto pair : count)
        {
            freq[pair.second].push_back(pair.first);
        }
        
        vector<int> res;
        for (int i = freq.size()-1; i >= 0; --i)
        {
            for (auto c : freq[i])
            {
                res.push_back(c);
                if (res.size() == k)
                {
                    return res;
                }
            }
        }
    }
};
