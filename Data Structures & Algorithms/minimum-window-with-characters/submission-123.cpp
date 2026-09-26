class Solution {
public:
    string minWindow(string s, string t) {
        if (t.empty())
        {
            return "";
        }

        unordered_map<char, int> countT, window;
        for (auto c : t)
        {
            countT[c]++;
        }

        int have = 0, need = countT.size();
        pair res = {-1, -1};
        int resLen = INT_MAX;
        int l = 0;

        for (int r = 0; r < s.size(); ++r)
        {
            char c = s[r];
            window[c]++;

            if (countT.count(c) and window[c] == countT[c])
            {
                have++;
            }
            while (have == need)
            {
                if (r-l+1 < resLen)
                {
                    res = {l, r};
                    resLen = r-l+1;
                }
                window[s[l]]--;
                if(countT.count(s[l]) and window[s[l]] < countT[s[l]])
                {
                    have--;
                }
                l++;
            }
        }
        auto pair = res;
        return resLen != INT_MAX ? s.substr(pair.first, pair.second - pair.first + 1) : "";

    }
};
