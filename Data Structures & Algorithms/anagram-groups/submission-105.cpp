class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> store;

        for (auto s : strs)
        {
            vector<int> count(26, 0);
            for (auto c : s)
            {
                count[c - 'a']++;
            }
            string key = to_string(count[0]);
            for (int i = 0; i < 26; ++i)
            {
                key += ',' + to_string(count[i]);
            }
            store[key].push_back(s);
        }

        vector<vector<string>> res;
        for (auto pair : store)
        {
            res.push_back(pair.second);
        }
        return res;
    }
};
