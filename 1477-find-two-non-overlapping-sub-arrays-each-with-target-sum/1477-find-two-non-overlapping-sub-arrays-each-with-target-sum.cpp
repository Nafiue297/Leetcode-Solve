class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        int currsum = 0;
        vector<int> minBestLenTillIdx(n, INT_MAX);

        int bestMinLen = INT_MAX;
        int result = INT_MAX;

        int left = 0;

        for(int right = 0; right < n; right++)
        {
            currsum += arr[right];

            while(currsum >= target)
            {
                if(currsum == target)
                {
                    int len = right - left + 1;

                    if(left > 0 && minBestLenTillIdx[left-1] != INT_MAX) {
                        result = min(result, len + minBestLenTillIdx[left-1]);
                    }

                    bestMinLen = min(bestMinLen, len);
                }

                currsum -= arr[left];
                left++;
            }

            minBestLenTillIdx[right] = bestMinLen;
        }

        return result == INT_MAX ? -1 : result;
    }
};