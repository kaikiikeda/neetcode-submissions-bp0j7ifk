class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size())
        {
            return false;
        }

        unordered_map<char, int> setS, setT;
        for (int i = 0; i < s.size(); ++i)
        {
            setS[s[i] - 'a']++;
            setT[t[i] - 'a']++;
        }
        return setS == setT;
    }
};
