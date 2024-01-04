// usuage: (420^666) mod 777

module;

#include <cstdlib>
export module modenv;



[[nodiscard]] constexpr u_int64_t modmul(u_int64_t value,u_int64_t md){
    while(value>=md)
        value-=md;

    value*=value;
    while(value>=md) value-=md;
    return value;
}
export namespace bignum {

    [[nodiscard]] constexpr u_int64_t exp_mod(u_int64_t base, u_int64_t power, u_int64_t md) noexcept {
        u_int64_t val=base;
        bool isFirst=false;
        for(u_int64_t i=63;~i;i--){

            val= modmul(val,md);
           if((1<<i) &power && isFirst){
                val=modmul(val,md);
           }
           isFirst=true;
        }
        return val;
    }
};



