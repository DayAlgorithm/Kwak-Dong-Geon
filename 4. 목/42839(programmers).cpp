#include <bits/stdc++.h>
using namespace std;

set<int> primes;

bool prime(int n) {
    if(n == 0 || n == 1) return false;

    for(int i = 2; i <= sqrt(n); ++i) {
        if(!(n % i)) return false;
    }
    return true;
}

int solution(string numbers) {
    int ans = 0, size = numbers.size();
    sort(numbers.begin(), numbers.end());
    do {
        for(int i = 1; i <= size; ++i) {
            for(int j = 0; j <= size - i; ++j) {
                string sub = numbers.substr(j, i);
                int num = stoi(sub);
                if(prime(num)) primes.insert(num);
            }
        }
    } while(next_permutation(numbers.begin(), numbers.end()));
    ans = primes.size();
    return ans;
}