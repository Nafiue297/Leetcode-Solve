class Solution {
public:
    const int mod = 1e9 + 7;
    using ll = long long;

    int maxSum(vector<int>& nums, int k) {
        vector<int> cnt(32, 0);

        for (auto &u : nums) {
            for (int i = 0; i < 32; i++) {
                if (u & (1LL << i)) cnt[i]++;
            }
        }

        ll res = 0;

        while (k--) {
            ll tmp = 0;

            for (int i = 0; i < 32; i++) {
                if (cnt[i] > 0) {
                    cnt[i]--;
                    tmp |= (1LL << i);
                }
            }

            tmp %= mod;
            res = (res+(tmp * tmp) % mod) % mod;
        }

        return res;
    }
};