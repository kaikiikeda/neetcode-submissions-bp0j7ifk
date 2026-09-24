class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> res(temperatures.size(), 0);
        stack<pair<int, int>> stack;

        for (int i = 0; i < temperatures.size(); ++i)
        {
            int t = temperatures[i];
            while (!stack.empty() && stack.top().second < t)
            {
                auto pair = stack.top();
                int index = pair.first;
                int temp = pair.second;
                stack.pop();
                res[index] = i - index;
            }
            stack.push({i, t});
        }
        return res;
    }
};
