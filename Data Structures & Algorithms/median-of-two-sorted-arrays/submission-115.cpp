class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> A = nums1;
        vector<int> B = nums2;

        int total = (int)A.size() + (int)B.size();
        int half = total/2;

        if (B.size() < A.size())
        {
            swap(A, B);
        }

        int l = -1, r = A.size()-1;

        while (l <= r)
        {
            int i = (l+r)/2;
            int j = half - i - 2;

            int Aleft = i >= 0 ? A[i] : INT_MIN;
            int Aright = i+1 < (int)A.size() ? A[i+1] : INT_MAX;
            int Bleft = j >= 0 ? B[j] : INT_MIN;
            int Bright = j+1 < (int)B.size() ? B[j+1] : INT_MAX;

            if (Aleft <= Bright && Bleft <= Aright)
            {
                if (total % 2 != 0)
                {
                    return min(Bright, Aright);
                }
                return (min(Aright, Bright) + max(Aleft, Bleft))/2.0;
            }
            else if (Aleft > Bright)
            {
                r = i - 1;
            }
            else
            {
                l = i + 1;
            }
            
        }
    }
};
