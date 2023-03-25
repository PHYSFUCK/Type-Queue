#include"llist.cpp"
#include<cstdint>
#include<iostream>

using u64 = uint64_t;
using i64 = int64_t;

class ListQueue {
    public:
        ListQueue(){
            size_ = 0;  
        }

        void PushBack(i64 element){
            l.PushBack(element);
            ++size_;
            //std::cout<< "tail size " <<tail_.Size()<<" "<< tail_[tail_.Size()-1]<<'\n';
            //std:: cout << "head size " << head_.Size() <<'\n';
        }
        void PopFront(){
            l.PopFront();
            --size_;
            return;

        }

        i64 Front() {
            //std:: cerr << "test size " << size_ << '\n';
            l.Front();
        }

        u64 Size() {
            return size_;
        }
    private:
        List l;
        u64 size_;


};