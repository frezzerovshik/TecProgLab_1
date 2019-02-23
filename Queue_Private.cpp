#include "Queue_Private.hpp"
#include <iostream>
using namespace std;
Node* Queue_private:: getHead(void){return Queue_Base::getHead();}
Node* Queue_private:: getTail(void){return Queue_Base::getTail();}
void Queue_private::calculatedValue()
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
Queue_private* Queue_private::copy()
{
    Queue_private copy;
    Queue_private *ptr;
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
void Queue_private::setHead(Node *arg)
{
    Queue_Base::setHead(arg);
}
void Queue_private::setTail(Node *arg)
{
    Queue_Base::setTail(arg);
}
