#include "Queue_Public.hpp"
#include <iostream>
using namespace std;
void Queue_public::calculatedValue()
{
    int Sum = 0;
    int Quantity = 0;
    
    Node *tmp = getTail();
    do
    {
        if((tmp->Num)%2==0)
           {
            Sum+=tmp->Value;
            Quantity++;
        }
         tmp=tmp->Previous;
    }while(tmp!=getHead());
     cout<<"Среднее арифметическое четных элементов очереди: "<< (double)Sum/Quantity<<endl;
}

Queue_public* Queue_public::copy()
{
    Queue_public copy;
    Queue_public *ptr;
    Node *tmp = getTail();
    int k = getNum()-1;
    int tmp_1[getNum()];
    do
    {
        tmp_1[k--] = tmp->Value;
        tmp = tmp->Previous;
    } while(tmp!=getHead());
    for(k = 0;k<getNum();++k)
    {
        copy.push(tmp_1[k]);
    }
    ptr = &copy;
    return ptr;
}
void Queue_public::setHead(Node *arg)
{
    Queue_Base::setHead(arg);
}
void Queue_public::setTail(Node *arg)
{
    Queue_Base::setTail(arg);
}
