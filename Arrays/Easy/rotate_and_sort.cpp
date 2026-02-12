#include<iostream>
#include<vector>
using namespace std;


bool rotate_and_sort(vector<int> &nums ){
    int n = nums.size();
    int count =0;
    for(int i =0;i<n;i++){
        if(nums[i]>nums[(i+1)%n]){
            count ++;
        }

    }
    return count<=1;
}
int main(){
    int n; 
    cout << "Enter the size of the array: ";
     cin >> n;
      vector<int> nums(n);
     cout << "Enter the elements of the array: ";
      for (int i = 0; i < n; i++) {
         cin >> nums[i];
         }
         bool result = rotate_and_sort(nums);
         cout << (result ? "true" : "false") << endl; 
         return 0;
}
