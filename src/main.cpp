#include <iostream>
#include <fstream>
#include <iterator>

#include <types.hpp>

int Ptr;

Vector<Byte> Tape(30000, 0);
Vector<char> Inst = {};
String Raw;

int Execute(Vector<char>& Code) {
    for (auto& C : Code) {
        if (C == '<') { if (Ptr > 0) Ptr--; }
        else if (C == '>') Ptr++;
        else if (C == '+') Tape[Ptr]++;
        else if (C == '-') Tape[Ptr]--;
        else if (C == '.') std::cout << static_cast<char>(Tape[Ptr]) << "\n";
        else if (C == ',') std::cout << "TODO\n";
    }
    return 0;
}

int main(int argc, char** argv) {
    std::ifstream File(argv[1]);
    Raw = String((
        std::istreambuf_iterator<char>(File)), 
        std::istreambuf_iterator<char>()
    );
    Inst.assign(Raw.begin(), Raw.end());
    Execute(Inst);
}
