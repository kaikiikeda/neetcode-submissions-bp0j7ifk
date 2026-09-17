class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        std::vector<pair<int, int>> stack;
        int res = 0;

        for (int i = 0; i < heights.size(); ++i)
        {
            int h = heights[i];
            int start = i;
            while (!stack.empty() && stack.back().second >= h)
            {
                auto pair = stack.back();
                stack.pop_back();
                int index = pair.first;
                int height = pair.second;

                res = max(res, height * (i - index));
                start = index;
            }
            stack.push_back({start, h});
        }

        while (!stack.empty())
        {
            auto pair = stack.back();
            stack.pop_back();
            int i = pair.first;
            int h = pair.second;

            res = max(res, h * ((int)heights.size() - i));
        }
        return res;
    }
};
