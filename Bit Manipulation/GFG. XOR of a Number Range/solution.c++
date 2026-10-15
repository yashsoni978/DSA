class Solution {
  public:
    int findXOR(int l, int r) {
        int ans = 0;

        for (int i = l; i <= r; i++) {
            ans ^= i;
        }

        return ans;
    }
};

class Solution {
public:
    int xorTillN(int n) {
        switch (n % 4) {
            case 0: return n;
            case 1: return 1;
            case 2: return n + 1;
            default: return 0;
        }
    }

    int findXOR(int l, int r) {
        return xorTillN(r) ^ xorTillN(l - 1);
    }
};