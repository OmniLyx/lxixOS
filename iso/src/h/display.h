/** fb_write_cell:
 *  Writes a character with the given foreground and background to position i
 *  in the framebuffer.
 *
 *  @param i  The location in the framebuffer
 *  @param c  The character
 *  @param fg The foreground color
 *  @param bg The background color
 */
void FrameBufferWriteCell(unsigned int i, char c, unsigned char fg, unsigned char bg);


/** fb_write:
 *  Writes a string with the given foreground and background to the framebuffer
 *
 *  @param str The string to write
 *  @param fg  The foreground color
 *  @param bg  The background color
 */
void FrameBufferWrite(char str, unsigned char fg, unsigned char bg);

/** ClearScreen:
 *  Clears the screen with the given background color
 *
 *  @param bg The background color
 */
void ClearScreen(unsigned char bg);