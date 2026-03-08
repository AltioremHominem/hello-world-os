#include <stddef.h>

enum vga_color {
	VGA_COLOR_BLACK = 0,
	VGA_COLOR_BLUE = 1,
	VGA_COLOR_GREEN = 2,
	VGA_COLOR_CYAN = 3,
	VGA_COLOR_RED = 4,
	VGA_COLOR_MAGENTA = 5,
	VGA_COLOR_BROWN = 6,
	VGA_COLOR_LIGHT_GREY = 7,
	VGA_COLOR_DARK_GREY = 8,
	VGA_COLOR_LIGHT_BLUE = 9,
	VGA_COLOR_LIGHT_GREEN = 10,
	VGA_COLOR_LIGHT_CYAN = 11,
	VGA_COLOR_LIGHT_RED = 12,
	VGA_COLOR_LIGHT_MAGENTA = 13,
	VGA_COLOR_LIGHT_BROWN = 14,
	VGA_COLOR_WHITE = 15,
};


size_t line = 0;

void kclrscr(){
    char *memory_video = (char *) 0xb8000;

    const int WIDTH = 80;
    const int HEIGHT = 25;

    unsigned int i = 0;

    for (size_t i = 0; i < ( WIDTH * HEIGHT * 2); i++ ){
        memory_video[i] = ' ';
        i++;
        memory_video[i] = VGA_COLOR_WHITE; 
    }
}

void kprint(const char *string){
    char *memory_video = (char *) 0xb8000;
    
    const int WIDTH = 80;
    unsigned long i = 0;

    i = (line * WIDTH * 2);

    while(*string != 0){
        if (*string == '\n'){
            line++;
            i = (line * WIDTH);
            *string++;
        } else {
            memory_video[i] = *string;
            *string++;
            i++;
            memory_video[i] = VGA_COLOR_WHITE;
            i++;
        }
    }
    line++;
}

void kmain(){
    kclrscr();

    kprint("HOLA");

}
