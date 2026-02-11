#include <iostream>
using namespace std;

int largest_element(int arr[], int n) {
    int maxi = arr[0];  // Initialize with the first element
    for (int i = 1; i < n; i++) {
        if (arr[i] > maxi) {
            maxi = arr[i];
        }
    }
    return maxi;
}

int main() {
    int arr[100];
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int maxi = largest_element(arr, n);  // Call the function to find the largest element
    cout << "The largest element in the array is: " << maxi << endl;

    return 0;
}
