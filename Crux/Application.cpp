
#include "CruxGraphicsModule.h"

int main() {
    CruxGraphicsModule gfx;

    try {
        gfx.CruxRun();
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}