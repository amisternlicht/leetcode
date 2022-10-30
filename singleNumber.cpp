#include <vector>

class Solution {
public:
    int singleNumber(std::vector<int>& nums) {
        int result = 0;
        //we will XOR all numbers, because XOR is commutative and all numbers repeat result will be our number
        for (std::vector<int>::iterator i = nums.begin(); i!=nums.end();++i){
            result = result^*i;
        }
        return result;
    }
};

int main(){
    std::vector<int> vec = {4,1,2,1,2};
    Solution s;
    int result = s.singleNumber(vec);
}