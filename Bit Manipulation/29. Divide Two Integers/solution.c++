class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;

        bool negative = (dividend < 0) ^ (divisor < 0);

        long long dvd = abs((long long)dividend);
        long long dvs = abs((long long)divisor);

        long long sum = 0;
        long long cnt = 0;

        while (sum + dvs <= dvd) {
            cnt++;
            sum += dvs;
        }

        return negative ? -cnt : cnt;
    }
};

class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == divisor)
            return 1;

        bool sign = !((dividend < 0) ^ (divisor < 0));

        long long n = llabs((long long)dividend);
        long long d = llabs((long long)divisor);

        long long quotient = 0;

        while (n >= d) {
            int cnt = 0;

            while (n >= (d << (cnt + 1)))
                cnt++;

            quotient += (1LL << cnt);
            n -= (d << cnt);
        }

        if (quotient == (1LL << 31))
            return sign ? INT_MAX : INT_MIN;

        return sign ? (int)quotient : -(int)quotient;
    }
};