#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <Windows.h>
#include <cstdlib>

using namespace std;

void WelcomeMes();
int CheckStr(string &uInput, int &len_a);
int CheckOp(string &uInput, int &operand);
vector <int> GetNumber(vector <int>& a, vector <int>& b, string &uInput, int &len_a);
int Trans(char element);
void Addition(vector <int>& a, vector <int>& b, vector <int>& result);
int CheckLength(vector <int>& a, vector <int>& b);
void Subtraction(vector <int>& a, vector <int>& b, vector <int>& result);
void Multiplication(vector <int>& a, vector <int>& b, vector <int>& result);
void Division(vector <int>& a, vector <int>& b, vector <int>& result);
void Power(vector <int>& a, vector <int>& b, vector <int>& result, string& uInput, int& len_a);
void ShowResult(vector <int>& a, vector <int>& b, vector <int>& result);

void WelcomeMes() {
	cout << "WelcomeMessage>>>" << endl;
	cout << "Вам доступны действия:" << endl;
	cout << "1. Сумма двух чисел (+) >>>" << endl;
	cout << "2. Разность двух чисел (-) >>>" << endl;
	cout << "3. Произведение двух чисел (*) >>>" << endl;
	cout << "4. Частное двух чисел (/) (Разрабатывается) >>>" << endl;
	cout << "5. Возведение числа в степень (%) >>>" << endl;
	cout << "0. Выйти (!) >>>" << endl;
	cout << "Пример ввода: 48495562145464+7864595413543513" << endl;
	cout << ">>>" << endl;
}

int CheckStr(string& uInput, int& len_a) {
	//Проверка строки на посторонние символы
	int counter = 0;
	len_a = 0;
	for (int i = 0; i < uInput.length(); i++) {
		if (uInput[i] == '0' || uInput[i] == '1' || uInput[i] == '2' || uInput[i] == '3' || uInput[i] == '4' || uInput[i] == '5' || uInput[i] == '6' || uInput[i] == '7' || uInput[i] == '8' || uInput[i] == '9') { 
			if (counter == 0) len_a++; }
		else counter++;
	}
	if (counter > 1 || counter == 0)
		return true;
	if (counter == 1) {
		if (uInput[len_a] == '+' || uInput[len_a] == '-' || uInput[len_a] == '*' || uInput[len_a] == '/' || uInput[len_a] == '%' || uInput[len_a] == '!')
		return false;
		else return true;
	}
}

int CheckOp(string &uInput, int &operand){
	//Поиск знака операции
	operand = 0;
	for (int i = 0; i < uInput.length(); i++) {
			if (uInput[i] == '+') return operand = '+';
			else if (uInput[i] == '-') return operand = '-';
			else if (uInput[i] == '*') return operand = '*';
			else if (uInput[i] == '/') return operand = '/';
			else if (uInput[i] == '%') return operand = '%';
			else if (uInput[i] == '!') return operand = '!';
	}
}

vector <int> GetNumber(vector <int>& a, vector <int>& b, string &uInput, int &len_a) {
	//Запись строки в два вектора
	for (int i = 0; i < len_a; i++) {
		a.push_back(Trans(uInput[i]));
	}
	for (int i = len_a + 1; i < uInput.length(); i++) {
		b.push_back(Trans(uInput[i]));
	}
	return a, b;
}

int Trans(char element) {
	//Перевод элемента вектора из чара в инт
	if (element == '0')
		return 0;
	else if (element == '1')
		return 1;
	else if (element == '2')
		return 2;
	else if (element == '3')
		return 3;
	else if (element == '4')
		return 4;
	else if (element == '5')
		return 5;
	else if (element == '6')
		return 6;
	else if (element == '7')
		return 7;
	else if (element == '8')
		return 8;
	else if (element == '9')
		return 9;
}

void Addition(vector <int>& a, vector <int>& b, vector <int>& result) {
	//Функция сложения двух длинных чисел
	//Работает только с положительными числами
	int flag = 0;

	if (a.size() > b.size()) {
		for (int i = a.size() - b.size(); i > 0; i--) {
			b.insert(b.begin(), 0);
		}
	}
	else if (b.size() > a.size()) {
		for (int i = b.size() - a.size(); i > 0; i--) {
			a.insert(a.begin(), 0);
		}
	}

	for (int i = a.size() - 1; i >= 0; i--) {
		result.insert(result.begin(), (a[i] + b[i] + flag) % 10);

		if (i == 0 && a[i] + b[i] + flag > 9)
			result.insert(result.begin(), 1);

		if ((a[i] +b[i] + flag) > 9)
			flag = 1;
		else
			flag = 0;
	}
}

