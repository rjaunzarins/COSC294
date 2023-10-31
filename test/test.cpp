#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>

bool isPalindrome(int x);
bool isPalindromeNoString(int x);
int getAnswer();
std::vector<int> twoSum(std::vector<int>& nums, int target);
std::vector<int> twoSumVersion2(std::vector<int>& nums, int target);
std::vector<std::vector<int>> threeSum(std::vector<int>& nums);

int main(){

    //int answer = getAnswer();

    //std::cout << answer << std::endl;
    
    //std::cout << __cplusplus;


    // std::vector<int> param = {};
    // std::vector<std::vector<int>> sum = threeSum(param);
    

    // std::cout << "\n\nSolution: " << std::endl;
    // for (size_t i = 0; i < sum.size(); i++) {
    //     for (size_t j = 0; j < sum[0].size(); j++) {
    //         std::cout << sum[i][j] << ",";
    //     }
    //     std::cout << " ";
    // }
    // std::cout << std::endl; 
    int num = 12121;
    bool pal;
    std::cout << "isPalindrome: " << (pal = isPalindrome(num));
    std::cout << "\nisPalindromeNoString: " << (pal = isPalindromeNoString(num));
}



bool isPalindrome(int x) {
    std::string str = std::to_string(x);
    int start = 0, end = str.size()-1;
    while(start < end) {
        if(str[start] != str[end]) 
            return false;
        ++start;
        --end;
    }
    return true;
}

//   1 2 1
bool isPalindromeNoString(int x) {
    if(x < 0)
        return false;
    std::vector<int> pal;
    while(x/10 >= 1) {
        pal.push_back(x%10);
        x = (x/10);
    }
    pal.push_back(x%10);
    int start = 0, end = pal.size()-1;
    while(start < end) {
        if(pal[start] != pal[end]) 
            return false;
        ++start;
        --end;
    }
    return true;
}


int getAnswer() {
    //Use current time as seed for random generator
    srand(time(0));
    //Return random number
    //return rand()%2; // Gives random between 0 & 1
    //return rand()%2 +1 gives random between 1 & 2
    return rand()%10 + 10; // gives random number between 10 & 20
} 



std::vector<int> twoSum(std::vector<int>& nums, int target) {
    std::vector<int> solution;
    for(int i = 0; i < nums.size() - 1; ++i) {
        for(int j = i + 1; j < nums.size(); ++j) {
            if(nums[i] + nums[j] == target) {
                return solution = {i,j};
            }
        }
    }
    return solution = {};
}



std::vector<int> twoSumVersion2(std::vector<int>& nums, int target) {
    std::vector<int> solution;
    int head = 0, tail;
    while(head < nums.size()) {
        tail = head+1;
        while(tail < nums.size()) {
            if(nums[head] + nums[tail] == target)
                return solution = {head,tail};
            ++tail;
        }
        ++head;
    }  
    return solution = {-1,-1};  
}



std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
    std::vector<std::vector<int>> solution;
    std::vector<int> subSolution;
    //Sort first
    // for(int i = 0; i < nums.size() - 1; ++i) {
    //     for(int j = i+1; j < nums.size(); ++j) {
    //         if(nums[j] < nums[i]) {
    //             int temp = nums[i];
    //             nums[i] = nums[j];
    //             nums[j] = temp;
    //         }
    //     }
    // }
    std::sort(nums.begin(), nums.end());
    //Find Sums
    int vectorDifferent = 0;
    int elementDifferent = 0;
    for(int i = 0; i < nums.size()-2; ++i) {
        for(int j = i+1; j < nums.size()-1; ++j) {
            for(int k  = j+1; k < nums.size(); ++k) {
                if(i!=j && i != k && j != k) {
                    if(nums[i] + nums[j] + nums[k] == 0) {
                        subSolution = std::vector<int> {nums[i], nums[j], nums[k]};  // have to now ensure it doesnt match any other vector
                        std::cout << "\n1. subSolution: " << subSolution[0] << "," << subSolution[1] << "," << subSolution[2] << std::endl;
                        
                        if(solution.size() == 0) {
                            solution.push_back(subSolution);
                            std::cout << "*Added solution: " << solution[0][0] << "," << solution[0][1] << "," << solution[0][2] << std::endl;
                        }
                        
                        else {
                            for(int l = 0; l < solution.size(); ++l) {
                                elementDifferent = 0;
                                for(int m = 0; m < subSolution.size(); ++m) {
                                    if(subSolution[m] != solution[l][m]) {
                                        ++elementDifferent;
                                        //std::cout << "++elementDifferent: " << elementDifferent << std::endl;
                                    }
                                }
                                //std::cout << "2. Element Different: " << elementDifferent << "\n";
                                if(elementDifferent > 0)
                                    ++vectorDifferent;
                                    //std::cout << "++vectorDifferent: " << vectorDifferent << std::endl;
                            }
                            std::cout << "1. VectorDifferent: " << vectorDifferent << ", Solution.size(): " << solution.size() << "\n";
                            if(vectorDifferent == solution.size()) {
                                solution.push_back(subSolution);
                                std::cout << "*Added solution: " << nums[i] << "," << nums[j] << "," << nums[k] << std::endl;
                            }
                            else {
                                std::cout << "*Solution NOT added: " << nums[i] << "," << nums[j] << "," << nums[k] << std::endl;
                            }
                            vectorDifferent = 0;
                        }
                    }
                }
            }
        }
    }
    return solution;
}
