Assignment:
  The provided program accepts a single argument interpreted as an unsigned 64-bit hex number.
  This uint64_t (stdint.h) is then broken up as an 8 element byte array (uint8_t's).
  The order of the bytes in the array is a BigEndian equivalent of the entered uint64_t.
  The array is then displayed in binary form.
  For example, if the number is 0103024050600708, the displayed array contents will be:
    00000001
    00000011
    00000010
    01000000
    01010000
    01100000
    00000111
    00001000
  All ones are to be interpreted as land.
  All zeroes, as well as the area around the array of digits, are to be interpreted as water.
  We then consider land portions adjacent vertically or horizontally as part of the same island.
  The program should then display the number islands.

  In the above example, the number of islands output should be 5.
