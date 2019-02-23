//Реализация методов базового класса очереди
#include "Queue_Base.hpp"
#include <iostream>

using namespace std;

Queue_Base::Queue_Base()//Конструктор используем как функцию инициализации очереди (Обнуляем все значения)
{
    Tail = nullptr;
    Head = nullptr;
    Num = 0;
}
Queue_Base::~Queue_Base()//Деструктор используем для освобождения памяти, выделенной для очереди поэлементно
{
    if(Num!=0)
    {
        Node *tmp;
        for(int i = 0; i<Num;++i)
        {
            tmp = Tail->Previous;
            delete Tail;
            Tail = tmp;
        }
    }
}
void Queue_Base::pop()//Метод извлечения элемента из очереди
{
    Node *tmp;
    tmp = Tail;
    while (tmp->Previous!=Head)
    {
        tmp = tmp->Previous;
    }
    delete Head;
    Head = tmp;
    tmp = Tail;
    do {
        tmp->Num--;
        tmp = tmp->Previous;
    }while(tmp!=Head);
    Num--;
}
void Queue_Base::push(int UserValue)//Метод добавления элементов в очередь
{
    Node *tmp = new Node;//Выделяем память под новый узел
    tmp->Previous = Tail;//Текущий хвост - предыдущий для добавляемого
    tmp->Value = UserValue;//В значение узла кладем значение, введенное пользователем
    tmp->Num = ++Num;//Наращиваем на 1 общее количество элементов в очереди и запоминаем порядковый номер элемента
    if (Num == 0)//Если очередь пуста - мы добавили головной элемент
    {
        Head = tmp;
    }
    else//Иначе - добавляем в конец
    {
    Tail = tmp;
    }
}
void Queue_Base::print()//Вывод очереди на экран
{
    Node *tmp = Tail;
    int tmp_1[Num];//Создаем массив для сохранения пользвательских данных элемента очереди
    int k = Num-1;
    do
    {
        tmp_1[k--] = tmp->Value;
        tmp = tmp->Previous;
    }
    while(tmp!=Head);//Заполняем массив с конца, т.к. в соответсвии с заданием двигаться по очереди мы можем только от хвоста к голове
    for(k = 0; k<Num;++k)
        k==Num-1?cout<<tmp_1[k]:cout<<tmp_1[k]<<"<<";
    cout<<endl;
}
void Queue_Base::copy(Queue_Base &op1)//Метод создания копии очереди, принимает как параметр ссылку на внешний объект, который и будет хранить копию существующей очереди
{
    Node *tmp = Tail;
    int k = Num-1;
    int tmp_1[Num];
    while(tmp!=Head)//Запоминаем данные в правильном порядке
    {
        tmp_1[k--] = tmp->Value;
        tmp = tmp->Previous;
    }
    for(k = 0;k<Num;++k)
    {
        op1.push(tmp_1[k]);//Вызываем метод добавления нужное количество раз,"проталкиваем" в очередь данные
    }
}
/*Методы получения и установки значений private - членов класса*/
void Queue_Base::setTail(Node *arg){Tail = arg;}
void Queue_Base::setHead(Node *arg){Head = arg;}
Node *Queue_Base::getHead(){return Head;}
Node *Queue_Base::getTail(){return Tail;}
int Queue_Base::getNum(){return Num;}
