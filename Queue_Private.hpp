#pragma once
#include "Queue_Base.hpp"

class Queue_private : private Queue_Base
{
public:
    void calculatedValue();
    Queue_private* copy();
    void setTail(Node *arg);
    void setHead(Node *arg);
    Node *getHead(void);
    Node *getTail(void);
};
