class HeapSort(object):

    def heapify(self, arr, index, length):
        if index >= length:
            return
        left = 2 * index + 1
        right = 2 * index + 2
        maxIndex = index

        if left < length and arr[left] > arr[maxIndex]:
            maxIndex = left
        
        if right < length and arr[right] > arr[maxIndex]:
            maxIndex = right

        if maxIndex != index:
            arr[maxIndex], arr[index] = arr[index], arr[maxIndex]
            self.heapify(arr, maxIndex, length)

    def buildHeap(self, arr, length):
        lastNode = length - 1
        start = int((lastNode - 1) / 2)
        while start >= 0:
            self.heapify(arr, start, length)
            start -= 1
    
    def sort(self, arr):
        length = len(arr)
        self.buildHeap(arr, length)
        i = length - 1

        while i > 0:
            arr[0], arr[i] = arr[i], arr[0]
            self.heapify(arr, 0, i)
            i -= 1

if __name__ == "__main__":
    arr = [4, 5, 6, 2, 1, 5, 7, 8, 0, 100, 3, 9]
    s = HeapSort()
    s.sort(arr)
    print(arr)

