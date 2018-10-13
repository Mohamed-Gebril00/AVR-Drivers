#ifndef MACROS_H
#define MACROS_H

#define SET_BIT(port,bit_num) port|=(1<<(bit_num))
#define CLEAR_BIT(port,bit_num) port&=~(1<<(bit_num))
#define TOGGLE_BIT(port,bit_num) port^=(1<<(bit_num))
#define GET_BIT(port,bit_num) ((port >> bit_num) & 1 )
#define SET_PORT(port) port|=0xFF
#define CLEAR_PORT(port) port=0x00
#define TOGGLE_PORT(port) port^=0xFF

#endif
