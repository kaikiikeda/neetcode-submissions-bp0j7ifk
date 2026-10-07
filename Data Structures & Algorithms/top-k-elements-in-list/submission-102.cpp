class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        vector<vector<int>> freq(nums.size()+1);

        for (auto n : nums)
        {
            count[n]++;
        }
        for (auto pair:count)
        {
            int n = pair.first;
            int c = pair.second;
            freq[c].push_back(n);
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
