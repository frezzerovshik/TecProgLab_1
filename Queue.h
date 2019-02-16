#pragma once
/*
 Тип данных, описывающий узел
 Целочисленное значение
 Номер в очереди
 Указатель на предыдущего стоящего в очереди
 */
typedef struct Node
{
    int Value;
    int Num;
    Node *Previous;
} Node;
/*
 Класс, реализующий очередь
 рrivate -  указатель на последний элемент в очереди, число элементов в очереди
 public - конструктор, деструктор, инициализация, добавление и удаление из очереди
 */
class Queue
{
    Node *End;
    int   Num;
public:
    Queue();
    ~Queue();
    void init(int InitialValue);
    void add(int UserValue);
    void del(int Index);
};


