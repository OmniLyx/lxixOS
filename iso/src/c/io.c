#include "io.h"

#define FB_COMMAND_PORT     0x3D4
#define FB_DATA_PORT        0x3D5

/* The I/O port commands */
#define FB_HIGH_BYTE_COMMAND    14  // 14 tells the framebuffer to expect the highest 8 bits of the position
#define FB_LOW_BYTE_COMMAND     15  // 15 tells the framebuffer to expect the lowest 8 bits of the position

/** FrameBufferMoveCursor:
 *  Moves the cursor of the framebuffer to the given position
 *
 *  @param pos The new position of the cursor
 */
void FrameBufferMoveCursor(unsigned short pos)
{
    OutB(FB_COMMAND_PORT, FB_HIGH_BYTE_COMMAND);
    OutB(FB_DATA_PORT,    ((pos >> 8) & 0x00FF));
    OutB(FB_COMMAND_PORT, FB_LOW_BYTE_COMMAND);
    OutB(FB_DATA_PORT,    pos & 0x00FF);
}