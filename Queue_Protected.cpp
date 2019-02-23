#include "Queue_Protected.hpp"
#include <iostream>
using namespace std;
Node* Queue_protected:: getHead(void){return Queue_Base::getHead();}
Node* Queue_protected:: getTail(void){return Queue_Base::getTail();}
int Queue_protected::getNum(void){return Queue_Base::getNum();}
void Queue_protected::calculatedValue()
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

Queue_protected* Queue_protected::copy()
{
    Queue_protected copy;
    Queue_protected *ptr;
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
void Queue_protected::setHead(Node *arg)
{
    Queue_Base::setHead(arg);
}
void Queue_protected::setTail(Node *arg)
{
    Queue_Base::setTail(arg);
}

