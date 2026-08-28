class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> prevMap;
        int res = 0;
        int l = 0;
        int maxC = 0;

        for (int r = 0; r < s.size(); ++r)
        {
            prevMap[s[r]]++;
            maxC = max(maxC, prevMap[s[r]]);
            if ((r-l+1) - maxC > k)
            {
                prevMap[s[l]]--;
                l++;
            }
            res = max(res, r-l+1);
        }
        return res;
    }
};
