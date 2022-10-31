#include <vector>
#include <algorithm>
#include <iostream>

/*
two types of solutions:
type 1 - operation: change the not allowed operation to an equivalent operation - like the swap or addition questions

by KyleOckerlund:
Use the Fundamental Theorem of Arithmetic.

The theorem states that any number can be broken into primes. 10 becomes 2x5, 20 becomes 2x2x5, and so on. Further, we can represent every number purely by prime exponents, we need only set a, b, c, ... as desired: -1^a x 1^b x 2^c x 3^d x 5^e x 7^f x....

We can put those in an array.

Suppose we looked at [0, 1, 1, 3, 1, 1]. Using these values as exponents yields the number: (-1^0) x (1^1) x (2^3) x (3^1) x (5^1) = 120.

Then, division is simply seeing what "cancels". So, to 'divide', we need only subtract these exponent arrays. 120/ 2 = [0, 1, 1, 3, 1, 1] - [0, 0, 0, 1, 0, 0] = [0, 1, 1, 2, 1, 1], or, to go through the formula above, 60. For multiplication, add instead, and you're done.

This approach has a major downside: Calculation. You need to calculate maps of numers to their factor-arrays, which takes some time. However, it only needs to be called once. So, this concept may work well in production, where a table can be stored. This is especially true if all of the numbers are under, say, 1000.

An advantage you get in return, then, is that manipulation becomes much easier. Want to exclude two indicies? Easily done, just subtract the exponents from index i+1 or whatever the case may be. Want to halve everything? Easily done, just pull out a two.

It's a nifty trick that gives a lot of flexibility, albeit for a hefty initialization time.

type 2 - index: find a way to calculate the product wthout indices of your choice - dynamic programming
*/
class Solution {
public:
    std::vector<int> productExceptSelf(std::vector<int>& nums) {
        //calc the suf an pre of all elements
        std::vector<int> result(nums.size());
        std::vector<int> pre(nums.size());
        std::vector<int> suf(nums.size());
        for (int i = 0; i < nums.size(); i++){
            if(i == 0){
                pre[i] = 1;
                suf[nums.size()-1] = 1;   
            }
            else {
                pre[i] = pre[i-1]*nums[i-1];
                suf[nums.size()- i-1] = suf[nums.size()- i]*nums[nums.size()-i]; 
            }  
        }

        for (int i = 0; i < nums.size(); i++){
            result[i] = pre[i]*suf[i];
        }
        return result;
    }
};

int main(){   
    std::vector<int> vec1 = {1,4,2,-2,3};
    std::vector<int>  vec2 = {-1,1,0,3,2};
    Solution s;
    std::vector<int> result1 = s.productExceptSelf(vec1); 
    std::vector<int> result2 = s.productExceptSelf(vec2); 
    return 0;
}