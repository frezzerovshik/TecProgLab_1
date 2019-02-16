#include "Queue.h"
#define  NULL 0
Queue::Queue()
{
    this->End = new Node;//Выделяем память под первый узел
    this->End->Num = 1;
}
Queue::~Queue()//Деструктор по умолчанию используем для особождения памяти, выделенной под каждый элемент очереди
{
    Node *tmp = this->End->Previous;
    do
    {
        delete this->End;
        this->End = tmp;
        tmp = tmp->Previous;
        
    }while (tmp->Num>0);
    //Удаляем первый элемент очереди
    tmp = nullptr;
}
void  Queue::init(int InitialValue) //Инициализация очереди данными с клавиатуры
{
    this->End->Previous = NULL;
    this->End->Value = InitialValue;
}
void  Queue::add(int UserValue)//Добавление нового элемента в конец очереди
{
    Node* tmp = new Node ;
    tmp->Previous = this->End;
    tmp->Value = UserValue;
    tmp->Num = (this->End->Num) + 1;
    this->End = tmp;
}
void  Queue::del(int Index)//Удаление элемента очереди
{
    Node *Current = this->End->Previous;
    Node *PrevToCurr = this->End;
    if (PrevToCurr->Num == Index)//Если самый последний элемент - подходящий, то удаляем его
    {
        delete this->End;
        this->End = Current;
    }
    else//Иначе - ищем нужный номер и удаляем
    {
        do
        {
            if (Current->Num == Index)
            {
                PrevToCurr->Previous = Current->Previous;//У следующего за удаленным меняем указатель на предыдущий
                delete Current;
                Current = nullptr;
                break;
            }
            else
            {
                Current = Current->Previous;//Двигаемся по очереди
            }
        } while (Current != NULL);
    }
    Current = this->End;
    while(Current->Num!=Index-1)//Пока не дошли до предыдущего для удаленного элемента, уменьшаем номер в очереди на 1
    {
        Current->Num-=1;
        Current = Current->Previous;
    }
    this->Num--;//Уменьшаем счетчик элементов очереди на 1
}

