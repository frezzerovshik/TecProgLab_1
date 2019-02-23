#pragma once
#include "Queue_Base.hpp"
class Queue_protected : protected Queue_Base
{
public:
    void calculatedValue();
    Queue_protected* copy();
    Node *getHead(void);
    Node *getTail(void);
    int getNum(void);
    void setTail(Node *arg);
    void setHead(Node *arg);
};