int CheckLength(vector <int>& a, vector <int>& b) {
	//Проверка длины для функции вычитания
	if (a.size() > b.size())
		return 1;
	else if (b.size() > a.size())
		return 0;

	for (int i = 0; i < a.size(); i++) {
		if (a[i] > b[i])
			return 1;
		else if (b[i] > a[i])
			return 0;
	}
}

void Subtraction(vector <int>& a, vector <int>& b, vector <int>& result) {
	//Функция вычитания двух длинных чисел
	//Работает только с положительными числами
	//Может дать отрицательный ответ
	int flag = 0;
	auto begin = result.cbegin();

	if (a.size() > b.size()) {
		for (int i = a.size() - b.size(); i > 0; i--) {
			b.insert(b.begin(), 0);
		}
	}
	else if (b.size() > a.size()) {
		for (int i = b.size() - a.size(); i > 0; i--) {
			a.insert(a.begin(), 0);
		}
	}

	if (CheckLength(a, b)) {
		for (int i = a.size() - 1; i >= 0; i--) {
			if (a[i] < b[i]) {
				result.insert(result.begin(), (a[i] + 10) - b[i]);
				int j = i;
				while (j > 0) {
					if (a[j - 1] > 0) {
						a[j - 1] = a[j - 1] - 1;
						flag++;
						if (flag == 2)
							a[j - 1] += 1;
						break;
					}
					else {
						a[j - 1] = -1;
						j--;
					}
				}
			}
			else {
				result.insert(result.begin(), a[i] - b[i]);
			}
			if (b[i] < 0 && i == 0) {
				result[i] = 0;
			}
		}
		for (int i = 0; i < result.size(); i++) {
			if (result[i] < 0) {
				result[i] = 0;
			}
		}
	}
	else {
		for (int i = a.size() - 1; i >= 0; i--) {
			if (b[i] < a[i]) {
				result.insert(result.begin(), (b[i] + 10) - a[i]);
				int j = i;
				while (j > 0) {
					if (b[j - 1] != 0) {
						b[j - 1] = b[j - 1] - 1;
						flag++;
						if (flag == 2)
							b[j - 1] += 1;
						break;
					}
					else {
						b[j - 1] = -1;
						j--;
					}
				}
			}
			else {
				result.insert(result.begin(), b[i] - a[i]);
			}
			if (b[i] < 0 && i == 0) {
				result[i] = 0;
			}
		}
		cout << "-";
	}
}

void Multiplication(vector <int>& a, vector <int>& b, vector <int>& result) {
	//Функция умножения длинного числа на длинное число
	//Работает только с положительными числами
	int flag = 0;
	int counter = 0;

	vector <int> cur;
	vector <int> carry;
	vector <int> carry_result;

	while (b.empty() == false) {

		int def = 0;
		for (int i = a.size() - 1; i >= 0; i--) {
			cur.insert(cur.begin(), (a[i] * b.back() + def) % 10);

			if (i == 0 && a[i] * b.back() + def > 9)
				cur.insert(cur.begin(), (a[i] * b.back() + def) / 10);

			if ((a[i] * b.back() + def) > 9)
				def = (a[i] * b.back() + def) / 10;
			else
				def = 0;
		}
		
		if (counter > 0)
			for (int i = counter; i >= 1; i--) {
				cur.push_back(0);
			}

		for (int i = cur.size() - carry.size(); i > 0; i--) {
			carry.insert(carry.begin(), 0);
		}

		for (int i = carry.size() - 1; i >= 0; i--) {
			carry_result.insert(carry_result.begin(), (carry[i] + cur[i] + flag) % 10);

			if (i == 0 && carry[i] + cur[i] + flag > 9)
				carry_result.insert(carry_result.begin(), 1);

			if ((carry[i] + cur[i] + flag) > 9)
				flag = 1;
			else
				flag = 0;
		}
		carry.assign(carry_result.begin(), carry_result.end());
		carry_result.clear();
		counter++;
		cur.clear();
		b.pop_back();		
	}
	result.swap(carry);
}

