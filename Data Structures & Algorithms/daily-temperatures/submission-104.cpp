class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> res(temperatures.size(), 0);
        std::stack<pair<int, int>> stack;

        for (int i = 0; i < temperatures.size(); ++i)
        {
            while (!stack.empty() && stack.top().second < temperatures[i])
            {
                auto pair = stack.top();
                stack.pop();
                int index = pair.first;
                int temp = pair.second;
                res[index] = i - index;
            }
            stack.push({i, temperatures[i]});
        }
        return res;

    }
};
