#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>
//#include <cstdint>
#include <stdint.h>
#include "Data.h"

class Serializer {
	private:
		Serializer();
		~Serializer();
		Serializer(const Serializer&);
		Serializer& operator=(const Serializer&);

	public:
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};

#endif
