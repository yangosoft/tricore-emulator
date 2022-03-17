#include "memory.hpp"
#include "register.hpp"
#include "registers.hpp"

#include <cstdint>
#include <iostream>




int main(int argc, char* argv[])
{
	std::cout << "TEST" << std::endl;

	trimul::Register<std::uint8_t> r8{16};
	trimul::Registers regs;

	regs.reg_a[2].set(15);
	trimul::Memory<2*1024*1024> mem;


	return 0;
}
