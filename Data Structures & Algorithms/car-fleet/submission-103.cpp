class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> pairs;
        for (int i = 0; i < position.size(); ++i)
        {
            pairs.push_back({position[i], speed[i]});
        }

        sort(pairs.rbegin(), pairs.rend());
        vector<double> stack;

        for (auto pair : pairs)
        {
            int p = pair.first;
            int s = pair.second;

            stack.push_back((double)(target - p)/s);

            if (stack.size() >= 2 && stack.back() <= stack[stack.size()-2])
            {
                stack.pop_back();
            }
        }
        return stack.size();
    }
};
