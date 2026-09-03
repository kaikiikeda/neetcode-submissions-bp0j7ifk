class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        std::stack<pair<int, int>> stack;
        int res = 0;

        for (int i = 0; i < heights.size(); ++i)
        {
            int start = i;
            while (!stack.empty() && stack.top().second > heights[i])
            {
                auto pair = stack.top();
                stack.pop();
                res = max(res, pair.second * (i - pair.first));
                start = pair.first;
            }
            stack.push({start, heights[i]});
        }

        while (!stack.empty())
        {
            int index = stack.top().first;
            int height = stack.top().second;
            res = max(res, height * ((int)heights.size() - index));
            stack.pop();
        }
        return res;
    }
};
