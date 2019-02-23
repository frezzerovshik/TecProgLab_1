#include <iostream>
#include "Queue_Base.hpp"
#include "Queue_Public.hpp"
#include "Queue_Private.hpp"
#include "Queue_Protected.hpp"
#include "Functions.hpp"
#include <Curses.h>
using namespace std;

int main(int argc, const char * argv[])
{
    Queue_Base q1;
    Queue_Base copy;
    Queue_Base merge;
    Queue_public q_publ;
    Queue_protected q_prot;
    Queue_private q_priv;
    int UserValue = 0;
    char Switcher;
    bool Exit = false;
    char ModeSwitch;
    do
    {
        cout<<"1 - Добавление элемента очереди"<<endl;
        cout<<"2 - Извлечение элемента очереди"<<endl;
        cout<<"3 - Печать очереди на экран"<<endl;
        cout<<"4 - Вычисление среднего арифметического четных элементов очереди"<<endl;
        cout<<"5 - Создание копии очереди"<<endl;
        cout<<"6 - Слияние оригинальной очереди с копией и вывод результата на экран"<<endl;
        cout<<"7 - Выход из программы"<<endl;
        cin>>Switcher;
    switch (Switcher)
        {
        case '1':
                system("clear");
                cout<<"Введите значение элемента очереди"<<endl;
                cin>>UserValue;
                q1.push(UserValue);
            break;
        case '2':
                system("clear");
                q1.pop();
                cout<<"Извлечение элемента очереди произошло успешно"<<endl;
            break;
        case '3':
                system("clear");
                q1.print();
            break;
        case '4':
                system("clear");
                cout<<"Выберите, объект с каким модификатором наследования хотите работать"<<endl;
                cout<<"1 - public"<<endl;
                cout<<"2 - protected"<<endl;
                cout<<"3 - private"<<endl;
                cin>>ModeSwitch;
                switch (ModeSwitch)
            {
                case '1':
                    q_publ.setTail(q1.getTail());
                    q_publ.setHead(q1.getHead());
                    q_publ.calculatedValue();
                        break;
                case '2':
                    q_prot.setTail(q1.getTail());
                    q_prot.setHead(q1.getHead());
                    q_prot.calculatedValue();
                    break;
                case '3':
                    q_priv.setTail(q1.getTail());
                    q_priv.setHead(q1.getHead());
                    q_priv.calculatedValue();
                    break;
                    default:
                        break;
            }
            break;
        case '5':
                system("clear");
                q1.copy(copy);
                cout<<"Создание копии очереди прошло успешно"<<endl;
            break;
        case '6':
                 system("clear");
                cout<<"Слияние двух очередей"<<endl;
                cout<<"Если Вы не создавали копию очереди ранее, результат работы этой функции непредсказуем"<<endl;
                mergeQueues(q1, copy, merge);
                Exit = false;
                continue;
        case '7':
                Exit = true;
                break;
         default:
                cout<<"Такой команды нет, попробуйте выбрать команду еще раз!"<<endl;
                system("clear");
                break;
    }
    }while(Exit == false);
    cout<<"До новых встреч"<<endl;
    return 0;
}
