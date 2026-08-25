class Solution {
public:
    bool isValid(string s) {
        std::stack<char> stack;
        std::unordered_map <char, char> closetoopen = {
            {')' , '('},
            {']' , '['},
            {'}' , '{'}
        };

        for (const auto &c : s)
        {
            if (closetoopen.count(c))
            {
                if (!stack.empty() && stack.top() == closetoopen[c])
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
                stack.push(c);
            }
        }
        return stack.empty();
    }
};
