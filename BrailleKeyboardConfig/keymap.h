#include <stdlib.h>

int getUsageId(int comb) {
    switch(comb) {
        case 0b000001: return 0x04;
        case 0b000101: return 0x05;
        case 0b000011: return 0x06;
        case 0b001011: return 0x07;
        case 0b001001: return 0x08;
        case 0b000111: return 0x09;
        case 0b001111: return 0x0A;
        case 0b001101: return 0x0B;
        case 0b000110: return 0x0C;
        case 0b001110: return 0x0D;
        case 0b010001: return 0x0E;
        case 0b010101: return 0x0F;
        case 0b010011: return 0x10;
        case 0b011011: return 0x11;
        case 0b011001: return 0x12;
        case 0b010111: return 0x13;
        case 0b011111: return 0x14;
        case 0b011101: return 0x15;
        case 0b010110: return 0x16;
        case 0b011110: return 0x17;
        case 0b110001: return 0x18;
        case 0b110101: return 0x19;
        case 0b101110: return 0x1A;
        case 0b110011: return 0x1B;
        case 0b111011: return 0x1C;
        case 0b111001: return 0x1D;
        case 0b101010: return 0x2A;
        case 0b111111: return 0x2C;
        case 0b101100: return 0x37;
        case 0b000100: return 0x36;
        default: return 0;
    }
}