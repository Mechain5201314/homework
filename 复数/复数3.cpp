#include <iostream>
#include <algorithm> 
# include"D:\qyc\Dev-Cpp\Vector/Vector.h"
# include"D:\qyc\Dev-Cpp\Vector/Complex.h"
using namespace std;


using namespace std;

int main() {
	Complex num[10];
	cout << "生成无序随机向量";
	for (int i = 0; i < 10; i++) {
		num[i].n_Real(rand() % 20 + 10);
		num[i].n_Imaginary(rand() % 20 + 10);
		num[i].n_modulus();
	}
	cout << endl;
	Vector<Complex> num1(num, 20);
	for (int i = 0; i < 20; i++) {
		num1._elem[i].display();
	}
	cout << endl;
	num1.mergeSort(0, 20);
	cout << "排序后" << endl;
	for (int i = 0; i < 20; i++)
		num1._elem[i].display();
	cout << endl;
	
	auto last = std::unique(num1._elem, num1._elem + num1._size);
	int num_removed = num1._size - (last -num1._elem);
	num1._size = last - num1._elem;
	
	cout << "移除了 " << num_removed << " 个重复元素" << endl;
	cout << "去重后的结果：" << endl;
	for (int i = 0; i < num1._size; i++)
		num1._elem[i].display();
	   return 0;
	
}
