/*
file name : shark_calculater
created : 2020.12.31
author : spenshark
*/

#include<iostream>
using namespace std;

int main(){
	int a, b;
	char op;
	
	while(1){
		cout << "\n" << "두 정수와 연산자를 입력하세요" << endl;
		cin >> a >> op >> b;
	
		switch(op){
		case '+':
			cout << a << op << b << '=' << a + b << endl;
			break;
		case '-':
			cout << a << op << b << '=' << a - b << endl;
			break;
		case '*':
			cout << a << op << b << '=' << a * b << endl;
			break;
		case '/':
			if(b==0){
				cout << "0으로 나눌 수는 없습니다." << endl;
				break;
			}
			cout << a << op << b << '=' << a * 1.0 / b << endl;
			break;
		default:
			cout << "잘못된 연산자입니다." << endl;
		}
	}
	return 0;
}