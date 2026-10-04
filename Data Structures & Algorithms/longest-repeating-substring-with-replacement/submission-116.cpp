class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> charset;
        int maxF =0 ;
        int l = 0;
        int res = 0;

        for (int r = 0; r < s.size(); ++r)
        {
            charset[s[r]]++;
            maxF = max(maxF, charset[s[r]]);
            if (r-l+1 - maxF > k)
            {
                charset[s[l]] -= 1;
                l++;
            }
            res = max(res, r-l+1);
        }
        return res;
    }
};
