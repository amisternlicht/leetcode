#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
        std::vector<std::vector<int>> solutions;
        std::sort(nums.begin(), nums.end());
        std::vector<int>::iterator left = nums.begin();
        std::vector<int>::iterator right = nums.end();
        right--;
        while(left + 1 < right){
            //look for the negative of there addition
            if(left + 1 == right-1){
                if (*(left+1) == -(*left+*right)){
                    std::vector<int> temp = {*left,-(*left+*right),*right};
                    if ( std::find(solutions.begin(), solutions.end(), temp) != solutions.end() );
                    else
                        solutions.push_back(temp);
                }
            }
            else {
                std::vector<int>::iterator it = std::find(left+1, right-1, -(*left+*right));
                if(it != nums.end() && (*it == -(*left+*right))){
                    std::vector<int> temp = {*left,-(*left+*right),*right};
                    if ( std::find(solutions.begin(), solutions.end(), temp) != solutions.end() );
                    else
                        solutions.push_back(temp);
                }
            }
            // if didnt find then move the larger one
            if(abs(*left) > abs(*right)){
                left++;
            }
            //missing equality!!!
            else if(abs(*left) == abs(*right)){

            }
            else
                right--;
        }
        return solutions;
    }
};


int main(){
    std::vector<int> vec = {-1,0,1,2,-1,-4};
    Solution s1;
    std::vector<std::vector<int>> result = s1.threeSum(vec);
}