#include <bits/stdc++.h>
using namespace std;

deque<string> cache;
int solution(int cacheSize, vector<string> cities) {
    int ans = 0;

    if(cacheSize == 0) return ans = 5 * cities.size();
    
    for(auto &c : cities) {
        transform(c.begin(), c.end(), c.begin(), ::tolower);
        
        auto idx = find(cache.begin(), cache.end(), c);
        if(idx != cache.end()){
            cache.erase(idx);
            ans++;
        } else{
            if(cache.size() == cacheSize)
                cache.pop_front();
            ans += 5;
        }
        cache.push_back(c);
    }
    
    return ans;
}