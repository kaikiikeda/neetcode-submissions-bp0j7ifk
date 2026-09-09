class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int, int>> pair;
        for (int i = 0; i < speed.size(); ++i)
        {
            pair.push_back({position[i], speed[i]});
        }

        std::vector<double> stack;
        sort(pair.rbegin(), pair.rend());
        for (auto p : pair)
        {
            stack.push_back((double)(target - p.first)/p.second);
            if (stack.size() >= 2 && stack[stack.size()-1] <= stack[stack.size()-2])
            {
                stack.pop_back();
            }
        }
        return stack.size();
    }
};
