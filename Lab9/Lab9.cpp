#include <iostream>
#include <string>
using namespace std;

int inputLen();					//введення граничної довжини слова
string inputStr();				//введення рядка
string strChange(string, int);	//визначення слів, коротших за k

int main()
{
	int k = inputLen();					//гранична довжина слів
	string str = inputStr();			//заданий рядок
	string rez = strChange(str, k);		//слова, що задовольняють умову
	cout << "Changed string: " << rez << endl;
	system("pause");
}

//введення граничної довжини слова
int inputLen()
{
	int k;
	cout << "Enter the limit length: ";
	cin >> k;
	return k;
}

//введення рядка
string inputStr()
{
	string str;
	cin.ignore(32767, '\n'); //ігнорування символа кінця рядку, що перешкоджає введенню нового рядка
	cout << "Enter the string: ";
	getline(cin, str);
	return str;
}

//визначення слів, коротших за k
string strChange(string str, int k)
{
	char sep = ' ';				//символ, що розділяє слова
	int pos = str.find(sep);	//визначення позиції розділення слів
	string rez, w;				//рядки для результату та окремого слова
	while (pos != string::npos) //поки можна знайти пробіл в рядку
	{
		w = str.substr(0, pos); //виділення слова в окремий рядок
		if (w.length() < k)
			rez += w + ' ';		//конкатенація слова, коротшого за k, до рядка результату
		str.erase(0, pos + 1);	//видалення з даного рядка слова та пробілу
		pos = str.find(sep);	//визначення позиції розділення слів
	}
	if (str.length() < k)		//врахування останнього слова, яке не обмежене пробілом
		rez += str;
	return rez;
}