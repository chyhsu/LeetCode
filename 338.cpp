
#include<vector>
#include<string>
using namespace std;
class Solution {
public:
    string toBinary(int n) {
        if (n == 0) return "0";

        std::string binary = "";
        while (n > 0) {
            // Get the remainder (0 or 1) and prepend it to the string
            binary = (n % 2 == 0 ? "0" : "1") + binary;
            // Integer division by 2
            n /= 2;
        }
        return binary;
    }
    int count_1(string a){
        int r=0;
        for(auto i:a){
            if(i=='1'){
                ++r;
            }
        }
        return r;
    }
    vector<int> countBits(int n) {
        vector<int> result;
        for(int i=0;i<=n;++i){
            result.push_back(count_1(toBinary(i)));
        }
        return result;
    }
};

/*
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n+1);
        ans[0]=0;
        for (int i=1;i<=n;i++) {
            ans[i] = ans[i/2] + (i&1);
        }
        return ans;
    }
};
*/