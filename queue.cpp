#include"stack_queue.h"
#include"list_queue.h"
#include"buffer_queue.h"
#include<iostream>
#include <chrono>
#include <cmath>


//using Queue = StackQueue;
//using Queue = ListQueue;
using Queue = BuffQueue;

int main() {
    /*
    Queue q;
    q.PushBack(0);
    q.PushBack(0);
    q.PushBack(0);
    q.PushBack(0);
    for 
    for 
    
    Queue q;
    Queue m;

    for (i64 i=0; i < 11; ++i) {
        q.PushBack(i*i);
        m.PushBack(i);
        
    }
    std::cout << "Size "<<q.Size()<<'\n';
    std::cout << "First element " << q.Front() << '\n';
    Queue u(std::move(q));
    //std::cerr << "u" <<'\n';
    Queue k;
    //std::cerr << "k" <<'\n';
    k = std::move(m);
    for (i64 i = 0; i < 11; i++) {
        std::cout << "size u " << u.Size() << '\n';
        u.PopFront();
        //std::cerr << "POP" <<'\n';
        std::cout << "test u " << u.Front() << '\n';
    }
    
    for (i64 i = 0; i < 11; i++) {
        std::cout << "Size k " << k.Size() << '\n';
        k.PopFront();
        std::cout << "test k " << k.Front() << '\n';
    }
    
    
    std::cout << "Size "<<q.Size()<<'\n';
    std::cout << "First element " << q.Front() << '\n';

    
    q.PushBack(200);
    q.PopFront();
    std::cout << "Size "<<q.Size()<<'\n';
    std::cout << "First element " << q.Front() << '\n';
    */
   i64 n;
   std::cin >> n;
   std::chrono::duration<double> avg;
    for (i64 j=0; j < 1; j++){
        Queue q;
        //std::cout << q.Size() << '\n';
        auto start = std::chrono::steady_clock::now();
        for(i64 i=0; i < n; i++) {
            q.PushBack(i);
        }
        std::cout << q.Size() << '\n';
        for(i64 i=0; i < n; i++) {
            //std::cout << q.Front() << '\n';
            q.PopFront();
        }

        auto end = std::chrono::steady_clock::now();
        std::chrono::duration<double> elapsed_seconds = end-start;
        avg += elapsed_seconds;
        std::cout << "elapsed time: " << elapsed_seconds.count() << "s\n";

    

        
    }
    std::cout<< n/pow(10, 6) << " average:" << avg.count()/5;
    
    return 0;
}