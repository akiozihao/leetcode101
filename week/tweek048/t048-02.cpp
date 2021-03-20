#include <bits/stdc++.h>
using namespace std;

class AuthenticationManager {
   public:
    AuthenticationManager(int timeToLive) : m_timeToLive(timeToLive) {}

    void generate(string tokenId, int currentTime) {
        int expire_time = currentTime + m_timeToLive;
        m_tokeTime_map[tokenId] = expire_time;
        m_expireTime_map[expire_time].insert(tokenId);
    }

    void renew(string tokenId, int currentTime) {
        if (!m_tokeTime_map.count(tokenId) ||
            currentTime >= m_tokeTime_map[tokenId]) {
            return;
        }
        m_expireTime_map[m_tokeTime_map[tokenId]].erase(tokenId);
        int expire_time = currentTime + m_timeToLive;
        m_expireTime_map[expire_time].insert(tokenId);
        m_tokeTime_map[tokenId] = expire_time;

    }

    int countUnexpiredTokens(int currentTime) {
        int cnt = 0;
        for(auto it=m_expireTime_map.rbegin();it!=m_expireTime_map.rend();++it){
            if(it->first > currentTime){
                cnt += it->second.size();
            }else break;
        }
        return cnt;
    }

   private:
    int m_timeToLive;
    // key:expiredtime, values : tokens;
    map<int, unordered_set<string>> m_expireTime_map;
    // key: token ,value : expire_time;
    map<string, int> m_tokeTime_map;
};

/**
 * Your AuthenticationManager object will be instantiated and called as such:
 * AuthenticationManager* obj = new AuthenticationManager(timeToLive);
 * obj->generate(tokenId,currentTime);
 * obj->renew(tokenId,currentTime);
 * int param_3 = obj->countUnexpiredTokens(currentTime);
 */