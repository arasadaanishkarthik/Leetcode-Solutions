class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        int freq[3] = {0};
        for (const int num: stones)
            ++freq[num % 3];

        int f1 = freq[1], f2 = freq[2];
        // if there is at least one type 1 stone
        if (f1) {
            // remove one of the type 1 stones
            int cnt = 1;
            --f1;
            // remove pairs of type 1/2 stones
            int minf = min(f1, f2);
            f1 -= minf, f2 -= minf;
            // if there are any type 1 stones left, remove one
            if (f1) {
                --f1;
                cnt = 0;
            }
            // in the end, if there are any type 1/2 stones left
            // and we remove odd number of type 0/1/2 stones,
            // there are no stones for Bob to remove in the next step,
            // so Alice wins
            if (f1 + f2 && (cnt + freq[0]) % 2)
                return true;
        }

        f1 = freq[1], f2 = freq[2];
        if (f2) {
            int cnt = 1;
            --f2;
            int minf = min(f1, f2);
            f1 -= minf, f2 -= minf;
            if (f2) {
                --f2;
                cnt = 0;
            }
            if (f1 + f2 && (cnt + freq[0]) % 2)
                return true;
        }
        return false;
    }
};