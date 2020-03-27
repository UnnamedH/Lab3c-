// Lab3C++.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;
#pragma warning(disable : 4996);
void ScanText(char **Matrix,int *k,int *j) {
    int plus = 0, minus = 0, ymnog = 0;
    for (int i = 0; i < *k; i++) {//инициализация двумерного массива
        Matrix[i] = new char[*j];
    }
    cout << "Введите символы:";
    for (int i = 0; i < *k; i++) {//ввод
        for (int n = 0; n < *j; n++) {
            cin >> Matrix[i][n];
        }
    }

    for (int i = 0; i < *k; i++) {
        for (int n = 0; n < *j; n++) {
            switch(Matrix[i][n]) {
                case '+':{
                    plus++;
                    break;
                }
                case '-': {
                    minus++;
                    break;
                }
                case '*': {
                    ymnog++;
                    break;
                }
                default: {
                    break;
                }

            }

        }
    }
    cout << "\nЗнаков минуса: " <<minus<<"\nЗнаков плюса: "<<plus<< "\nЗнаков умножить: "<<ymnog;

}


void ChangeSimb(string str) {
    for (string::size_type i = 0; i < str.size(); ++i) {
        if (str[i] == ' ') {
            str.insert(i, ",");
            i++;
        }
    }
    cout << str << endl;
}

void ChangePerem(string simbols[5]) {
    int ravno, plus,one;
    for (int i = 0; i < 5;i++) {
            ravno = simbols[i].find('=');
             plus = simbols[i].find('+');
             one = simbols[i].find('1');
             cout << "till :" <<simbols[i] << endl;
             if ((ravno > 0) && (plus > 0) && (one > 0)) {
                 if ((simbols[i][ravno - 1] == simbols[i][plus - 1]) && (plus == ravno + 2) && (one == plus + 1)) {
                      char s1 = simbols[i][ravno - 1];
                      string s2 = "++";
                      
                     simbols[i].replace(ravno-1, one,s1+s2);
                 }
             }
            cout <<"after:"<< simbols[i] << endl;
    }
    

    
}

int main()
{
  /* setlocale(LC_ALL,"");
   //базовый
    int k = 2;
    int j = 6;
    
    char** Matrix = new char* [k];
    ScanText(Matrix,&k,&j);
    //средний
    string str = "I study in Politech";

    cout << str << endl;
    ChangeSimb(str);
    //высокий*/
    string simbols[5]={ {"qweaefaf*a=a+1"} ,{"qweaa=a+1efafh*"},{"asavsb=b+1effh"},{"iyiyc=c+1wefw"},{"vlb;bo;h'lpfew"} };

    ChangePerem(simbols);
}


