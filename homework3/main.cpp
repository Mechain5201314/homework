#include"../../vector/queue.h"

#include <iostream>
#include <time.h>
#include <stack>
#include <vector>
using namespace std;


int mianji(const vector<int>& heights) {
	const int n = heights.size();
	int res = 0;
	for (int i = 0; i < n; ++i) {
		int left = i, right = i;
		while (left >= 0 && heights[left] >= heights[i])
			--left;
		while (right < n && heights[right] >= heights[i])
			++right;
		res = max(res, heights[i] * (right - left - 1));
	}
	return res;
}

int main() {
	srand(static_cast<unsigned>(time(nullptr))); //随机种子
	const int array_size = 10;
	for (int k = 0; k < 10; ++k) {
		int s1[array_size];
		cout << "每个柱型高度：";
		for (int j = 0; j < array_size; ++j) {
			s1[j] = rand() % 100; //为柱型赋随机值
			cout << s1[j] << " ";
		}
		cout << endl;
		vector<int> heights(begin(s1), end(s1));
		int res = mianji(heights); //计算最大面积
		cout << "最小面积：" << res << endl;//输出最大面积
	}
	//输入高度
	int s2[array_size];
	cout << "请输入高度：";
	for (int k = 0; k < array_size; ++k) {
		cin >> s2[k];
	}
	cout << "高度为：";
	for (int k = 0; k < array_size; ++k) {
		cout << s2[k] << " ";
	}
	cout << endl;
	vector<int> heights2(begin(s2), end(s2));
	int res2 = mianji(heights2); //计算最大面积
	cout << "最小面积：" << res2 << endl; //输出最大面积
	return 0;
}
