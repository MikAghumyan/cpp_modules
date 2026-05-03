#include "Serializer.hpp"
#include <iostream>

int main(void)
{
	Data data = {42};

	std::cout << "Original pointer : " << &data << "\n";

	uintptr_t raw = Serializer::serialize(&data);
    std::cout << "Serialized value : " << raw << "\n";

	Data *back = Serializer::deserialize(raw);
	std::cout << "Restored pointer : " << back << "\n";

	std::cout << "Pointers match : " << ((&data == back) ? "yes" : "no") << "\n";
	std::cout << "Value through ptr: " << back->value << "\n";

	return (0);
}