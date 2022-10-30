#include <unordered_map>
#include <vector>

/*
the main idea is to map the elements to there frequency then return the max frequency 
*/
class Solution {
public:
    int majorityElement(std::vector<int>& nums) {
        std::unordered_map<int,int> m;
        for(auto i: nums){
            m[i]++;
        }
        int max = 0;
        int majorityElement = *nums.begin();
        for(auto j: m){
            if(j.second>max){
                max = j.second;
                majorityElement= j.first;
            }
        }
        return majorityElement;
    }
};

/*
from leetCode: Approach 7: Boyer-Moore Voting Algorithm
Intuition
If we had some way of counting instances of the majority element as +1+1+1 and instances of any other element as −1-1−1,
summing them would make it obvious that the majority element is indeed the majority element.
furthermore we know only the majority element can "win this race" throughout the whole array

Algorithm
Essentially, what Boyer-Moore does is look for a suffix sufsufsuf of nums where suf[0] is the majority element in that suffix.
To do this, we maintain a count, which is incremented whenever we see an instance of our current candidate for majority element
and decremented whenever we see anything else.
Most importantly - whenever count equals 0, we effectively forget about everything in nums up to the current index
and consider the current number as the candidate for majority element.
It is not immediately obvious why we can get away with forgetting prefixes of nums - consider the following examples
(pipes are inserted to separate runs of nonzero count).
candidate - [--------7--------|---5--|-----5------|-----7-----]
count     - [1, 2, 1, 2, 1, 0 | 1, 0 | 1, 2, 1, 0 | 1, 2, 3, 4] 
array     - [7, 7, 5, 7, 5, 1 | 5, 7 | 5, 5, 7, 7 | 7, 7, 7, 7]
note: the number count at the end of the algorithm is the difference between the majority element and all other numbers

Here, the 7 at index 0 is selected to be the first candidate for majority element. count will eventually reach 0 after index 5 is processed, so the 5 at index 6 will be the next candidate. In this case, 7 is the true majority element, so by disregarding this prefix, we are ignoring an equal number of majority and minority elements - therefore, 7 will still be the majority element in the suffix formed by throwing away the first prefix.

[7, 7, 5, 7, 5, 1 | 5, 7 | 5, 5, 7, 7 | 5, 5, 5, 5]

Now, the majority element is 5 (we changed the last run of the array from 7s to 5s), but our first candidate is still 7. In this case, our candidate is not the true majority element, but we still cannot discard more majority elements than minority elements (this would imply that count could reach -1 before we reassign candidate, which is obviously false).

Therefore, given that it is impossible (in both cases) to discard more majority elements than minority elements, we are safe in discarding the prefix and attempting to recursively solve the majority element problem for the suffix. Eventually, a suffix will be found for which count does not hit 0, and the majority element of that suffix will necessarily be the same as the majority element of the overall array.
*/
class  BoyerMooreSolution {
public:
    int majorityElement(std::vector<int>& nums) {
        int count = 0;
        int majorityElement = *nums.begin();
        for(auto i: nums){
            if(majorityElement == i){
                count++;
            }
            else{
                count--;
                if(count < 0){
                   majorityElement = i;
                   count = 1;
                }
            }
        }
        return majorityElement;
    }
};

int main(){
    std::vector<int> vec = {7, 7, 5, 7, 5, 1 , 5, 7 , 5, 5, 7, 7 ,7, 7, 7, 7};
    Solution s1;
    BoyerMooreSolution s2;
    int result1 = s1.majorityElement(vec);
    int result2 = s2.majorityElement(vec);
}