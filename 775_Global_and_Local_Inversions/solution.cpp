class Solution {
public:
    bool isIdealPermutation(vector<int>& A) {

        if (A.size() == 1 || A.size() == 2) {
            return true;
        }

        int maxI = max(A[0], A[1]); // Largest digit.
        int maxII = min(A[0], A[1]); // Second largest digit.
        for (int i = 2; i < A.size(); ++i) {

            if ((A[i] < maxII) || (A[i] < maxI && maxI != A[i-1])) {
                return false;
            }

            maxII = max(min(A[i], maxI), maxII);
            maxI = max(A[i], maxI);
        }

        return true;
    }
};
