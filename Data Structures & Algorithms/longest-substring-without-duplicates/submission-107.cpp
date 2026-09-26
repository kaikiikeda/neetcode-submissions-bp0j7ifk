class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> charset;
        int l = 0;
        int res = 0;

        for (int r = 0; r < s.size(); ++r)
        {
            while (charset.count(s[r]))
            {
                charset.erase(s[l]);
                l++;
            }
            charset.insert(s[r]);
            res = max(r-l+1, res);
        }
        return res;
    }
};
