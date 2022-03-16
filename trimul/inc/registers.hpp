
#pragma once 
#include "register.hpp"

#include <array>
#include <cstdint>

namespace trimul
{
    struct Registers
    {
        std::array< Register<std::uint32_t>, 16> reg_a;
        std::array< Register<std::uint32_t>, 16> reg_d;
        Register<std::uint32_t> reg_pc;

        Register<std::uint32_t> reg_cr1;
        Register<std::uint32_t> reg_cr2;

    };
    
} // namespace trimul


