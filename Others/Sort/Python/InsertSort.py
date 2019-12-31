class InsertSort(object):

    def sort(self, arr):
        i = 1
        while i < len(arr):
            self.insert(arr, i - 1, i)
            i += 1

    def insert(self, arr, end, index):
        if end <= 0:
            return
        if arr[index] >= arr[end]:
            return
        arr[index], arr[end] = arr[end], arr[index]
        self.insert(arr, end - 1, end)

if __name__ == "__main__":
    arr = [1, 2, 2, 3, 4, 7, 6, 5, 7, 6, 7, 5, 3]
    inSort = InsertSort()
    inSort.sort(arr)
    print(arr)