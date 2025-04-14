#include <iostream>
#include <vector>
#include <sstream>
#include <string>
using namespace std;

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++)
            if (arr[j] < arr[minIdx])
                minIdx = j;
        swap(arr[i], arr[minIdx]);
    }
}

void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1, n2 = r - m;
    int L[n1], R[n2];

    for (int i = 0; i < n1; i++) L[i] = arr[l + i];
    for (int j = 0; j < n2; j++) R[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }

    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = (l + r) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

int linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++)
        if (arr[i] == key)
            return i;
    return -1;
}

int binarySearch(int arr[], int n, int key) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == key) return mid;
        else if (arr[mid] < key) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}

void displayArray(int arr[], int n) {
    cout << "Array: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
}

int main() {
    const int size = 100;
    int arr[size], n, choice, key;

    cout << "Enter number of elements: ";
    cin >> n;
    cin.ignore(); // Clear newline after cin

    string input;
    vector<int> temp;

    cout << "Enter elements: ";
    getline(cin, input);

    // Detect and process input
    if (input.find(' ') != string::npos) {
        // With spaces
        stringstream ss(input);
        int num;
        while (ss >> num) temp.push_back(num);
    } else {
        // Without spaces
        for (char ch : input) {
            if (isdigit(ch))
                temp.push_back(ch - '0');
        }
    }

    // Validate input count
    if (temp.size() != n) {
        cout << "Error: You entered " << temp.size() 
             << " elements but expected " << n << "." << endl;
        return 1;
    }

    // Copy to array
    for (int i = 0; i < n; i++) arr[i] = temp[i];

    do {
        cout << "\n--- MENU ---\n";
        cout << "1. Selection Sort\n";
        cout << "2. Merge Sort\n";
        cout << "3. Linear Search\n";
        cout << "4. Binary Search (Array must be sorted)\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        int result;

        switch (choice) {
            case 1:
                selectionSort(arr, n);
                cout << "\nSorted using Selection Sort:\n";
                displayArray(arr, n);
                break;
            case 2:
                mergeSort(arr, 0, n - 1);
                cout << "\nSorted using Merge Sort:\n";
                displayArray(arr, n);
                break;
            case 3:
                cout << "Enter element to search: ";
                cin >> key;
                result = linearSearch(arr, n, key);
                if (result != -1) cout << "Element found at index " << result << endl;
                else cout << "Element not found.\n";
                break;
            case 4:
                cout << "Enter element to search: ";
                cin >> key;
                result = binarySearch(arr, n, key);
                if (result != -1) cout << "Element found at index " << result << endl;
                else cout << "Element not found.\n";
                break;
            case 5:
                cout << "Exiting program. Thank you!\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }

    } while (choice != 5);

    return 0;
}
