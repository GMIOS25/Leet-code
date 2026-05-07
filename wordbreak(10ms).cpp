class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        // dp[i] means s[0...i-1] can be segmented
        vector<bool> dp(n + 1, false);
        dp[0] = true; // Base case: empty string is valid

        // Convert dict to a set for O(1) lookups
        unordered_set<string> dict(wordDict.begin(), wordDict.end());

        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                // If the prefix s[0...j] is valid AND the rest s[j...i] is in dict
                if (dp[j] && dict.find(s.substr(j, i - j)) != dict.end()) {
                    dp[i] = true;
                    break; // Found a way to make s[0...i] valid
                }
            }
        }
        return dp[n];
    }
};