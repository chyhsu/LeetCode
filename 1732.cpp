class Solution {
    public:
        int largestAltitude(vector<int>& gain) {
            int max=0;
            int temp=0;
            vector<int> altitude;
            altitude.push_back(0);
            for(int i=0;i<gain.size();++i){
                temp=altitude[i]+gain[i];
                altitude.push_back(temp);
                if(temp>max){
                    max=temp;
                }
            }
            return max;
        }
    };

//Reference Solution
// class Solution {
//     public:
//         int largestAltitude(vector<int>& gain) {
//             int alt = 0;
//             int maxAlt = 0;
    
//             for (int g : gain) {
//                 alt += g;
//                 maxAlt = max(maxAlt, alt);
//             }
    
//             return maxAlt;
//         }
//     };