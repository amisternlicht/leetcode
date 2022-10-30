#include <vector>
#include <iostream>

/*
Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

You must solve this problem without using the library's sort function.
*/

//solution 1: simple bubble sort
class Solution {
public:
    void sortColors(std::vector<int>& nums) {
        for(int len = nums.size(); len > 0; len--){
            for(auto it = nums.begin(); it != (nums.begin()+len-1);it++){
                if(*it > *(it+1) ){
                    std::iter_swap(it,it+1);
                }
            }
        }
    }
};

//solution two: maintaining pointers which close in on the processed section (instead of processed section only at the end) 
/*
Consider three pointers low = 0, mid = 0, high = nums.size() - 1
The algorithm ensures that at any point, every element before low is 0, every element after high is 2, 
every element in between are either 0, 1 or 2 i.e. unprocessed.
We'll use mid pointer to traverse and check the array elements i.e. while(mid <= high). Three cases are possible:
nums[mid] == 0 In this case swap(nums[low], nums[mid]) and increment both low and mid pointer i.e. low++ mid++
nums[mid] == 1 In this case mid++
nums[mid] == 2 In this case swap(nums[mid], nums[high]) and decrement high pointer i.e. high--
*/
void sortColorsFifu(std::vector<int>& nums) {
    
    // initialize variables:
    int low = 0, mid = 0, high = nums.size() - 1;
    
    // logic:
    while(mid <= high)
    {
        switch(nums[mid])
        {
            case 0: std::swap(nums[low++], nums[mid++]); break;
            
            case 1: mid++; break;
            
            case 2: std::swap(nums[mid], nums[high--]); break;
        }
    }
}

int main(){
    std::vector<int> vec1 = {0,1,2,1,2,0,0};
    std::vector<int> vec2 = {0,1,2,1,2,0,0};
    Solution s;
    s.sortColors(vec1);
    sortColorsFifu(vec2);
}