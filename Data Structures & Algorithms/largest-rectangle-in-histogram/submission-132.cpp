class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        std::stack<pair<int, int>> stack;
        int res = 0;

        for (int i = 0; i < heights.size(); ++i)
        {
            int start = i;
            int h = heights[i];
            while (!stack.empty() && stack.top().second >= h)
            {
                auto pair = stack.top();
                stack.pop();
                int index = pair.first;
                int height = pair.second;

                res = max(res, height * (i - index));
                start = index;
            }
            stack.push({start, h});
        }

        while (!stack.empty())
        {
            int i = stack.top().first;
            int h = stack.top().second;
            stack.pop();

            res = max(res, h * ((int)heights.size() - i));
        }
        return res;
    }
};
