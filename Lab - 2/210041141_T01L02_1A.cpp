#include<iostream>
#include<vector>
#include<string>
using namespace std;

int searchInsert(vector<int>& nums, int target) {
        int left, right, mid;
        left = 0;
        right = nums.size() - 1;
        while(left <= right){
            mid = (right+left) / 2;
            if(nums[mid] == target){
                return mid;
            }
            if(nums[mid] > target){
                right = mid - 1;
            }
            else{
                left = mid + 1;
            }
        }
        return left;
    }


int main(){
    int numberSoldier{0}, numRounds{0}, numKilled{0}, intp{0}, index{0};
    vector<int> powerSoldier;
    cin >> numberSoldier >> numRounds;
    for(int i = 0; i < numberSoldier; i++){
        cin >> intp;
        powerSoldier.push_back(intp);
    }
    for(int j = 0; j < numRounds; j++){
        cin >> intp;
        index = searchInsert(powerSoldier, intp);
        if(powerSoldier[index] == intp){
            cout << index+1 << endl;
        }
        else{
            cout << index << endl;
        }
    }
}