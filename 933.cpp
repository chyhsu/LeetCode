#include<queue>
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