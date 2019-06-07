# Questions

## What's `stdint.h`?

stdint.h is a header file in the C standard library to allow programmers to write more portable code by providing a set of typedefs that specify exact-width integer types, together with the defined minimum and maximum allowable values for each type, using macros.

## What's the point of using `uint8_t`, `uint32_t`, `int32_t`, and `uint16_t` in a program?

We cann't store large value int that's why we use these data types

## How many bytes is a `BYTE`, a `DWORD`, a `LONG`, and a `WORD`, respectively?

 BYTE = 1 byte, DWORD = 4 byte, LONG = 4 byte, and WORD = 2 byte

## What (in ASCII, decimal, or hexadecimal) must the first two bytes of any BMP file be? Leading bytes used to identify file formats (with high probability) are generally called "magic numbers."

Hexadecimal = 0x424d
ASCII = BM
The value is store in "bfType"

## What's the difference between `bfSize` and `biSize`?

bfSize is the total number of bytes in the file (246 for smiley.bmp).
biSize is the number of bytes in the info header (40 for a bitmap).

## What does it mean if `biHeight` is negative?

If biHeight is negative, the bitmap is a top-down with the origin at the upper left corner.

## What field in `BITMAPINFOHEADER` specifies the BMP's color depth (i.e., bits per pixel)?

biBitCount

## Why might `fopen` return `NULL` in `copy.c`?

When it can't find the file, it return fopen

## Why is the third argument to `fread` always `1` in our code?

Because we're always reading a complete struct at a time.

## What value does `copy.c` assign to `padding` if `bi.biWidth` is `3`?

The padding would be 3, because 3 pixels * 3 bytes per pixel * 3 padding = 12,
which is a multiple of 4.

## What does `fseek` do?

It skip the padding and move to the specific location

## What is `SEEK_CUR`?

specifies that the offset provided is relative to the current file position.
