#from Sort import Sort

class QuickSort(object):

    def sort(self, arr, left, right):
        if left >= right:
            return
        
        pivot = arr[left]
        low, high = left, right
        while low < high:
            while arr[low] <= pivot and low < right:
                low += 1
            while arr[high] >= pivot and high > left:                
                high -= 1
            if low >= high:
                break
            arr[low], arr[high] = arr[high], arr[low]

        arr[left], arr[high] = arr[high], arr[left]
        self.sort(arr, left, high - 1)
        self.sort(arr, high + 1, right)

    def threeWaySort(self, arr, left, right):
        if left >= right:
            return

        low, high = left, right
        mid = low + 1
        pivot = arr[left]

        while mid <= high:
            if arr[mid] < pivot:
                arr[mid], arr[low] = arr[low], arr[mid]
                low += 1
                mid += 1
            elif arr[mid] == pivot:
                mid += 1
            else:
                arr[mid], arr[high] = arr[high], arr[mid]
                high -= 1
        self.threeWaySort(arr, left, low - 1)
        self.threeWaySort(arr, high + 1, right)
    
if __name__ == "__main__":
    arr = [1, 2, 3, 2, 4, 7, 6, 5, 7, 6, 7, 5, 3]
    print(arr)
    qs = QuickSort()
    qs.sort(arr, 0, 12)
    print(arr)