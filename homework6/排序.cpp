#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <chrono>
using namespace std;

// 交换两个数
void swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

// 起泡排序
void bubbleSort(vector<int>& nums) {
	int n = nums.size();
	for (int i = 0; i < n - 1; ++i) {
		bool changed = false;
		for (int j = 0; j < n - 1 - i; ++j) {
			if (nums[j] > nums[j + 1]) {
				swap(nums[j], nums[j + 1]);
				changed = true;
			}
		}
		if (!changed) break;
	}
}

// 插入排序
void insertionSort(vector<int>& nums) {
	for (int i = 1; i < nums.size(); ++i) {
		int cur = nums[i], j = i - 1;
		while (j >= 0 && nums[j] > cur) {
			nums[j + 1] = nums[j];
			--j;
		}
		nums[j + 1] = cur;
	}
}

// 选择排序
void selectionSort(vector<int>& nums) {
	int n = nums.size();
	for (int i = 0; i < n - 1; ++i) {
		int minIndex = i;
		for (int j = i + 1; j < n; ++j) {
			if (nums[j] < nums[minIndex]) {
				minIndex = j;
			}
		}
		if (minIndex != i) {
			swap(nums[i], nums[minIndex]);
		}
	}
}

// 归并排序
void merge(vector<int>& nums, int left, int mid, int right) {
	vector<int> temp(right - left + 1);
	int i = left, j = mid + 1, k = 0;
	while (i <= mid && j <= right) {
		if (nums[i] <= nums[j]) {
			temp[k++] = nums[i++];
		} else {
			temp[k++] = nums[j++];
		}
	}
	while (i <= mid) {
		temp[k++] = nums[i++];
	}
	while (j <= right) {
		temp[k++] = nums[j++];
	}
	for (int i = left; i <= right; ++i) {
		nums[i] = temp[i - left];
	}
}

void mergeSort(vector<int>& nums, int left, int right) {
	if (left >= right) return;
	int mid = (left + right) / 2;
	mergeSort(nums, left, mid);
	mergeSort(nums, mid + 1, right);
	merge(nums, left, mid, right);
}

// 快速排序
void quickSort(vector<int>& nums, int left, int right) {
	if (left >= right) return;
	int pivot = nums[left], i = left, j = right;
	while (i < j) {
		while (i < j && nums[j] > pivot) --j;
		if (i < j) nums[i++] = nums[j];
		while (i < j && nums[i] < pivot) ++i;
		if (i < j) nums[j--] = nums[i];
	}
	nums[i] = pivot;
	quickSort(nums, left, i - 1);
	quickSort(nums, i + 1, right);
}

// 堆排序
void heapify(vector<int>& nums, int i, int len) {
	int left = i * 2 + 1, right = i * 2 + 2, largest = i;
	if (left < len && nums[left] > nums[largest]) {
		largest = left;
	}
	if (right < len && nums[right] > nums[largest]) {
		largest = right;
	}
	if (largest != i) {
		swap(nums[i], nums[largest]);
		heapify(nums, largest, len);
	}
}

void buildHeap(vector<int>& nums) {
	int n = nums.size();
	for (int i = n / 2 - 1; i >= 0; --i) {
		heapify(nums, i, n);
	}
}

void heapSort(vector<int>& nums) {
	buildHeap(nums);
	int n = nums.size();
	for (int i = n - 1; i > 0; --i) {
		swap(nums[0], nums[i]);
		heapify(nums, 0, i);
	}
}

// 测试性能
void testPerformance(vector<int>& nums, string algoName) {
	auto start = chrono::steady_clock::now();
	if (algoName == "Bubble Sort") {
		bubbleSort(nums);
	} else if (algoName == "Insertion Sort") {
		insertionSort(nums);
	} else if (algoName == "Selection Sort") {
		selectionSort(nums);
	} else if (algoName == "Merge Sort") {
		mergeSort(nums, 0, nums.size() - 1);
	} else if (algoName == "Quick Sort") {
		quickSort(nums, 0, nums.size() - 1);
	} else if (algoName == "Heap Sort") {
		heapSort(nums);
	}
	auto end = chrono::steady_clock::now();
	auto duration = chrono::duration_cast<chrono::microseconds>(end - start).count();
	cout << algoName << ":\t" << duration << " microseconds" << endl;
}

int main() {
	// 生成顺序序列
	vector<int> nums1(10000);
	for (int i = 0; i < 10000; ++i) {
		nums1[i] = i;
	}
	
	// 生成逆序序列
	vector<int> nums2(10000);
	for (int i = 0; i < 10000; ++i) {
		nums2[i] = 10000 - i;
	}
	
	// 生成随机序列
	vector<int> nums3(10000);
	srand(time(NULL));
	for (int i = 0; i < 10000; ++i) {
		nums3[i] = rand() % 10000;
	}
	
	testPerformance(nums1, "Bubble Sort");
	testPerformance(nums1, "Insertion Sort");
	testPerformance(nums1, "Selection Sort");
	testPerformance(nums1, "Merge Sort");
	testPerformance(nums1, "Quick Sort");
	testPerformance(nums1, "Heap Sort");
	cout << endl;
	
	testPerformance(nums2, "Bubble Sort");
	testPerformance(nums2, "Insertion Sort");
	testPerformance(nums2, "Selection Sort");
	testPerformance(nums2, "Merge Sort");
	testPerformance(nums2, "Quick Sort");
	testPerformance(nums2, "Heap Sort");
	cout << endl;
	
	testPerformance(nums3, "Bubble Sort");
	testPerformance(nums3, "Insertion Sort");
	testPerformance(nums3, "Selection Sort");
	testPerformance(nums3, "Merge Sort");
	testPerformance(nums3, "Quick Sort");
	testPerformance(nums3, "Heap Sort");
	
	return 0;
}
