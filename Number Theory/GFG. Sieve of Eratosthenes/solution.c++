/*Sieve of Eratosthenes — Short Note

Core Idea:
Instead of checking every number individually to see if it is prime,
start by assuming all numbers are prime and eliminate numbers that
are definitely NOT prime.

Why mark multiples as non-prime?
If i is prime, every multiple of i (except i itself) is divisible by i,
so it has factors other than 1 and itself → therefore it is NOT prime.

Example:
i = 2 → eliminate 4, 6, 8, 10, 12...
i = 3 → eliminate 9, 12, 15, 18...
i = 5 → eliminate 25, 30, 35...

Why start from i * i?
Smaller multiples have already been eliminated by smaller factors.

Example for i = 5:
10 = 2 × 5 → already eliminated by 2
15 = 3 × 5 → already eliminated by 3
20 = 4 × 5 → already eliminated by 2
25 = 5 × 5 → first new multiple to eliminate

So we use:
j = i * i

At the end:
Numbers that are still marked prime = Prime numbers.

Memory Trick:
"Don't find primes directly → eliminate composites.
A number is composite if it has a smaller factor."*/

class Solution {
  public:
    vector<int> sieve(int n) {
        // code here
        vector<bool>isPrime(n+1, true);
        vector<int>ans;
        isPrime[0] = false;
        isPrime[1] = false;
        if(n < 2) return ans;
        for(int i=2; i*i <= n; i++){
            if(isPrime[i]){
                for(int j=i*i; j<=n; j+=i) isPrime[j] = false;
            }
        }
        for(int i=2; i<=n; i++){
            if(isPrime[i]) ans.push_back(i);
        }
        return ans;
    }
};