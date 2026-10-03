class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int res = 0;
        stack<pair<int, int>> stack;

        for (int i = 0; i < heights.size(); ++i)
        {
            int h = heights[i];
            int start = i;
            while (!stack.empty() && stack.top().second >= h)
            {
                auto pair = stack.top();
                stack.pop();
                int index = pair.first, height = pair.second;
                res = max(res, height * (i - index));
                start = index;
            }
            stack.push({start, h});
        }

        while (!stack.empty())
        {
            auto pair = stack.top();
            stack.pop();

            res = max(res, pair.second * ((int)heights.size() - pair.first));
        }
        return res;
    }
};
