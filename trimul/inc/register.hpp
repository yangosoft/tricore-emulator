
#pragma once 
#include <type_traits>

namespace trimul
{
    // 
    template <class T,class = typename std::enable_if_t<std::is_unsigned<T>::value>>
    class Register
    {
    public:
        Register() : value(0){};
        Register(T t) : value(t){};
        T get() { return value; };
        void set(T t) { value = t; };

       /*  // copy assignment
        T& operator=(const T& other)
        {
            // Guard self assignment
            if (this == &other)
            {
                return *this;
            }

            value = other.value; 
            return *this;
        } */

    private:
        T value;
    };
}