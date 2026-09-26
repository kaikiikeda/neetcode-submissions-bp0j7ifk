class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> output;
        int l = 0;
        int res = 0;
        deque<int> q;

        for (int r = 0; r < nums.size(); ++r)
        {
            while (!q.empty() && nums[q.back()] < nums[r])
            {
                q.pop_back();
            }
            q.push_back(r);
            if (l > q.front())
            {
                q.pop_front();
            }
            if (r+1 >= k)
            {
                output.push_back(nums[q.front()]);
                l++;
            }
        }
        return output;
    }
};
