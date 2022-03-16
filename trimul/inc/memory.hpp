#pragma once

#include <cstdint>

namespace trimul
{
    constexpr const std::uint32_t base_address = 0x80000000;

    template <std::size_t T>
    class Memory
    {
        public:
            Memory() = default;

            void set(std::uint32_t address, std::uint8_t value);
            void set(std::uint32_t address, std::uint16_t value);
            void set(std::uint32_t address, std::uint32_t value);

            /*template<typename U>
            U get(std::uint32_t address);*/

            void get(std::uint32_t address, std::uint8_t &value);
            void get(std::uint32_t address, std::uint16_t &value);
            void get(std::uint32_t address, std::uint32_t &value);



            


        private:
            std::uint8_t memory[T];
    
    };


}