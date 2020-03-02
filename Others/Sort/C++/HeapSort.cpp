#include <iostream>
#include <vector>

using namespace std;
class HeapSort {
private:
    void heapify(vector<int>&arr, int index, int length) {
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        int maxIndex = index;

        if (index >= length) {
            return;
        }

        if (left < length && arr[left] > arr[maxIndex]) {
            maxIndex = left;
        }

        if (right < length && arr[right] > arr[maxIndex]) {
            maxIndex = right;
        }

        if (maxIndex != index) {
            int tmp = arr[maxIndex];
            arr[maxIndex] = arr[index];
            arr[index] = tmp;
            heapify(arr, maxIndex, length);
        }
    }
    void buildHeap(vector<int>&arr, int length) {
        int endIndex = length - 1;
        int startIndex = (endIndex - 1) / 2;

        while (startIndex >= 0) {
            heapify(arr, startIndex, length);
            startIndex--;
        }
    }

public:
    void sort(vector<int>&arr) {
        int length = arr.size();
        buildHeap(arr, length);
        int i = length - 1;

        while (i > 0) {
            int tmp = arr[i];
            arr[i] = arr[0];
            arr[0] = tmp;
            heapify(arr, 0, i);
            i--;
        }
    }

    void printArr(vector<int>&arr) {
        for (int i = 0; i < arr.size(); i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main(int argc, char *argv[]) {
    HeapSort hs;
    vector <int> arr({2, 3, 1, 5, 7, 9, 0, 10, 4, 5});
    hs.sort(arr);
    hs.printArr(arr);
}