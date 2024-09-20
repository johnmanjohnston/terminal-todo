typedef struct {
    int r;
    int g;
    int b;
} color;

void set_text_color(color c);
void fill_with_color(color c);
color hex_c(int col);
color rgb_c(unsigned int r, unsigned int g, unsigned int b);

void ansi_reset();

// theme
color background_c();
color foreground_c();
color red_c();
color green_c();
color blue_c();
color yellow_c();
