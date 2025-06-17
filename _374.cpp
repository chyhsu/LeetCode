/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

 class Solution {
    public:
        int guessNumber(int n) {
            if(guess(n)==0) return n;
            int left=0;
            int right=n;
            int mid=left+(right-left)/2;
            while(guess(mid)!=0){
                if(guess(mid)==1){
                    left=mid;
                }else if(guess(mid)==-1){
                    right=mid;
                }
                mid=left+(right-left)/2;
            }
            return mid;
        }
    };