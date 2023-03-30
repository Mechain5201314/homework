# include"D:\qyc\Dev-Cpp\Vector/Vector.h"
# include"D:\qyc\Dev-Cpp\Vector/Complex.h"
# include <iostream>
# include <ctime>
using namespace std;

void generateRandomComplex(Complex& c){
	c.n_Real(rand() % 20 + 10);
	c.n_Imaginary(rand() % 20 + 10);
	c.n_modulus();
}

int main(){
	const int N = 10000;
	Complex num[N];
	cout<<"生成随机无序向量"<<endl;
	for( int i = 0; i < N; i++ ){
		generateRandomComplex(num[i]);
	}
	cout<<endl;
	
	Vector<Complex> num1(num, N);
	clock_t StartTime1, EndTime1;
	StartTime1 = clock();
	num1.bubbleSort(0,N);
	EndTime1 = clock();
	double TotalTime1 = (double)(EndTime1 - StartTime1);
	cout<<"冒泡排序时间"<< TotalTime1 << "ms" << endl;
	
	Vector<Complex> num2(num, N);
	clock_t StartTime2, EndTime2;
	StartTime2 = clock();
	num2.mergeSort(0,N);
	EndTime2= clock();
	double TotalTime2 = (double)(EndTime2 - StartTime2);
	cout<<"归并排序时间"<< TotalTime2 << "ms" << endl;
	
} 
