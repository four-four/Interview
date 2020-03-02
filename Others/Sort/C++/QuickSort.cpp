#include <iostream>
#include <vector>

using namespace std;

class QuickSort {
private:
    void swap(vector<int> &arr, int a, int b) {
        int tmp = arr[a];
        arr[a] = arr[b];
        arr[b] = tmp;
    }
    int partition(vector<int> &arr, int left, int right) {
        int pivot = arr[left];
        int p = left;
        left++;

        while (true) {
            while (arr[left] < pivot) {
                left++;
            }
            while (arr[right] > pivot) {
                right--;
            }

            if (left >= right) {
                break;
            }

            swap(arr, left, right);
        }
        swap(arr, p, right);
        return right;
    }
    void quickSort(vector<int> &arr, int left, int right) {
        if (right <= left) {
            return;
        }
        int p = partition(arr, left, right);
        quickSort(arr, left, p - 1);
        quickSort(arr, p + 1, right);
    }
public:
    void sort(vector<int> &arr) {
        quickSort(arr, 0, arr.size() - 1);
    }

    void printArr(vector<int>&arr) {
        for (int i = 0; i < arr.size(); i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main(int argc, char *argv[]) {
    QuickSort qs;
    vector <int> arr({2, 3, 1, 5, 7, 9, 0, 10, 4, 5});
    qs.sort(arr);
    qs.printArr(arr);
}