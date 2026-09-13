class Solution {
public:
    struct State {
        int wordIndex;
        int position;
    };

    int numMatchingSubseq(string s, vector<string>& words) {
        vector<State> bucket[26];

        // Initially, every word is waiting for its first character
        for (int i = 0; i < words.size(); i++) {
            bucket[words[i][0] - 'a'].push_back({i, 0});
        }

        int ans = 0;

        for (char ch : s) {
            int index = ch - 'a';

            // Take all words currently waiting for this character
            vector<State> current = move(bucket[index]);

            for (auto state : current) {
                int wordIndex = state.wordIndex;
                int position = state.position + 1;

                // The whole word has been matched
                if (position == words[wordIndex].size()) {
                    ans++;
                }
                else {
                    // Wait for the next required character
                    char nextChar = words[wordIndex][position];

                    bucket[nextChar - 'a'].push_back({
                        wordIndex,
                        position
                    });
                }
            }
        }

        return ans;
    }
};