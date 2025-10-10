#include <iostream>
#include <fstream>
#include <iterator>

#ifdef _WIN32
    #include <conio.h>
#else
    #include <termios.h>
    #include <unistd.h>

    char getch() {
        char buf = 0;
        struct termios old = {0};
        tcgetattr(STDIN_FILENO, &old);
        struct termios newt = old;
        newt.c_lflag &= ~(ICANON | ECHO);
        tcsetattr(STDIN_FILENO, TCSANOW, &newt);
        read(STDIN_FILENO, &buf, 1);
        tcsetattr(STDIN_FILENO, TCSANOW, &old);
        return buf;
    }
#endif

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
        else if (C == ',') Tape[Ptr] = getch();
    }
    return 0;
}

int main(int argc, char** argv) {
    if (argc < 2) { std::cout << "\x1b[93mUsage\x1b[0m: <binary> <file.bf>\n"; return 1; }
    std::ifstream File(argv[1]);
    if (!File) { std::cout << "idk something happend\n"; return 1; }

    Raw = String((
        std::istreambuf_iterator<char>(File)), 
        std::istreambuf_iterator<char>()
    );

    Inst.assign(Raw.begin(), Raw.end());
    Execute(Inst);
}
