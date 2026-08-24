class Solution {
public:
    int maxArea(vector<int>& heights) {
        int maxA = 0;
        int l = 0, r = heights.size()-1;

        while (l < r)
        {
            int area = (r-l) * min(heights[l], heights[r]);
            if (heights[l] < heights[r])
            {
                l++;
            }
            else
            {
                r--;
            }
            maxA = max(maxA, area);

        }
        return maxA;
    }
};