void Division(vector <int>& a, vector <int>& b, vector <int>& result) {
	//Деление двух длинных чисел
	//Баги, баги, баги
	vector <int> a_div;
	vector <int> b_div;
	vector <int> result_div;
	vector <int> carry;
	vector <int> balance_div;
	int a_size = a.size();
	int b_size = b.size();
	int counter = 0;
	int flag;
	
	if (a_size >= b_size) {
		a_div.assign(a.begin(), a.end());
		b_div.assign(b.begin(), b.end());
		while (a_div.size() >= b_div.size()){
		do {
			a.assign(b_div.begin(), b_div.end());
			b.clear();
			carry.clear();
			b.insert(b.begin(), 9 - counter);
			carry.insert(carry.begin(), 9 - counter);
			Multiplication(a, b, result);
			counter++;
			flag = 0;
			if (a_div[0] >= result[0]) {
				for (int i = 0; i <= result.size() - 1; i++) {
					if (a_div[i] <= result[i])  flag++;
				}
			}
			else flag = 1;
		} while (flag > 0);
		
		result_div.push_back(carry.front());
		a.assign(a_div.begin(), a_div.end());
		b.assign(result.begin(), result.end());
		result.clear();
		while(a.size()> b.size()) b.push_back(0);
		Subtraction(a, b, result);
		int zero = 0;
		for (int i = 0; i < result.size(); i++) {
			if (result[i] == 0) zero++;
		}
		if (result.size() >= 1 && zero > 0) result.erase(result.begin(), result.begin() + zero - 1);
		a_div.assign(result.begin(), result.end());
		result.clear();
		}
		result.swap(a_div);
	}
	result.swap(result_div);
	result_div.clear();
}

void Power(vector <int>& a, vector <int>& b, vector <int>& result, string& uInput, int& len_a) {
	//Возведение в степень
	//Поддерживает только положительную степень
	for (int i = 0; i < len_a; i++) {
		a.push_back(Trans(uInput[i]));
	}
	int counter = 0;
	int n = 0;

	for (int i = uInput.length() - 1; i >= len_a + 1; i--) {

		if (counter > 0) {
			n = n + Trans(uInput[i]) * pow(10, counter);
		}
		else n += Trans(uInput[i]);
		counter++;
	}
	if (n >= 1) {
		while (n > 1) {
			for (int i = 0; i < len_a; i++) {
				b.push_back(Trans(uInput[i]));
			}
			Multiplication(a, b, result);
			a.swap(result);
			result.clear();
			n--;
		}
		result.swap(a);
		a.clear();
	}
	if (n == 0) {
		result = { 1 };
	}
}

void ShowResult(vector <int>& a, vector <int>& b, vector <int>& result) {
	//Вывод результата с учётом удаления ведущих нулей
	 int counter = 0;
	 for (int i = 0; i < result.size(); i++) {
		 if (result[i] == 0) counter++; else break;
	 }
	 if (result.size() >= 1 && counter > 0) result.erase(result.begin(), result.begin() + counter - 1);
	 for (int i = 0; i < result.size(); i++) {
		cout << result[i];
	 }
	cout << "" << endl;
	cout << ">>>" << endl;
	a.clear();
	b.clear();
	result.clear();
}

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	vector <int> a;
	vector <int> b;
	vector <int> result;
	string uInput;
	int operand = 0;
	int len_a = 0;
		do{
			WelcomeMes();
			do {
				cout << "Введите числа и действие, или ! для выхода." << endl;
				cout << ">>>";
				cin >> uInput;
				if (CheckStr(uInput, len_a)) {
					system("cls");
					cout << "Сделайте ввод корректно, используя пример." << endl;
					cout << ">>>";
					system("pause");
				}
				system("cls");
			} while (CheckStr(uInput, len_a));
			CheckOp(uInput, operand);
		switch (operand){
		case '+':
			GetNumber(a, b, uInput, len_a);
			Addition(a, b, result);
			ShowResult(a, b, result);
			break;
		case '-':
			GetNumber(a, b, uInput, len_a);
			Subtraction(a, b, result);
			ShowResult(a, b, result);
			break;
		case '*':
			GetNumber(a, b, uInput, len_a);
			Multiplication(a, b, result);
			ShowResult(a, b, result);
			break;
		case '/': 
			GetNumber(a, b, uInput, len_a);
			Division(a, b, result);
			ShowResult(a, b, result);
			break;
		case '%': 
			Power(a, b, result, uInput, len_a);
			ShowResult(a, b, result);
			break;
		}
		} while (operand != '!');

		system("pause");
	return 0;
}
