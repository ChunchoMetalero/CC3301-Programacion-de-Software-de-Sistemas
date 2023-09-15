#include <stdio.h>

#include "suma.h"

typedef unsigned long long Bcd;

Bcd sumaBcd(Bcd x, Bcd y) {

  Bcd c = 0;
  Bcd d = 0;
  int carry = 0;
  unsigned m = -1;
  int mask = ~(m<<4);

  for(int i = 0; i < 16; i++) {
    c = (x & mask) + (y & mask) + carry;

    if (c>9) {
      carry = 1;
      c -= 10;
    }
    else {
      carry = 0;
    }

    x >>= 4;
    y >>= 4;  
    c <<= (i<<2);
    d |= c;
    
    if (i==15 && carry==1) {
      d = 0xffffffffffffffff;
      break;
    }
  }
  return d;
}
