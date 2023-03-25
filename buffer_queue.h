#include<cstdint>
#include<iostream>

using i64 = int64_t;
using u64 = uint64_t;

class BuffQueue{
    public:
        BuffQueue(){
            size_ = 0; reserved_ = 0; head_ = 0; tail_ = 0; data_ = nullptr;
            ReallocAtLeast_(def_min_size_);
            //std::cout << "tail " << tail_ <<'\n';
            //std::cout << "size " << size_ <<'\n';
            //std:: cout << "Initialized " << '\n';
        };

        ~BuffQueue(){
            delete[] data_;
        }

        BuffQueue(const BuffQueue& rhs) {
            std::cerr << "Copy" <<'\n';
            size_ = rhs.size_;
            reserved_ = rhs.reserved_;
            head_ = rhs.head_;
            tail_ = rhs.tail_;
            data_ = new i64[rhs.size_];
            for (i64 i=0; i < rhs.size_; ++i) {
                data_[i] = rhs.data_[i];
            }
            std::cerr<<data_[0]<<'\n';
        }

        BuffQueue& operator= (const BuffQueue& rhs){
            if (this == &rhs) {
                return *this;
            }
            BuffQueue tmp(rhs);
            std::swap(tmp.size_, size_);
            std::swap(tmp.data_, data_);
            std::swap(tmp.reserved_, reserved_);
            std::swap(tmp.head_, head_);
            std::swap(tmp.tail_, tail_);
            return *this;
        }

        BuffQueue(BuffQueue&& rhs) noexcept{
            data_ = nullptr;
            std::swap(data_, rhs.data_);
            std::swap(size_, rhs.size_);
            std::swap(rhs.reserved_, reserved_);
            std::swap(rhs.head_, head_);
            std::swap(rhs.tail_, tail_);
        }

        BuffQueue& operator=(BuffQueue&& rhs) noexcept{
            if (this == &rhs) {
                return *this;
            }
            BuffQueue tmp(std::move(rhs));
            std::swap(tmp.data_, data_);
            std::swap(tmp.size_, size_);
            std::swap(tmp.reserved_, reserved_);
            std::swap(tmp.head_, head_);
            std::swap(tmp.tail_, tail_);

            return *this;
        }

        i64 PopFront(){
            if (size_ == 0){
                std :: cout << "Error: Front() from empty queue\n" << std::flush;
                return -1;
            }
            i64 pop = data_[head_];
            head_ = (head_ + 1) % reserved_;
            --size_;
            return pop;
        };
        void PushBack(i64 element){
            //std::cout << "PushBack " <<element << '\n';
            //std::cout << "tail " << tail_ <<'\n';
            //std::cout << "data " << data_ << "\n";
            //*(data_+tail_ * sizeof(i64)) = 1;
            //std::cout<<"Data " << data_[tail_] << '\n';
            data_[tail_] = element;
            //std::cerr<<"Data " << data_[tail_] << '\n';
            //std::cerr<<"Start " << tail_ << '\n';

            tail_ = (tail_ + 1) % reserved_;
            //std::cerr<<"Start " << tail_ << '\n';
            ++size_; 
            if (tail_ == head_){
                ReallocAtLeast_(2 * reserved_);
            }
            //std::cout << "tail " << tail_ <<'\n';
            //std:: cout << "head " << head_ << '\n';
        }
        i64 Front(){
            if (size_ == 0){
                std :: cout << "Error: Front() from empty queue\n" << std::flush;
                return -1;
            }
            return data_[head_];
        };

        u64 Size() {
            return size_;
        }

    private:
        void ReallocAtLeast_(u64 n){
            //std::cerr << "ReallocAtLeast_" << n << '\n';
            if (reserved_ >= n) {
                return;

            }
            
            i64 * new_data = new i64[n];
            for (u64 i = 0; i < size_; ++i) {
                new_data[i] = data_[(head_ + i) % reserved_];
            }
            
            delete[] data_;
            data_ = new_data;

            head_ = 0;
            reserved_ = n;
            tail_ = size_;
            //tail_  = (tail_ + 1) % n;
            
        }

        u64 size_, reserved_;
        const i64 def_min_size_ = 2;
        i64 head_, tail_;
        i64 * data_;



};