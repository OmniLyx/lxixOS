int boot(void) {
    char *fb = (char *) 0x000B8000;
    fb[0] = 'A';
    fb[1] = 0x28;
    return 0;
}