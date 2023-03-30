# include"D:\qyc\Dev-Cpp\Vector/Vector.h"
# include"D:\qyc\Dev-Cpp\Vector/Complex.h"
#include <iostream>
using namespace std;
int main(){
	Complex num[20];
	cout << "随机生成一个无序的复数向量" <<endl; 
	for (int i = 0; i < 20; i++){
		num[i].n_Real(rand() % 20 + 10);num[i].n_Imaginary(rand() % 20 + 10);num[i].n_modulus();
		num[i].display();}
	cout<<endl;
	Vector<Complex> num1(num,20);


	num1.unsort(0,20);
	cout <<endl<< "进行置乱" << endl;
	for(int j=0;j<20;j++)
		num1._elem[j].display();
	//置乱 

	cout<<endl;
	int local;
	local = num1.find0(num[0]);
	cout<<endl<<"原向量组第一个元素置乱后的位置为"<<endl<<local<<endl;
	//查找

	Vector<Complex> num2(num,1);
	num2[0].n_Real(rand() % 200 / 10 );
	num2[0].n_Imaginary(rand() % 200 / 10 );
	num1.insert( 10, num2[0]);
	cout<<endl<<"把一个随机向量插入到末尾" <<endl; 
	for(int j = 0 ;j <=20; j++ )
		num1._elem[j].display(); 
	cout<<endl;
	//插入

	cout<<endl<<"删除第一个向量"<<endl;
	num1.remove(10);
	for(int j=0;j<20;j++)
		num1._elem[j].display();
	cout<<endl;
	//删除

	Vector<Complex> num3(num,1);
	num3[0].n_Real(4);
	num3[0].n_Imaginary(6);
	int k = rand() % 8 + 2; 
	for( int j = 0; j < k; j++)
	num1.insert(rand() % 8 + 2 , num3[0]);
	cout<<endl<<"唯一化前："<<endl;
	for(int j = 0; j <=20 + k; j++ )
		num1._elem[j].display();
	int x = num1.deduplicate();
	cout<<endl<<"重复元素个数: "<< x <<endl;
	cout<<endl<<"唯一化后："<<endl;
	num1.deduplicate();
	for(int j = 0; j < (20 + k - x) ; j++ )
		num1._elem[j].display();}
	//唯一化
