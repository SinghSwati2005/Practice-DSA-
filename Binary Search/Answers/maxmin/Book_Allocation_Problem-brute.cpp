/* Allocate Minimum Number of Pages



1

Problem Statement: Given an array ‘arr of integer numbers, ‘ar[i]’ represents the number of pages in the ‘i-th’ book. There are a ‘m’ number of students, and the task is to allocate all the books to the students.
Allocate books in such a way that:

Each student gets at least one book.
Each book should be allocated to only one student.
Book allocation should be in a contiguous manner.
You have to allocate the book to ‘m’ students such that the maximum number of pages assigned to a student is minimum. If the allocation of books is not possible. return -1

Examples
Example 1:

Input Format: n = 4, m = 2, arr[] = {12, 34, 67, 90}
Result: 113
Explanation: The allocation of books will be 12, 34, 67 | 90. One student will get the first 3 books and the other will get the last one.


Example 2:
Input Format:
 n = 5, m = 4, arr[] = {25, 46, 28, 49, 24}
Result:
 71
Explanation: The allocation of books will be 25, 46 | 28 | 49 | 24.
 */

#include<iostream>
#include<vector>
#include<algorithm>
#include <numeric>

using namespace std;

int countStudents(vector<int>&nums, int pages){
int  n = nums.size();
int students =1;
int pagesSTudent = 0;
for(int i=0;i<n;i++){
    if(pagesSTudent + nums[i]<=pages){
        pagesSTudent+=nums[i];
    }
    else{
        students++;
        pagesSTudent = nums[i];
    }
}
return students;
}



int findPages(vector<int>&nums , int n , int m){
if(m>n) return -1;
int low = *max_element(nums.begin(), nums.end());
int high = accumulate(nums.begin(), nums.end(),0);

for(int pages = low;pages<=high;pages++){
    if(countStudents(nums,pages)==m){
        return pages;
    }
}
return low;
}

int main(){
    int n ;
    int m ;
    cin>>n>>m;
    vector<int>nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    cout<<findPages(nums,n,m)<<" ";
    return 0;
}