class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        vector<pair<int, int>> stack;
        int res = 0;

        for (int i = 0; i < heights.size(); ++i)
        {
            int h = heights[i];
            int start = i;
            while (!stack.empty() && stack.back().second >= h)
            {
                auto pair = stack.back();
                stack.pop_back();
                res = max(res, pair.second * (i - pair.first));
                start = pair.first;
            }
            stack.push_back({start, h});
        }

        while (!stack.empty())
        {
            auto pair = stack.back();
            stack.pop_back();
            res = max(res, pair.second * ((int)heights.size() - pair.first));
        }
        return res;
    }
};
