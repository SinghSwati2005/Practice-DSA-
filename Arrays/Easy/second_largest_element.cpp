#include <iostream>
#include <climits>  // for INT_MIN
using namespace std;

int second_largest_element(int arr[], int n) {
    if (n < 2) {
        cout << "Array must have at least two elements." << endl;
        return INT_MIN;
    }

    int largest = arr[0];
    int second_largest = INT_MIN;

    for (int i = 1; i < n; i++) {
        if (arr[i] > largest) {
            second_largest = largest;  // update second largest
            largest = arr[i];          // update largest
        } else if (arr[i] > second_largest && arr[i] != largest) {
            second_largest = arr[i];
        }
    }

    return second_largest;
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

    int second_largest = second_largest_element(arr, n);
    if (second_largest == INT_MIN) {
        cout << "No second largest element found." << endl;
    } else {
        cout << "The second largest element in the array is: " << second_largest << endl;
    }

    return 0;
}
