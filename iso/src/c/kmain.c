#include <display.h>

void Boot(void) {
    ClearScreen(0x00);
    FrameBufferWriteCell(0, 'H', 0x0F);
}
