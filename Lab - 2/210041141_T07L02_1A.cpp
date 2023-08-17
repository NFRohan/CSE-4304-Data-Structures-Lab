#include<iostream>
#include<string>
#include<vector>
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
        int targetIndex{0}, levels{0}, trials{0}, mark{0}, gradeIndex{0}, intp{0}; 
        string insp;
        vector<int> lower_threshold;
        vector<string> grades;

        cin >> levels >> trials;
        for(int i = 0; i < levels; i++){
            cin >> intp >> insp;
            lower_threshold.push_back(intp);
            grades.push_back(insp);
        }
        for(int j = 0; j < trials ;j++){
            cin >> mark;
            if(mark < lower_threshold[0]){
                cout << "F" << endl;
            }
            else{
                gradeIndex = searchInsert(lower_threshold, mark);
                cout << grades[gradeIndex - 1] << endl;
            }
            

        }

}