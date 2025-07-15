#include "Serializer.hpp"
#include <iostream>

int main() {
    Data d;
    d.value = 123;
    d.flag  = 'X';

    // 1) serialize the pointer
    uintptr_t raw = Serializer::serialize(&d);
    std::cout << "Serialized value: " << raw << '\n';

    // 2) deserialize back
    Data* ptr = Serializer::deserialize(raw);
    std::cout << "Deserialized pointer: " << ptr << '\n';

    // 3) verify correctness
    if (ptr == &d)
        std::cout << "Success: pointers match!\n";
    else
        std::cout << "Error: pointers do not match.\n";

    // Optionally print the data to show it's intact
    std::cout << "Data.value = " << ptr->value
              << ", Data.flag = '" << ptr->flag << "'\n";

    return 0;
}
