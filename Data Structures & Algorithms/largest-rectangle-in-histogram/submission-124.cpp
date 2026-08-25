class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        std::stack<std::pair<int, int>> stack;
        int res = 0;

        for (int i = 0; i < heights.size(); ++i)
        {
            int h = heights[i];
            int start = i;
            while (!stack.empty() && stack.top().second > h)
            {
                auto pair = stack.top();
                stack.pop();
                res = max(res, pair.second * (i - pair.first));
                start = pair.first;
            }
            stack.push({start, h});
        }

        while (!stack.empty())
        {
            int index = stack.top().first;
            int height = stack.top().second;
            res = max(res, height * static_cast<int>(heights.size() - index));
            stack.pop();
        }
        return res;
    }
};
