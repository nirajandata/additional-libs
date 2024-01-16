module;
#include <string_view>
#include <vector>
#include <iostream>
#include <ranges>
#include <algorithm>
#include <complex>
export module modmain;

import :helper;

export namespace bignum{
    class LargeNum{
    public:
        std::vector<int> value;
        explicit LargeNum(std::string_view num){
           value.resize(num.size());
           size_t i=0;
           for(auto &n:num){
               value[i]=static_cast<int>(n)-48;
               i++;
           }
       }

        [[maybe_unused]] explicit LargeNum(std::vector<int> &&temp){
            value=std::move(temp);
        }
        void flatten(){
            //didn't use this due to some ABI compatibility
       //     std::ranges::reverse_view rvv{value};
           std::reverse(value.begin(),value.end());
            size_t carry=0;
            for(auto &t: value){
                t+=carry;
                carry=0;
                if(t>9){
                    carry=t/10;
                    t%=10;
                }
            }
            // when we have empty carry left
            if(carry!=0){
                value.push_back(carry);
            }
            std::reverse(value.begin(),value.end());
        }
        void operator+=(LargeNum& secondValue){
            if(this->size()<secondValue.size()){
                std::swap(value,secondValue.value);
            }
            for(size_t i=0;i<secondValue.size();i++){
                value[i]+=secondValue.value[i];
            }
            this->flatten();

        }
      [[nodiscard]] auto operator* (LargeNum& secondValue){
            //fft pointvalue multiplication. use any fft with return_val::resize(sum_of_both_vector-1);
           LargeNum temp(multiply(value,secondValue.value));
           temp.flatten();
           return temp;
       }

        friend std::ostream& operator<<(std::ostream& os, const LargeNum& num) {
            std::ranges::reverse_view rv{num.value};
            for (auto& t : num.value) {
                os << t ;
            }

            return os;
        }
         size_t size(){
           return value.size();
       }
    };
}
