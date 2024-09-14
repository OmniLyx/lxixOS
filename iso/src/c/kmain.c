#include "display.h"
#include "serial.h"


void Boot(void) {
    char buff[5] = "Hello";
    ClearScreen(0x00);
    FrameBufferWriteCell(0, 'H', 0x0F);
    FrameBufferWrite(buff, 5);
    SerialConfigureBaudRate(0x3F8, 1);
    SerialConfigureLine(0x3F8);
    SerialWrite(0x3F8, buff);
}
