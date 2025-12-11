#include <iostream>
using namespace std;

void sortArray(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }
}

void binary_search(int max, int min) {
    int m = max;
    int n = min;
    int temp, c = 0;
    string answer, value, yes, no, higher, lower;

    while (1) {
        cout << "Left is : " << n << endl;
        cout << "Right is : " << m << endl;
        temp = (m + n) / 2;
        cout << "Is your answer " << temp << " ? " << endl;
        cout << "yes or no ?" << endl;
        cin >> answer;
        if (answer == "yes") {
            cout << "Finished guessing successfully!!" << endl;
            break;
        }
        else if (answer == "no") {
            cout << "Is your number higher or lower ? " << endl;
            cin >> value;
            if (value == "lower") {
                m = temp - 1;
            }
            else if (value == "higher") {
                n = temp + 1;
            }
        }
        else
            cout << "Choice is Incorrect! Please enter yes or no " << endl;
        c++;
    }
    cout << "The game took: " << c << " guesses";
}
void binarysearch() {
    int x;
    int count = 0;
    int max, min, mid, number;
    string yes, no, high, low, answer, value;
    cout << "Enter the amount of numbers in the array" << endl;
    cin >> number;
    cout << "Enter data " << endl;

    int* arr = new int[number];
    for (int i = 0; i < number; i++) {
        cout << "Enter element " << i + 1 << ": ";
        cin >> arr[i];
    }

    sortArray(arr, number);

    cout << "Sorted array: ";
    for (int i = 0; i < number; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;


    max = number - 1;
    min = 0;

    cout << "Enter the number you are searching for " << endl;
    cin >> x;

    while (true) {
        count++;
        cout << "New left is index: " << min << endl;
        cout << "New right is index: " << max << endl;
        cout << "Searching. . . ";
        cout << endl;
        if (min > max) {
            cout << "Number not found!" << endl;
            break;
        }

        mid = (max + min) / 2;

        if (arr[mid] == x) {
            cout << "Finished guessing successfully!! " << endl;
            cout << "Your number is at position number: " << mid + 1 << endl;;
            break;
        }
        else if (arr[max] == x) {
            cout << "Finished guessing successfully!!" << endl;
            cout << "Your number is at position number: " << max + 1 << endl;;
            break;
        }
        else if (arr[min] == x) {
            cout << "Finished guessing successfully!!" << endl;
            cout << "Your number is at position number: " << min + 1 << endl;;
            break;
        }
        else {
            if (arr[mid] < x) {
                min = mid + 1;

            }
            else if (arr[mid] > x) {
                max = mid - 1;

            }
        }
    }
    cout << "The game took " << count << " guesses.";
    delete[] arr;
}
void main() {
    int m, n;
    int choice;
    cout << "To search in sorted data you enter press 1: \nTo play as a search game press 2: \n";
    cin >> choice;

    switch (choice) {
    case 1:
        binarysearch();
        break;
    case 2:
        cout << "Enter lowest number: ";
        cin >> n;
        cout << "Enter highest number: ";
        cin >> m;
        binary_search(m, n);
        break;
    default:
        cout << "Invalid choice!" << endl;
        break;
    }
}
