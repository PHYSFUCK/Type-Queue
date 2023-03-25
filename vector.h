#include <cstdint>
#include<iostream>


using u64 = uint64_t;
using i64 = int64_t;


class Vector{
    public:
        Vector() {
            size_ = 0; data_ = nullptr; reserved_ = 0;
            ReallocAtLeast_(def_min_size);
        }
        Vector(u64 initial_size){
            size_ = 0; data_ = nullptr; reserved_ = 0;
            ReallocAtLeast_(initial_size);

            for (u64 i = 0; i < initial_size; ++i) {
                data_[i] = 0;
            }
            size_ = initial_size;

        }
        ~Vector() {
            delete[] data_;
        }

        Vector(const Vector& rhs) {
            //std:: cout << "Copy " << '\n';
            size_ = rhs.size_;
            reserved_ = rhs.reserved_;
            data_ = new i64[rhs.size_];
            for (i64 i = 0; i < size_; ++i) {
                data_[i] = rhs.data_[i]; // v.data[i]
            }
        }

        Vector& operator=(const Vector& rhs) {
            if (&rhs == this) {
                return *this;
            }
            Vector tmp(rhs);
            std::swap(tmp.size_, size_);
            std::swap(tmp.data_, data_);
            std::swap(tmp.reserved_, reserved_);
            return *this;
        }

        Vector(Vector&& rhs) noexcept{
            std::cout << "Move" << '\n';
            data_ = nullptr;
            std::swap(data_, rhs.data_);
            std::swap(size_, rhs.size_);
            std::swap(rhs.reserved_, reserved_);

        }

        Vector& operator=(Vector&& rhs) noexcept {
            if (&rhs == this) {
                return *this;

            }
            Vector tmp(std::move(rhs));
            std::swap(tmp.data_, data_);
            std::swap(tmp.size_, size_);
            std::swap(tmp.reserved_, reserved_);
            return *this;
        }
        
        
    
        i64& operator[] (u64 index) {
            return data_[index];
        }

        void PushBack(i64 element){
            //std::cerr << "PB [" << element << "], r="<<reserved_ << ", s=" <<size_ <<"\n";
            if (size_ >= reserved_ ) {
                ReallocAtLeast_(2 * reserved_);
            }
            data_[size_] = element;
            ++size_;
            // std::cerr 
        }

        i64& PopBack() {
            //std:: cout  << "pop " << data_[size_ - 1] << '\n';
            --size_;
            //std:: cout<< "pop " << data_[size_ - 1] << '\n';
            return data_[size_];
        }
        u64 Size() const {
            return size_;
        }
    protected:
    private:
        void ReallocAtLeast_(u64 n){
            //std::cerr << "ReallocAtLeast_" << n << '\n';
            if (reserved_ >= n) {
                return;

            }
            i64 * new_data = new i64[n];
            for (u64 i =0; i < size_; ++i) {
                new_data[i] = data_[i];
            }
            delete[] data_;
            data_ = new_data;
            reserved_ = n;
        }

        const u64 def_min_size = 2;
        i64 *data_;
        u64 size_, reserved_;


};