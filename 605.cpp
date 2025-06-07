class Solution {
    public:
        bool canPlaceFlowers(vector<int>& flowerbed, int n) {
            int count=0;
            flowerbed.push_back(0);
            flowerbed.insert(flowerbed.begin(),0);
            int j=0;
            for(int i=0; i<flowerbed.size();++i)
            {
                if(flowerbed[i]==0)
                {
                    ++j;
                }
                if(flowerbed[i]==1)
                {
                    count+=ceil(j/2.0)-1;
                    j=0;
                }
            }
            count+=ceil(j/2.0)-1;
            return count>=n;
        }
    };

// Reference Solution
// class Solution {
//     public:
//         bool canPlaceFlowers(vector<int>& flowerbed, int n) {
//             int count = 0;
//             for (int i = 0; i < flowerbed.size(); ++i) {
//                 if (flowerbed.at(i) == 0 && (i == 0 || flowerbed.at(i - 1) == 0) && (i == flowerbed.size() - 1 || flowerbed.at(i + 1) == 0)) {
//                     flowerbed.at(i) = 1;
//                     ++count;
//                 }
//             }
//             return count >= n;
//         }
// };
