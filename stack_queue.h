#include"vector.h"
#include<cstdint>
#include<iostream>

using u64 = uint64_t;
using i64 = int64_t;

class StackQueue {
    public:
        StackQueue(){
            size_ = 0;  
        }

        void PushBack(i64 element){
            tail_.PushBack(element);
            ++size_;
            //std::cout<< "tail size " <<tail_.Size()<<" "<< tail_[tail_.Size()-1]<<'\n';
            //std:: cout << "head size " << head_.Size() <<'\n';
        }
        i64 PopFront(){
            if (head_.Size() == 0) {
                for (i64 i = tail_.Size() - 1; i >= 0 ; --i) {
                    //std:: cerr << "i: "<< i << '\n';
                    //std:: cerr << "tail -> head " << tail_[i] << '\n';
                    head_.PushBack(tail_[i]);
                    tail_.PopBack();
                }
            }
            --size_;
            return head_.PopBack();

        }

        i64 Front() {
            //std:: cerr << "test size " << size_ << '\n';
            if (size_ == 0) {
                std :: cout << "Error: Front() from empty queue\n" << std::flush;
                return -1;
            }
            if (head_.Size() != 0) {
                return head_[head_.Size() - 1];
            } else {
                return tail_[0];
            }
        }

        u64 Size() {
            return size_;
        }
    private:
        Vector head_{};
        Vector tail_{};
        u64 size_;


};