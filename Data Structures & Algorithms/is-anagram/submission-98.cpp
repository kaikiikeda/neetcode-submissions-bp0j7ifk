class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size())
        {
            return false;
        }

        map<char, int> setS, setT;

        for (int i = 0; i < s.size(); ++i)
        {
            setS[s[i]] += 1;
            setT[t[i]] += 1;
        }
        return setS == setT;
    }
};
