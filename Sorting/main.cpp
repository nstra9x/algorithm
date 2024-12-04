#include <iostream>
#include <vector>

using namespace std;

#define FLAG 0

void swap(int &number_one, int &number_two)
{
	int intermedium = number_one;
	number_one = number_two;
	number_two = intermedium;
}

vector<int> selection_sort(const vector<int>& arr) {
	vector<int> result = arr;

	for (int i = 0; i < result.size() - 1; ++i) {
		int min_idx = i;
		for (int j = i + 1; j < result.size(); ++j) {
			if (result[j] < result[min_idx]) {
				min_idx = j;
			}
		}
		if (min_idx != i) {
			swap(result[i], result[min_idx]);
		}
	}

	return result;
}

vector<int> insertion_sort(const vector<int>& arr) {
	vector<int> result = arr;
	for (int i = 1; i < arr.size(); ++i) {
#if FLAG
		// Method 1
		int idx = i;
		for (int j = i - 1; j >= 0; --j) {
			if (result[idx] < result[j]) {
				swap(result[idx], result[j]);
				idx = j;
			}
		}
	}
#else
		// Method 2
		int key = result[i];
		int idx = i - 1;
		while (idx >= 0 && key < result[idx]) {
			result[idx + 1] = result[idx];
			idx--;
		}

		result[idx + 1] = key;
#endif
	}

	return result;
}

vector<int> counting_sort(const vector<int>& arr) {
	int max = *std::max_element(arr.begin(), arr.end());
	vector<int> result(max + 1);

	for (const auto& it : arr) {
		result[it]++;
	}

	vector<int> output;
	for (int i = 0; i < result.size(); ++i) {
		while (result[i] > 0) {
			output.push_back(i);
			result[i]--;
		}
	}


	return output;
}

void merge(vector<int> &arr, int left, int mid, int right) {
	int size_one = mid - left + 1;
	int size_two = right - mid;

	vector<int> arr_one(size_one);
	vector<int> arr_two(size_two);

	for (int i = 0; i < size_one; ++i) {
		arr_one[i] = arr[left + i];
	}

	for (int j = 0; j < size_two; ++j) {
		arr_two[j] = arr[mid + 1 + j];
	}

	int idx_one = 0;
	int idx_two = 0;
	int idx_merge = left;

	// merge two array
	while (idx_one < size_one && idx_two < size_two) {
		if (arr_one[idx_one] <= arr_two[idx_two]) {
			arr[idx_merge] = arr_one[idx_one];
			idx_one++;
		}
		else {
			arr[idx_merge] = arr_two[idx_two];
			idx_two++;
		}
		idx_merge++;
	}

	// if there are elements remaining in one of the two arrays
	while (idx_one < size_one) {
		arr[idx_merge] = arr_one[idx_one];
		idx_one++;
		idx_merge++;
	}
	while (idx_two < size_two) {
		arr[idx_merge] = arr_two[idx_two];
		idx_two++;
		idx_merge++;
	}
}

void merge_sort(vector<int> &arr, int left, int right) {
	if (left < right) {
		int mid = left + (right - left) / 2;
		merge_sort(arr, left, mid);
		merge_sort(arr, mid + 1, right);
		merge(arr, left, mid, right);
	}

}

int main() {
	vector<int> arr = { 38,27,43,3,9,82,10, 3, 3, 82 };
	vector<int> selection = selection_sort(arr);
	vector<int> insertion = insertion_sort(arr);
	vector<int> counting = counting_sort(arr);
	
	vector<int> merge = arr;
	merge_sort(merge, 0, merge.size() - 1);
	return 0;
}