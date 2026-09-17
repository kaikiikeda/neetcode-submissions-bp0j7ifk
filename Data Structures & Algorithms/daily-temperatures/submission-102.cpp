class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> res(temperatures.size(), 0);
        stack<pair<int, int>> stack;

        for (int i = 0; i < temperatures.size(); ++i)
        {
            while (!stack.empty() && stack.top().second < temperatures[i])
            {
                auto pair = stack.top();
                stack.pop();
                res[pair.first] = i - pair.first;
            }
            stack.push({i, temperatures[i]});
        }
        return res;
    }
};
