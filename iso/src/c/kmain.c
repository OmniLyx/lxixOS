#include <display.h>


int Boot(void) {
    ClearScreen(0x00);
    FrameBufferWriteCell(0, 'H', 0x0F, 0x00);
    FrameBufferWriteCell(2, 'e', 0x0F, 0x00);
    FrameBufferWriteCell(4, 'l', 0x0F, 0x00);
    FrameBufferWriteCell(6, 'l', 0x0F, 0x00);
    FrameBufferWriteCell(8, 'o', 0x0F, 0x00);
    return 0;
}
