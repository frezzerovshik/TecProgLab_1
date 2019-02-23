#include "Functions.hpp"
#include <iostream>

using namespace std;

void mergeQueues(Queue_Base &q1 , Queue_Base &q2 , Queue_Base &result)//Функция слияния очередей
{
    int values_op1[q1.getNum()];//Для хранения значений первой очереди
    int values_op2[q2.getNum()];//Для хранения значений второй очереди
    Node *tmp_op1 = q1.getTail();//Указатель для прохода по первой очереди
    Node *tmp_op2 = q2.getTail();//Указатель для прохода по второй очереди
    int q1_k = (q1.getNum()) - 1;//Индексация массива значений первой очереди
    int q2_k = (q2.getNum()) - 1;//Индексация массива значений второй очереди
    while (tmp_op1!=q1.getHead() && tmp_op2!=q2.getHead())//Идем до начала обеих очередей(т.к. слияние происходит с копией, то их длины одинаковы)
    {
        values_op1[q1_k--] = tmp_op1->Value;
        values_op2[q2_k--] = tmp_op2->Value;
        tmp_op1 = tmp_op1->Previous;
        tmp_op2 = tmp_op2->Previous;
    }
    //"Проталкиваем" в новую очередь значения первой и второй очередей
    for (int i = 0;i<q1.getNum();++i)
    {
        result.push(values_op1[i]);
    }
    for (int i = 0;i<q2.getNum();++i)
    {
        result.push(values_op2[i]);
    }
    result.print();
}

