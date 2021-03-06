/*
  Font.h - 7x5 Font for a ST7565 based 12864 LCD.
  Created by Thomas Baum, th.baum@online.de, 14.06.2014
*/
#define CHARACTER_WIDTH 6
#define MAX_CHARACTERS_X 22
#define MAX_CHARACTERS_Y 8

const PROGMEM byte font7x5[] = {
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char NULL
  0x3E, 0x55, 0x51, 0x55, 0x3E, 0x00,  // Code for char 
  0x3E, 0x6B, 0x6F, 0x6B, 0x3E, 0x00,  // Code for char 
  0x0E, 0x1F, 0x3E, 0x1F, 0x0E, 0x00,  // Code for char 
  0x08, 0x1C, 0x3E, 0x1C, 0x08, 0x00,  // Code for char 
  0x98, 0x9B, 0xFF, 0x9B, 0x98, 0x00,  // Code for char 
  0x18, 0x5E, 0x7F, 0x5E, 0x18, 0x00,  // Code for char 
  0x00, 0x08, 0x1C, 0x08, 0x00, 0x00,  // Code for char 
  0x7F, 0x77, 0x63, 0x77, 0x7F, 0x00,  // Code for char 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char 	
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char 
  0x30, 0x48, 0x48, 0x3E, 0x07, 0x00,  // Code for char 
  0x06, 0x29, 0x79, 0x29, 0x06, 0x00,  // Code for char 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char 
  0x60, 0x7E, 0x06, 0x33, 0x3F, 0x00,  // Code for char 
  0x49, 0x3E, 0x63, 0x3E, 0x49, 0x00,  // Code for char 
  0x08, 0x08, 0x7F, 0x08, 0x08, 0x00,  // Code for char 
  0x08, 0x1C, 0x3E, 0x7F, 0x00, 0x00,  // Code for char 
  0x14, 0x22, 0x7F, 0x22, 0x14, 0x00,  // Code for char 
  0x00, 0x5F, 0x00, 0x5F, 0x00, 0x00,  // Code for char 
  0x06, 0x0F, 0x7F, 0x00, 0x7F, 0x00,  // Code for char 
  0x08, 0x08, 0x0F, 0x08, 0x08, 0x00,  // Code for char 
  0x08, 0x08, 0x78, 0x08, 0x08, 0x00,  // Code for char 
  0x00, 0x08, 0x08, 0x7F, 0x00, 0x00,  // Code for char 
  0x04, 0x02, 0x7F, 0x02, 0x04, 0x00,  // Code for char 
  0x00, 0x7F, 0x08, 0x08, 0x00, 0x00,  // Code for char 
  0x08, 0x08, 0x2A, 0x1C, 0x08, 0x00,  // Code for char 
  0x08, 0x1C, 0x2A, 0x08, 0x08, 0x00,  // Code for char 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char  
  0x00, 0x00, 0x5F, 0x00, 0x00, 0x00,  // Code for char !
  0x00, 0x03, 0x00, 0x03, 0x00, 0x00,  // Code for char "
  0x74, 0x1C, 0x77, 0x1C, 0x17, 0x00,  // Code for char #
  0x24, 0x4A, 0xFF, 0x52, 0x24, 0x00,  // Code for char $
  0x43, 0x33, 0x08, 0x66, 0x61, 0x00,  // Code for char %
  0x36, 0x49, 0x55, 0x22, 0x50, 0x00,  // Code for char &
  0x00, 0x00, 0x03, 0x00, 0x00, 0x00,  // Code for char '
  0x00, 0x00, 0x3E, 0x41, 0x00, 0x00,  // Code for char (
  0x00, 0x00, 0x41, 0x3E, 0x00, 0x00,  // Code for char )
  0x00, 0x0A, 0x04, 0x0A, 0x00, 0x00,  // Code for char *
  0x00, 0x08, 0x1C, 0x08, 0x00, 0x00,  // Code for char +
  0x00, 0x00, 0xA0, 0x60, 0x00, 0x00,  // Code for char ,
  0x00, 0x08, 0x08, 0x08, 0x00, 0x00,  // Code for char -
  0x00, 0x00, 0x60, 0x60, 0x00, 0x00,  // Code for char .
  0x00, 0x60, 0x1C, 0x03, 0x00, 0x00,  // Code for char /
  0x3E, 0x41, 0x41, 0x41, 0x3E, 0x00,  // Code for char 0
  0x00, 0x42, 0x7F, 0x40, 0x00, 0x00,  // Code for char 1
  0x42, 0x61, 0x51, 0x49, 0x46, 0x00,  // Code for char 2
  0x22, 0x41, 0x49, 0x49, 0x36, 0x00,  // Code for char 3
  0x1C, 0x13, 0x10, 0x78, 0x10, 0x00,  // Code for char 4
  0x4F, 0x49, 0x49, 0x49, 0x31, 0x00,  // Code for char 5
  0x3E, 0x49, 0x49, 0x49, 0x32, 0x00,  // Code for char 6
  0x01, 0x01, 0x71, 0x09, 0x07, 0x00,  // Code for char 7
  0x36, 0x49, 0x49, 0x49, 0x36, 0x00,  // Code for char 8
  0x26, 0x49, 0x49, 0x49, 0x3E, 0x00,  // Code for char 9
  0x00, 0x00, 0x6C, 0x6C, 0x00, 0x00,  // Code for char :
  0x00, 0x00, 0xAC, 0x6C, 0x00, 0x00,  // Code for char ;
  0x00, 0x08, 0x14, 0x22, 0x00, 0x00,  // Code for char <
  0x00, 0x14, 0x14, 0x14, 0x00, 0x00,  // Code for char =
  0x00, 0x22, 0x14, 0x08, 0x00, 0x00,  // Code for char >
  0x02, 0x01, 0x51, 0x09, 0x06, 0x00,  // Code for char ?
  0x3E, 0x5D, 0x5D, 0x51, 0x5E, 0x00,  // Code for char @
  0x7E, 0x09, 0x09, 0x09, 0x7E, 0x00,  // Code for char A
  0x7F, 0x49, 0x49, 0x49, 0x36, 0x00,  // Code for char B
  0x3E, 0x41, 0x41, 0x41, 0x22, 0x00,  // Code for char C
  0x7F, 0x41, 0x41, 0x22, 0x1C, 0x00,  // Code for char D
  0x7F, 0x49, 0x49, 0x49, 0x41, 0x00,  // Code for char E
  0x7F, 0x09, 0x09, 0x09, 0x01, 0x00,  // Code for char F
  0x3E, 0x41, 0x41, 0x51, 0x32, 0x00,  // Code for char G
  0x7F, 0x08, 0x08, 0x08, 0x7F, 0x00,  // Code for char H
  0x00, 0x00, 0x7F, 0x00, 0x00, 0x00,  // Code for char I
  0x00, 0x20, 0x40, 0x3F, 0x00, 0x00,  // Code for char J
  0x7F, 0x08, 0x14, 0x22, 0x41, 0x00,  // Code for char K
  0x7F, 0x40, 0x40, 0x40, 0x40, 0x00,  // Code for char L
  0x7F, 0x02, 0x0C, 0x02, 0x7F, 0x00,  // Code for char M
  0x7F, 0x04, 0x08, 0x10, 0x7F, 0x00,  // Code for char N
  0x3E, 0x41, 0x41, 0x41, 0x3E, 0x00,  // Code for char O
  0x7F, 0x09, 0x09, 0x09, 0x06, 0x00,  // Code for char P
  0x3E, 0x41, 0x41, 0x21, 0x5E, 0x00,  // Code for char Q
  0x7F, 0x09, 0x09, 0x09, 0x76, 0x00,  // Code for char R
  0x26, 0x49, 0x49, 0x49, 0x32, 0x00,  // Code for char S
  0x01, 0x01, 0x7F, 0x01, 0x01, 0x00,  // Code for char T
  0x3F, 0x40, 0x40, 0x40, 0x3F, 0x00,  // Code for char U
  0x03, 0x1C, 0x60, 0x1C, 0x03, 0x00,  // Code for char V
  0x1F, 0x60, 0x18, 0x60, 0x1F, 0x00,  // Code for char W
  0x63, 0x14, 0x08, 0x14, 0x63, 0x00,  // Code for char X
  0x03, 0x04, 0x78, 0x04, 0x03, 0x00,  // Code for char Y
  0x61, 0x51, 0x49, 0x45, 0x43, 0x00,  // Code for char Z
  0x00, 0x00, 0x7F, 0x41, 0x41, 0x00,  // Code for char [
  0x00, 0x03, 0x1C, 0x60, 0x00, 0x00,  // Code for char BackSlash
  0x00, 0x41, 0x41, 0x7F, 0x00, 0x00,  // Code for char ]
  0x00, 0x06, 0x01, 0x06, 0x00, 0x00,  // Code for char ^
  0x40, 0x40, 0x40, 0x40, 0x40, 0x00,  // Code for char _
  0x00, 0x00, 0x01, 0x02, 0x00, 0x00,  // Code for char `
  0x38, 0x44, 0x44, 0x44, 0x7C, 0x00,  // Code for char a
  0x7F, 0x44, 0x44, 0x44, 0x38, 0x00,  // Code for char b
  0x38, 0x44, 0x44, 0x44, 0x28, 0x00,  // Code for char c
  0x38, 0x44, 0x44, 0x44, 0x7F, 0x00,  // Code for char d
  0x38, 0x54, 0x54, 0x54, 0x58, 0x00,  // Code for char e
  0x00, 0x04, 0x7E, 0x05, 0x00, 0x00,  // Code for char f
  0x18, 0xA4, 0xA4, 0xA4, 0x7C, 0x00,  // Code for char g
  0x7F, 0x04, 0x04, 0x04, 0x78, 0x00,  // Code for char h
  0x00, 0x00, 0x7D, 0x00, 0x00, 0x00,  // Code for char i
  0x00, 0x40, 0x3D, 0x00, 0x00, 0x00,  // Code for char j
  0x7F, 0x20, 0x10, 0x28, 0x44, 0x00,  // Code for char k
  0x00, 0x00, 0x3F, 0x40, 0x00, 0x00,  // Code for char l
  0x78, 0x04, 0x78, 0x04, 0x78, 0x00,  // Code for char m
  0x04, 0x78, 0x04, 0x04, 0x78, 0x00,  // Code for char n
  0x38, 0x44, 0x44, 0x44, 0x38, 0x00,  // Code for char o
  0xF8, 0x44, 0x44, 0x44, 0x38, 0x00,  // Code for char p
  0x38, 0x44, 0x44, 0x44, 0xF8, 0x00,  // Code for char q
  0x00, 0x7C, 0x08, 0x04, 0x04, 0x00,  // Code for char r
  0x48, 0x54, 0x54, 0x54, 0x24, 0x00,  // Code for char s
  0x00, 0x04, 0x3F, 0x44, 0x00, 0x00,  // Code for char t
  0x3C, 0x40, 0x40, 0x40, 0x7C, 0x00,  // Code for char u
  0x0C, 0x30, 0x40, 0x30, 0x0C, 0x00,  // Code for char v
  0x1C, 0x60, 0x1C, 0x60, 0x1C, 0x00,  // Code for char w
  0x44, 0x28, 0x10, 0x28, 0x44, 0x00,  // Code for char x
  0x44, 0x48, 0x30, 0x08, 0x04, 0x00,  // Code for char y
  0x44, 0x64, 0x54, 0x4C, 0x44, 0x00,  // Code for char z
  0x00, 0x08, 0x36, 0x41, 0x00, 0x00,  // Code for char {
  0x00, 0x00, 0x7F, 0x00, 0x00, 0x00,  // Code for char |
  0x00, 0x41, 0x36, 0x08, 0x00, 0x00,  // Code for char }
  0x08, 0x04, 0x08, 0x08, 0x04, 0x00,  // Code for char ~
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char 
  0x14, 0x3E, 0x55, 0x55, 0x41, 0x00,  // Code for char ???
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char ??
  0x00, 0x00, 0xA0, 0x60, 0x00, 0x00,  // Code for char ???
  0x00, 0x84, 0x7E, 0x05, 0x01, 0x00,  // Code for char ??
  0xA0, 0x60, 0x00, 0xA0, 0x60, 0x00,  // Code for char ???
  0x40, 0x00, 0x40, 0x00, 0x40, 0x00,  // Code for char ???
  0x04, 0x04, 0xFF, 0x04, 0x04, 0x00,  // Code for char ???
  0x24, 0x24, 0xFF, 0x24, 0x24, 0x00,  // Code for char ???
  0x00, 0x02, 0x01, 0x02, 0x00, 0x00,  // Code for char ??
  0x63, 0x13, 0x6C, 0x63, 0x60, 0x60,  // Code for char ???
  0x48, 0x55, 0x56, 0x55, 0x24, 0x00,  // Code for char ??
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char ???
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char ??
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char ??
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char ??
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char ??
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char ??
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char ???
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char ???
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char ???
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char ???
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char ???
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char ???
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char ???
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char ??
  0x01, 0x07, 0x01, 0x07, 0x03, 0x07,  // Code for char ???
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char ??
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char ???
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char ??
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char ??
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char ??
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char ??
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char  
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char ??
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char ??
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char ??
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char ??
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char ??
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char ??
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char ??
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char ??
  0x7E, 0x81, 0xBD, 0xA5, 0x81, 0x7E,  // Code for char ??
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char ??
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char ??
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char ??
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char ??
  0x7E, 0x81, 0xBD, 0x9D, 0xA1, 0x7E,  // Code for char ??
  0x01, 0x01, 0x01, 0x01, 0x01, 0x00,  // Code for char ??
  0x00, 0x02, 0x05, 0x02, 0x00, 0x00,  // Code for char ??
  0x00, 0x48, 0x5C, 0x48, 0x00, 0x00,  // Code for char ??
  0x00, 0x09, 0x0D, 0x0A, 0x00, 0x00,  // Code for char ??
  0x00, 0x09, 0x0D, 0x0F, 0x00, 0x00,  // Code for char ??
  0x00, 0x00, 0x02, 0x01, 0x00, 0x00,  // Code for char ??
  0xFC, 0x40, 0x40, 0x40, 0x3C, 0x00,  // Code for char ??
  0x06, 0x0F, 0xFF, 0x01, 0xFF, 0x01,  // Code for char ??
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char ??
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char ??
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char ??
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char ??
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char ??
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char ??
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char ??
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char ??
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char ??
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char ??
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char ??
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char ??
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char ??
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char ??
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char ??
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char ??
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char ??
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char ??
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char ??
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char ??
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char ??
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char ??
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char ??
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char ??
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char ??
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char ??
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char ??
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char ??
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char ??
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char ??
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char ??
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char ??
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char ??
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char ??
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char ??
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char ??
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char ??
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char ??
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char ??
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char ??
  0xFE, 0x49, 0x49, 0x56, 0x20, 0x00,  // Code for char ??
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char ??
  0xFE, 0x49, 0x49, 0x56, 0x20, 0x00,  // Code for char ??
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char ??
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char ??
  0x38, 0x45, 0x44, 0x45, 0x7C, 0x00,  // Code for char ??
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char ??
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char ??
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char ??
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char ??
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char ??
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char ??
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char ??
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char ??
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char ??
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char ??
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char ??
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char ??
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char ??
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char ??
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char ??
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char ??
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char ??
  0x30, 0x4A, 0x48, 0x4A, 0x30, 0x00,  // Code for char ??
  0x08, 0x08, 0x2A, 0x08, 0x08, 0x00,  // Code for char ??
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char ??
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char ??
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char ??
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char ??
  0x38, 0x42, 0x40, 0x42, 0x78, 0x00,  // Code for char ??
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char ??
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char ??
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char ??
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00   // Code for char 
};
