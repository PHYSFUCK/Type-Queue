#include "llist.h"
#include <iostream>

//using i64 = int64_t

List::List(){
    size = 0;
}

List::List(const List& rhs) {
    head = new ListItem;
    tail = new ListItem;
    head = rhs.head;
    tail = rhs.tail;
    size = rhs.size;
    
}

List& List::operator=(const List& rhs){
    if(this == &rhs) {
        return *this;
    }
    List tmp(rhs);
    std::swap(tmp.size, size);
    std::swap(tmp.head, head);
    std::swap(tmp.tail, tail);
    return *this;
}

List::List(List&& rhs) {
    head = nullptr;
    tail = nullptr;
    std::swap(rhs.size, size);
    std::swap(rhs.head, head);
    std::swap(rhs.tail, tail);

}

List& List::operator=(List&& rhs){
    List tmp(std::move(rhs));
    std::swap(tmp.size, size);
    std::swap(tmp.head, head);
    std::swap(tmp.tail, tail);

}

void List::PushBack (Data d) {
    //std::cout << "start " << d << '\n';
    //Create new element
    ListItem * itm = new ListItem;
    itm->data = d;
    //std::cout << "itm " << head << '\n';
    itm->next = nullptr;
    ++size;
    if ((head == nullptr) && (tail == nullptr)) {
        itm->prev = nullptr;
        head = itm;
        tail = itm;
        //std::cout << "tail " << tail->data << '\n';
        return;
    }

    //Link it to tail
    tail->next = itm;
    itm->prev = tail;

    //Update tail
    tail = itm;
    //std::cout << "tail " << tail->data << '\n';


}

void List:: PushFront(Data d) {
    ListItem * itm = new ListItem;
    itm->data = d;
    itm->prev = nullptr;
    ++size;
    if ((head == nullptr) && (tail == nullptr)) {
        itm->prev = nullptr;
        head = itm;
        tail = itm;
        return;
    }
    
    head->prev = itm;
    itm->next = head;

    head = itm;

}

void List :: PopBack() {
    if (tail == nullptr) {
        std :: cout << "Error: PopFront() from empty list\n" << std::flush;
        return;
    }

    --size;

    if (tail->prev == nullptr) {
        delete tail;
        head = nullptr;
        tail = nullptr;
        return;
    }

    tail = tail->prev;
    delete tail->next;
    tail->next = nullptr;  


}

void List::PopFront() {
    if (head == nullptr) {
        std:: cout << "Error: PopFront() from empty list\n" << std::flush;
        return;
    }

    --size;

    if (head->next == nullptr) {
        delete head;
        head = nullptr;
        tail = nullptr;
        return;
    }
    //Unlink from head->next
    head = head->next;
    delete head->prev;
    head->prev = nullptr;



    //Delete old head
    //Reassign head
}

List::~List() {
    if (head == nullptr) return; 
    ListItem *cur = head;
    while ( cur != nullptr) {
        head = cur->next;
        delete cur;
        cur = head;
    };

}

Data List::Size(){
    return size;
}

Data List::Front(){
    if (head == nullptr){
        std :: cout << "Error: Front() from empty list\n" << std::flush;
        return -1;
    }
    return head->data;
    
}
Data List::Back(){
    if (tail == nullptr){
        std :: cout << "Error: Back() from empty list\n" << std::flush;
        return -1;
    }
    return tail->data;
    
}
    

