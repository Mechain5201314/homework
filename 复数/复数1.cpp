# include"D:\qyc\Dev-Cpp\Vector/Vector.h"
# include"D:\qyc\Dev-Cpp\Vector/Complex.h"
#include <iostream>
using namespace std;
int main(){
	Complex num[20];
	cout << "�������һ������ĸ�������" <<endl; 
	for (int i = 0; i < 20; i++){
		num[i].n_Real(rand() % 20 + 10);num[i].n_Imaginary(rand() % 20 + 10);num[i].n_modulus();
		num[i].display();}
	cout<<endl;
	Vector<Complex> num1(num,20);


	num1.unsort(0,20);
	cout <<endl<< "��������" << endl;
	for(int j=0;j<20;j++)
		num1._elem[j].display();
	//���� 

	cout<<endl;
	int local;
	local = num1.find0(num[0]);
	cout<<endl<<"ԭ�������һ��Ԫ�����Һ��λ��Ϊ"<<endl<<local<<endl;
	//����

	Vector<Complex> num2(num,1);
	num2[0].n_Real(rand() % 200 / 10 );
	num2[0].n_Imaginary(rand() % 200 / 10 );
	num1.insert( 10, num2[0]);
	cout<<endl<<"��һ������������뵽ĩβ" <<endl; 
	for(int j = 0 ;j <=20; j++ )
		num1._elem[j].display(); 
	cout<<endl;
	//����

	cout<<endl<<"ɾ����һ������"<<endl;
	num1.remove(10);
	for(int j=0;j<20;j++)
		num1._elem[j].display();
	cout<<endl;
	//ɾ��

	Vector<Complex> num3(num,1);
	num3[0].n_Real(4);
	num3[0].n_Imaginary(6);
	int k = rand() % 8 + 2; 
	for( int j = 0; j < k; j++)
	num1.insert(rand() % 8 + 2 , num3[0]);
	cout<<endl<<"Ψһ��ǰ��"<<endl;
	for(int j = 0; j <=20 + k; j++ )
		num1._elem[j].display();
	int x = num1.deduplicate();
	cout<<endl<<"�ظ�Ԫ�ظ���: "<< x <<endl;
	cout<<endl<<"Ψһ����"<<endl;
	num1.deduplicate();
	for(int j = 0; j < (20 + k - x) ; j++ )
		num1._elem[j].display();}
	//Ψһ��
