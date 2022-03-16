#include "memory.hpp"


using namespace trimul;

template <std::size_t T>
void Memory<T>::set(std::uint32_t address, std::uint8_t value)
{
    if(address < sizeof(memory))
    {
        memory[address] = value;
    }
}
            //void set(std::uint32_t address, std::uint16_t value);
            //void set(std::uint32_t address, std::uint32_t value);

template <std::size_t T>
void Memory<T>::get(std::uint32_t address, std::uint8_t &value)
{
    if(address < sizeof(memory))
    {
        value = memory[address];
    }
}


template <std::size_t T>
void Memory<T>::get(std::uint32_t address, std::uint16_t &value)
{
    if(address+1 < sizeof(memory))
    {
        value = memory[address+1];
        value = 0xFF00 & (value << 8);
        value = value | memory[address];
    }
}

template <std::size_t T>
void Memory<T>::get(std::uint32_t address, std::uint32_t &value)
{
    if(address < sizeof(memory))
    {
        value = memory[address];
    }
}
       

/*template <std::size_t T>
std::uint8_t  Memory<T>::get(std::uint32_t address)
{
    if(address < sizeof(memory))
    {
        return memory[address];
    }

    return 0;
}
template <std::size_t T>
template <typename U>
U Memory<T>::get(std::uint32_t address)
{
    if(address < sizeof(memory))
    {
        return memory[address];
    }
    return 0;
}*/

