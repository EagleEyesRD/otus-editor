#include"Editor.h"

int main(int argc, char **argv) {
    try {
        auto editor = new Editor();
        if (editor != nullptr && argc > 1) {
            editor->Open(argv[1]);
            editor->Modify("something write here");
            editor->Save(argv[2]);
        }
    }
    catch (std::exception ex) { std::cout << "error on main:" + std::string(ex.what()) << std::endl; }
    return 0;
}