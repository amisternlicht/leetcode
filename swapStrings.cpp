#include <iostream>
#include <string>

/* iterative solution to swap two concatenated strings in O(1) space*/
class Solution {
public:
    void swapStrings(std::string& strings, int len_of_first_string) {
        int len_of_second_string = strings.size() - len_of_first_string;
        if(len_of_second_string == len_of_first_string){
          for (int i = 0; i < len_of_first_string; i++){
                char temp = strings[i+len_of_first_string];
                strings[i+len_of_first_string] = strings[i];
                strings[i] = temp;
            }
        }
        else {
            int index = 0;
            char last_char = strings[index];
            for (int i = 0; i < strings.size(); i++){
                if(index < len_of_first_string){
                    index += len_of_second_string;
                    char temp = strings[index];
                    strings[index] = last_char;
                    last_char = temp;
                }
                else if (index >= len_of_first_string){
                    index -= len_of_first_string;
                    char temp = strings[index];
                    strings[index] = last_char;
                    last_char = temp;
                }
            }
        }
    }
        
};


int main(){
    std::string str1("hiworld");
    std::string str2("helloworld");
    std::string str3("whatare");

    Solution s1;
    s1.swapStrings(str1,2);
    if(str1.compare("worldhi")){ // returns 0 when they are equal
        std::cout << str1 << " didnt swap correctly!" << std::endl;
    }
    s1.swapStrings(str2,5);
    if(str2.compare("worldhello")){
        std::cout << str2 << " didnt swap correctly!" << std::endl;
    }
    s1.swapStrings(str3,4);
    if(str3.compare("arewhat")){
        std::cout << str3 << " didnt swap correctly!" << std::endl;
    }
}