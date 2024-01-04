module;
#include <unordered_map>

export module bignums;


export namespace bignum {
    template<typename T1,typename T2,size_t num=420> requires (num!=0)
    struct Caches{
        void insert(T1&& t1,T2&& t2){
            if(cache.size()>=num){
                cache.erase(cache.begin());
            }
            cache.emplace(std::move(t1),std::move(t2));
        }
        T2 operator[](T1 t1){
            return cache[t1]; //std library handles it when value doesn't exists.
        }
    private:
        size_t count=0;
        std::unordered_map<T1,T2> cache;

    };

};



