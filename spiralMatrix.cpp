#include <vector>
#include <algorithm>
#include <iostream>

using intVec = std::vector<int>;

/*
Approach 1: Traverse Layer by Layer in Spiral Form, starting from outermost layer(indexed 0)
each matrix has floor(n+1/2) layers, in each layer we will build the same kind of spiral.

https://leetcode.com/problems/spiral-matrix-ii/solutions/823106/spiral-matrix-ii/?envType=study-plan&id=data-structure-ii
the spiral:
In every direction, either row or column remains constant and other parameter changes (increments/decrements).

Direction 1: From top left corner to top right corner.

row = layer number, column increments starting from layer number up to n−layer−1

Direction 2: From top right corner to the bottom right corner.

column = n−layer−1, row increments from layer+1 to n−layer.

Direction 3: From bottom right corner to bottom left corner.

row = n−layer−1, column decrements from n−layer−2 to layer.

Direction 4: From bottom left corner to top left corner.

column = layer, row decrements from n−layer−2 to layer+1.

This process repeats (n+1)/2 times until all layers are traversed.
*/
class iterativeSolution {
public:
     std::vector<intVec> generateSpiralMatrix(int n) {
        //init matrix
        std::vector<intVec> result (n, intVec(n));
        int cnt = 1;
        int number_of_layers = (n + 1) / 2;
        for (int layer = 0; layer < number_of_layers; layer++) {
            // direction 1 - traverse from left to right, row = layer number, column increments
            for (int ptr = layer; ptr < n - layer; ptr++) {
                result[layer][ptr] = cnt++;
            }
            // direction 2 - traverse from top to bottom, column = n−layer−1, row increments
            for (int ptr = layer + 1; ptr < n - layer; ptr++) {
                result[ptr][n - layer - 1] = cnt++;
            }
            // direction 3 - traverse from right to left, row = n−layer−1, column decrements
            for (int ptr = n - layer - 2; ptr >= layer; ptr--) {
                result[n - layer - 1][ptr] = cnt++;
            }
            // direction 4 - traverse from bottom to top, column = layer, row decrements
            for (int ptr = n - layer - 2; ptr > layer; ptr--) {
                result[ptr][layer] = cnt++;
            }
        }
        return result;
    }
    void printMatrix(std::vector<intVec>& m){
        std::cout << "spiral matrix:" << std::endl;
        for(int i=0; i < m.size(); i++){
            for(int j=0; j < m[i].size(); j++){
                const int singleDigit = 10;
                if( m[i][j] < singleDigit){
                    std::cout << "  " << m[i][j] << " ";
                }
                else
                    std::cout << "  " << m[i][j];
            }
            std::cout << std:: endl;
        }
    }
};

int main(){   
    intVec vec1 = {1,4,7,11,15};
    intVec vec2 = {2,5,8,12,19};
    intVec vec3 = {3,6,9,16,22};
    intVec vec4 = {10,13,14,17,24};
    intVec vec5 = {18,21,23,26,30};
    std::vector<intVec> matrix = {vec1,vec2,vec3,vec4,vec5};
    iterativeSolution s;
    std::vector<intVec> result = s.generateSpiralMatrix(1); 
    s.printMatrix(result);  
    result = s.generateSpiralMatrix(4); 
    s.printMatrix(result); 
    result = s.generateSpiralMatrix(7); 
    s.printMatrix(result); 
    return 0;
}