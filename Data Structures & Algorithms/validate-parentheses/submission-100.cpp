class Solution {
public:
    bool isValid(string s) {
        std::stack<char> stack;
        std::unordered_map<char, char> closedtoopen = {
            {'}','{'},
            {')','('},
            {']','['}
        };

        for (char i : s)
        {
            if (closedtoopen.count(i))
            {
                if (!stack.empty() && stack.top() == closedtoopen[i])
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
