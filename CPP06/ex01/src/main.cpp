#include "Serializer.hpp"

int main() {
	Data data = {42, "<GM_Express>", 10.05f};
	Data* ptr = &data;

	std::cout << "Original Data: " << ptr->id << ", " << ptr->name << ", "  << ptr->c << std::endl;
	std::cout << "Address of data: " << &data << std::endl;
	std::cout << "Address of data.id: " << &data.id << std::endl;
	std::cout << "Address of data.name: " << &data.name << std::endl;
	std::cout << "Address of data.float: " << &data.c << std::endl;

	uintptr_t raw = Serializer::serialize(&data);
	std::cout << "Serialized value: " << raw << std::endl;

	Data* restored = Serializer::deserialize(raw);
	std::cout << "Restored Data: id = " << restored->id << ", name = " << restored->name << ", float = " << restored->c <<  std::endl;

	std::cout << "Restored Address of Restored: " << &restored << std::endl;
	std::cout << "Restored Address of data: " << restored << std::endl;
	std::cout << "Restored Address of Restored.id: " << &restored->id << std::endl;
	std::cout << "Restored Address of Restored.name: " << &restored->name << std::endl;
	std::cout << "Restored Address of Restored.float: " << &restored->c << std::endl;

	if (&data == restored) {
		std::cout << "Serialization and deserialization succeeded!" << std::endl;
	} else {
		std::cout << "Error: pointers do not match!" << std::endl;
	}

	return 0;
}
