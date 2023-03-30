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
	cout<<"���������������"<<endl;
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
	cout<<"ð������ʱ��"<< TotalTime1 << "ms" << endl;
	
	Vector<Complex> num2(num, N);
	clock_t StartTime2, EndTime2;
	StartTime2 = clock();
	num2.mergeSort(0,N);
	EndTime2= clock();
	double TotalTime2 = (double)(EndTime2 - StartTime2);
	cout<<"�鲢����ʱ��"<< TotalTime2 << "ms" << endl;
	
} 
