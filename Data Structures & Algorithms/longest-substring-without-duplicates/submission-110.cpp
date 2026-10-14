class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> prevmap;
        int res = 0;
        int l = 0;

        for (int r = 0; r < s.size(); ++r)
        {
            while (prevmap.count(s[r]))
            {
                prevmap.erase(s[l]);
                l++;
            }
            prevmap.insert(s[r]);
            res = max(res, r-l+1);
        }
        return res;
    }
};
