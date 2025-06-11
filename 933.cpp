/*
LeetCode 933 – Number of Recent Calls
------------------------------------
Problem (re-phrased):
Implement a data structure RecentCounter that counts the number of calls
to the function ping that have happened within the last 3000
milliseconds (inclusive).  Each call to ping(int t) occurs with strictly
increasing integer timestamps t (in milliseconds) and returns the number
of calls in the interval [t-3000, t].

Input / API
 • Constructor: RecentCounter()
 • int ping(int t): 1 ≤ t ≤ 10⁹, timestamps are strictly increasing.

Output
 • For each ping call, return the number of pings that have happened in
   the time window [t-3000, t].
------------------------------------
*/
#include <queue>
using namespace std;
class RecentCounter {
    public:
        std::queue<int> set;
        RecentCounter() {
            while(!set.empty()){
                set.pop();
            }
        }
        
        int ping(int t) {
            set.push(t);
            while((t-set.front())>3000){
                set.pop();
            }
            return set.size();
        }
    };