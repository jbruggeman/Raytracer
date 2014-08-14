#ifndef COLOR_H
#define COLOR_H

typedef unsigned char uint8_t;

class Color {
    public:
		Color();
		Color(uint8_t r, uint8_t g, uint8_t b);
 
   		uint8_t _r;
   		uint8_t _g;
		uint8_t _b;
};

#endif /* COLOR_H */