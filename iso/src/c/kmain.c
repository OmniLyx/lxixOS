#include "display.h"


void Boot(void) {
    char buff[5] = "Hello";
    ClearScreen(0x00);
    FrameBufferWriteCell(0, 'H', 0x0F);
    Write(buff, 5);
}
