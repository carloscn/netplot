#ifndef COM_H
#define COM_H
/*
* Definition C style:

note: all of uint8 type.

#define         CMD_SET_FREQ            0xA0
#define         CMD_SET_FS              0xA1
#define         CMD_SET_GAIN            0xA2
#define         CMD_HEADER_1            0xAA
#define         CMD_HEADER_2            0xBB
#define         CMD_CLOSE_REMOTE        0xFF


* short cmd format:

note:  all of uint8 type.

| header1 | header2 | length | cmd_type | cmd_high_8 bits | cmd_low_8 bits | checksum |


    for example:

    cmd 8-bits serial:
    "\xAA\xBB\x04\xA0\xFF\xFB\xB1"
    header1  : 0xAA
    header2  : 0xBB
    length   : 0x04
    cmd_type : 0xA0
    cmd_h_8  : 0xFF
    cmd_l_8  : 0xFB
    check_sum: 0xB1

* lengh data block:


network send:

"@@@" + ".....data block....." + "###"

define string s1 = "@@@"; as stream header
define string s2 = "......data block......" area as adc stream datas. length should be set 1024 float datas.
define string s3 = "###"; as stream tail

detail string s2 data block:

you should transform the adc result to float(32bits) data then encode it as BCD code.(IEEE754 Single precision 32-bit)

for example:
    decimal (32.65) -> Binary (010000010 11111011 10011001 10011010) -> BCD Hex (0x42FB999A)

*/

#define         CMD_HEADER_1            0xAA
#define         CMD_HEADER_2            0xBB
#define         CMD_SET_FREQ            0x01
#define         CMD_SET_GAIN            0x03
#define         CMD_ALL_START           0x04
#define         CMD_ALL_STOP            0x08
#define         CMD_CLOSE_REMOTE        0xFF
#define         CMD_SET_FS              0xA1

#endif // COM_H
