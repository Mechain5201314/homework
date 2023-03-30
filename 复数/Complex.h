#include <iostream>
#include <cmath>
using namespace std;

class Complex{
public: 
    Complex(double real = 0, double imaginary = 0): m_real(real), m_imag(imaginary){ }
public:  
    friend bool operator> (const Complex &c1, const Complex &c2);
    friend bool operator< (const Complex &c1, const Complex &c2);
    friend bool operator==(const Complex &c1, const Complex &c2);
    friend bool operator!=(const Complex &c1, const Complex &c2);
     void display ();
     double n_Real (double r);
     double n_Imaginary (double i);
     double n_modulus();
    double display2();
public:  
    double real() const{ return m_real; }
    double imaginary() const{ return m_imag; }
    double modulus() const{ return m_modulus; } 
    double m_real;  
    double m_imag;  
    double m_modulus;  
};
bool operator==(const Complex &c1, const Complex &c2){
    if( c1.m_real == c2.m_real && c1.m_imag == c2.m_imag ){
        return true;
    }else{
        return false;
    }
}
bool operator>(const Complex &c1, const Complex &c2){
    if( c1.m_modulus > c2.m_modulus ){
        return true;
    }else{
        return false;
    }
}
bool operator>(const Complex &c1, double m){
    if( c1.m_modulus > m*m){
        return true;
    }else{
        return false;
    }
}
bool operator<(const Complex &c1, const Complex &c2){
    if(c1.m_modulus < c2.m_modulus ){
        return true;
    }else{
        return false;
    }
}
bool operator<(const Complex &c1, double m){
    if(c1.m_modulus < m*m ){
        return true;
    }else{
        return false;
    }
}
bool operator<=(const Complex &c1, const Complex &c2){
    if(c1.m_modulus <= c2.m_modulus ){
        return true;
    }else{
        return false;
    }
}
bool operator<=(const Complex &c1, double m){
    if(c1.m_modulus <= m*m ){
        return true;
    }else{
        return false;
    }
}
bool operator>=(const Complex &c1, double m){
    if(c1.m_modulus >= m*m ){
        return true;
    }else{
        return false;
    }
}
bool operator!=(const Complex &c1, const Complex &c2){
    if( c1.m_real != c2.m_real || c1.m_imag != c2.m_imag ){
        return true;
    }else{
        return false;
    }
}
void Complex::display (){
	if ( m_real != 0 ){
		if  ( m_imag > 0 ){
			cout << m_real << "+" << m_imag << "i" << " "; 
		}
		else cout << m_real << m_imag << "i" << " ";
	}
	if (m_imag == 0)
		cout << m_imag << "i" << " "; 
}
double Complex::display2 (){
	double x = m_modulus;
	return x;
}
double Complex::n_Real (double r){
    m_real = r;		
}
double Complex::n_Imaginary (double i){
    m_imag = i;		
}
double Complex::n_modulus(){
	m_modulus =m_imag * m_imag + m_real*m_real;
}

