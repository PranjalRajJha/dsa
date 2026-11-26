class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int lastSeenS[256] = {0};
        int lastSeenT[256] = {0};

        for (int i = 0; i < s.length(); ++i) {
            if (lastSeenS[s[i]] != lastSeenT[t[i]]) {
                return false;
            }

            // Store i + 1 to distinguish from the default initial value of 0
            lastSeenS[s[i]] = i + 1;
            lastSeenT[t[i]] = i + 1;
        }

        return true;
    }
};