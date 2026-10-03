class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, char> map{
            {')','('},
            {']','['},
            {'}','{'}
        };
        std::stack<char> stack;

        for (auto i : s)
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
