#include"../../vector/stack.h"
#include<cctype>
#include<string>
#include<cstdlib>
#include<cstring>
#include<math.h>
#define N_OPTR 9 
typedef enum {
	ADD, SUB, MUL, DIV, POW, FAC, L_P, R_P, EOE
} Operator;

Operator optr2rank(char op) { 
	switch (op) {
		case '+':   return ADD; 
		case '-':   return SUB; 
		case '*':   return MUL; 
		case '/':   return DIV; 
		case '^':   return POW; 
		case '!':   return FAC; 
		case '(':   return L_P; 
		case ')':   return R_P; 
		case '\0':  return EOE; 
		default:  throw std::invalid_argument("Unknown Operator!");
	}
}
char orderBetween(char a, char b)
{
	const char pri[N_OPTR][N_OPTR] = {
		// 运算符优先等级 [栈顶] [弼前]
		/* |-------------------- 当 前 运 算 符 --------------------| */
		/* + - * / ^    !     (     )   \0 */
		/* -- + */ '>', '>', '<', '<', '<', '<', '<', '>', '>',
		/* | - */ '>', '>', '<', '<', '<', '<', '<', '>', '>',
		/* 栈 * */ '>', '>', '>', '>', '<', '<', '<', '>', '>',
		/* 顶 / */ '>', '>', '>', '>', '<', '<', '<', '>', '>',
		/* 运 ^ */ '>', '>', '>', '>', '>', '<', '<', '>', '>',
		/* 算 ! */ '>', '>', '>', '>', '>', '>', ' ', '>', '>',
		/* 符 ( */ '<', '<', '<', '<', '<', '<', '<', '=', ' ',
		/* | ) */ ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
		/* -- \0 */ '<', '<', '<', '<', '<', '<', '<', ' ', '='};
	return pri[optr2rank(a)][optr2rank(b)];
}

void ap(char *&rpn, float opnd)
{
	int n = strlen(rpn);
	char buf[64];
	if (opnd == 0){   
		sprintf(buf, "0 ");
	} else if (opnd == 1) {  
		sprintf(buf, "1 ");
	} else {
		if (opnd != (float)(int)opnd) {
			sprintf(buf, "%.2f ", opnd); // 将浮点数保留两位小数并转为字符串
		} else {
			sprintf(buf, "%d ", (int)opnd); // 直接转为整数并转为字符串
		}
	}
	
	rpn = (char *)realloc(rpn, sizeof(char) * (n + strlen(buf) + 1)); // 重新分配空间
	strcat(rpn, buf); // 将字符串拼接到后面
}

void ap(char *&rpn, char optr)
{
	int n = strlen(rpn);
	rpn = (char *)realloc(rpn, sizeof(char) * (n + 4)); // 增加一位空格和 '\0'
	rpn[n] = optr;
	rpn[n + 1] = ' '; 
	rpn[n + 2] = '\0'; 
}

void readNumber(char*& p, Stack<float>& stk) {
	float num = (float)(*p - '0');
	while(isdigit(*(++p))) {
		num = num * 10 + (*p - '0');
	}
	if('.' != *p) {
		stk.push(num);
		return;
	}
	float fraction = 1;
	while(isdigit(*(++p))) {
		fraction /= 10;
		num = num + (*p - '0') * fraction;
	}
	stk.push(num);
}
float calculate(char optr, float opnd)
{
	if (floor(opnd) == opnd)
		if (opnd == 0)
			return 1.0;
	else
	{
		float b = 1.0;
		for (float i = 1.0; i <= opnd; i++)
		{
			b *= i;
		}
		return b;
	}
	else
	{
		cout << "非整数无法阶乘" << endl;
	throw std::invalid_argument("Unknown Operator!");
	}
}

float calculate(float opnd1, char op, float opnd2)
{
	float result = 0; //存储计算结果
	switch (op)
{
case '+':
	result = opnd1 + opnd2;
	break;
case '-':
	result = opnd1 - opnd2;
	break;
case '*':
	result = opnd1 * opnd2;
	break;
case '/':
	if (opnd2 == 0) {
		cout << "ERROR:除数为0" << endl;
		exit(-1);
	}
	result = opnd1 / opnd2;
	break;
case '%':
	if ((int)opnd2 == 0) {
		cout << "ERROR:除数为0" << endl;
		exit(-1);
	}
	result = (int)opnd1 % (int)opnd2;
	break;
case '^':
	result = pow(opnd1, opnd2);
	break;
default:
	cout << "Error" << endl;
	throw std::invalid_argument("Unknown Operator!");
}
	return result; // 返回计算结果
}

float evaluate(char *S, char *&RPN)
{
	Stack<float> opnd;
	Stack<char> optr;
	optr.push('\0');
	while (!optr.empty())
	{
		if (isdigit(*S))
		{
			readNumber(S, opnd);
			ap(RPN, opnd.top());
		}
		else
			switch (orderBetween(optr.top(), *S))
		{
		case '<':
			optr.push(*S);
			S++;
			break;
		case '=':
			optr.pop();
			S++;
			break;
		case '>':
{
	char op = optr.pop();
	ap(RPN, op);
	if (op == '!')
	{
		float pOpnd = opnd.pop();
		opnd.push(calculate(op, pOpnd));
	}
	else
	{
		float pOpnd2 = opnd.pop(), pOpnd1 = opnd.pop();
		opnd.push(calculate(pOpnd1, op, pOpnd2));
	}
	break;
}
		default:
		throw std::invalid_argument("Unknown Operator!");
		}
	}
	return opnd.pop();
}

int main()
{
	bool again = true; 
	while(again) { 
		cout << "请输入需要计算的式子" << endl;
		char S[30];
		char *RPN = new char[30];
		cin >> S;
		cout << S<< "=" << evaluate(S, RPN) << endl;
		cout << "若需要再次计算输入1，若不需要输入0" << endl;
		cin >> again;
		delete[] RPN; // 释放内存
	}
	return 0;
}
