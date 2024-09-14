#ifndef INCLUDE_DISPLAY_H
#define INCLUDE_DISPLAY_H

/** fb_write_cell:
 *  Writes a character with the given foreground and background to position i
 *  in the framebuffer.
 *
 *  @param i  The location in the framebuffer
 *  @param c  The character
 *  @param color The color
 */
void FrameBufferWriteCell(unsigned int i, char c, unsigned char color);


/** ClearScreen:
 *  Clears the screen with the given background color
 *
 *  @param bg The background color
 */
void ClearScreen(unsigned char bg);

void FrameBufferWrite(char *buf, unsigned int len);

#endif
