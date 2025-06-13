/*

Topics
premium lock icon
Companies
Hint
You have a set which contains all positive integers [1, 2, 3, 4, 5, ...].

Implement the SmallestInfiniteSet class:

SmallestInfiniteSet() Initializes the SmallestInfiniteSet object to contain all positive integers.
int popSmallest() Removes and returns the smallest integer contained in the infinite set.
void addBack(int num) Adds a positive integer num back into the infinite set, if it is not already in the infinite set.
*/

#include <set>
using namespace std;

class SmallestInfiniteSet {
public:
    set<int> s;
    int ptr=0;
    SmallestInfiniteSet() {
    }

    int popSmallest() {
        if(s.empty()){
            ptr++;
            return ptr;
        }
        int min=*s.begin();
        s.erase(s.begin());
        return min;
    }
    
    void addBack(int num) {
        if(num<=ptr){   
            s.insert(num);
        }
    }
};

/**
class SmallestInfiniteSet {
    set<int> addedIntegers;
    int currentInteger;
public:
    SmallestInfiniteSet() {
        // The positive integer set's first element will be 1.
        currentInteger = 1;
    }
    int popSmallest() {
        int answer;
        // If there are numbers in the sorted-set, 
        // first element is lowest among all the available numbers.
        if (!addedIntegers.empty()) {
            answer = *addedIntegers.begin();
            addedIntegers.erase(addedIntegers.begin());
        } 
        // Otherwise, the smallest number of large positive set 
        // denoted by 'currentInteger' is the answer.
        else {
            answer = currentInteger;
            currentInteger += 1;
        }
        return answer;
    }
    void addBack(int num) {
        if (currentInteger <= num || 
            addedIntegers.find(num) != addedIntegers.end()) {
            return;
        }
        // We push 'num' in the sorted-set if it isn't already present.
        addedIntegers.insert(num);
    }
};
 */