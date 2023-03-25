#include <iostream>

using Data = int64_t;

struct ListItem {
    Data data;
    ListItem *prev, *next;
};

struct List {
    List();
    ListItem *head=nullptr, * tail=nullptr;
    List(const List& rhs);
    List& operator=(const List& rhs);
    List(List&& rhs);
    List& operator=(List&& rhs);
    void PushBack (Data d);
    void PushFront(Data d);
    void PopBack();
    void PopFront();
    Data Front();
    Data Back();
    Data Size();
    ~List();
    Data size;


};