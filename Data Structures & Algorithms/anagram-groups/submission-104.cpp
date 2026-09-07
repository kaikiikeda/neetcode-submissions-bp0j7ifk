class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> result;

        for (auto s : strs)
        {
            vector<int> count(26, 0);
            for (auto c : s)
            {
                count[c - 'a']++;
            }
            string key = to_string(count[0]);
            for (int i = 1; i < 26; ++i)
            {
                key += ',' + to_string(count[i]);
            }
            result[key].push_back(s);
        }

        vector<vector<string>> res;
        for (auto pair : result)
        {
            res.push_back(pair.second);
        }
        return res;

    
    }
};
