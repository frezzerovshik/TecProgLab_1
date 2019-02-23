#pragma once
#include "Data.h"
class Queue_Base
{
    Node *Head;//Указатель на голову очереди
    Node *Tail;//Указатель на хвост очереди
    int Num;//Суммарное количество элементов в очереди
public:
    /*Комментарии по назначению методов даны в файле Queue_Base.cpp*/
    Queue_Base();
    ~Queue_Base();
    void pop();
    void push(int UserValue);
    void print();
    int getNum();
    Node *getHead();
    Node *getTail();
    void copy(Queue_Base &op1);
    void setTail(Node *arg);
    void setHead(Node *arg);
};
