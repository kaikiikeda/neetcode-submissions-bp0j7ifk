class Solution {
public:
    bool isValid(string s) {
        std::stack<char> stack;
        std::unordered_map<char, char> map = {
            {']', '['},
            {'}', '{'},
            {')', '('}
        };

        for (char i : s)
        {
            if (map.count(i))
            {
                if (!stack.empty() && stack.top() == map[i])
                {
                    stack.pop();
                }
                else
                {
                    return false;
                }
            }
            else
            {
                stack.push(i);
            }
        }
        return stack.empty();
    }
};
