#pragma once
#include "Queue_Base.hpp"
class Queue_public : public Queue_Base
{
public:
    void calculatedValue();
    void setTail(Node *arg);
    void setHead(Node *arg);
    Queue_public* copy();
};
