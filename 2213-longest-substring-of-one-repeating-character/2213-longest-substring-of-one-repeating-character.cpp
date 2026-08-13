class Solution {
public:
    struct Node {
        char lc, rc;
        int llen, rlen, best, len;

        Node() {
            lc = rc = 0;
            llen = rlen = best = len = 0;
        }
    };

    vector<Node> tree;

    Node merge(Node a, Node b) {
        if (a.len == 0) return b;
        if (b.len == 0) return a;

        Node res;
        res.len = a.len + b.len;

        res.lc = a.lc;
        res.rc = b.rc;

        res.llen = a.llen;
        res.rlen = b.rlen;

        res.best = max(a.best, b.best);

        if (a.rc == b.lc) {
            res.best = max(res.best, a.rlen + b.llen);

            if (a.llen == a.len)
                res.llen = a.len + b.llen;

            if (b.rlen == b.len)
                res.rlen = b.len + a.rlen;
        }

        return res;
    }

    void build(int node, int l, int r, string &s) {
        if (l == r) {
            tree[node].lc = s[l];
            tree[node].rc = s[l];
            tree[node].llen = 1;
            tree[node].rlen = 1;
            tree[node].best = 1;
            tree[node].len = 1;
            return;
        }

        int mid = (l + r) / 2;

        build(node * 2, l, mid, s);
        build(node * 2 + 1, mid + 1, r, s);

        tree[node] = merge(tree[node * 2], tree[node * 2 + 1]);
    }

    void update(int node, int l, int r, int idx, char c) {
        if (l == r) {
            tree[node].lc = c;
            tree[node].rc = c;
            tree[node].llen = 1;
            tree[node].rlen = 1;
            tree[node].best = 1;
            tree[node].len = 1;
            return;
        }

        int mid = (l + r) / 2;

        if (idx <= mid)
            update(node * 2, l, mid, idx, c);
        else
            update(node * 2 + 1, mid + 1, r, idx, c);

        tree[node] = merge(tree[node * 2], tree[node * 2 + 1]);
    }

    vector<int> longestRepeating(string s, string queryCharacters,
                                 vector<int>& queryIndices) {

        int n = s.size();

        tree.resize(4 * n + 5);

        build(1, 0, n - 1, s);

        vector<int> ans;

        for (int i = 0; i < queryIndices.size(); i++) {

            update(
                1,
                0,
                n - 1,
                queryIndices[i],
                queryCharacters[i]
            );

            ans.push_back(tree[1].best);
        }

        return ans;
    }
};