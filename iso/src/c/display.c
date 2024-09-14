#include <display.h>

char *fb = (char *) 0x000B8000;

void FrameBufferWriteCell(unsigned int i, char c, unsigned char fg, unsigned char bg)
{
    fb[i] = c;
    fb[i + 1] = ((fg & 0x0F) << 4) | (bg & 0x0F);
}

void FrameBufferWrite(char str, unsigned char fg, unsigned char bg)
{
    FrameBufferWriteCell(0, str, fg, bg);
    // while (str[i] != '\0')
    // {
    //     FrameBufferWriteCell(i * 2, str[i], fg, bg);
    //     i++;
    // }
}

void ClearScreen(unsigned char bg)
{
    for (int i = 0; i < 80 * 25; i++)
    {
        fb[i * 2] = ' ';
        fb[i * 2 + 1] = bg;
    }
}