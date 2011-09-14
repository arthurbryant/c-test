#include  <stdio.h>
#include  <stdlib.h>
#include  <stdint.h>
#include  <assert.h>
#include  <string.h>
  int
encode (const void *raw_in, void *raw_out, uint32_t password, size_t len)
{
  const uint8_t *in = (const uint8_t *) raw_in;
  uint8_t *out = (uint8_t *) raw_out;

  uint32_t seed = password ^ 0xa9a8a2c8u;
  for (size_t i = 0; i < len; ++i)
    {
      uint8_t a = (in[i] ^ seed) >> 2;
      uint8_t b = ((((uint32_t) in[i]) << 20) ^ seed) >> (20 - 6);
      a &= 63;
      b &= 192;
      a = 63 & (a ^ (b << 3));
      out[i] = a | b;
      seed = (seed * 3687989 ^ seed ^ in[i]);
    }
}


int
decode (const void *raw_in, void *raw_out, uint32_t password, size_t len)
{
  const uint8_t *in = (const uint8_t *) raw_in;
  uint8_t *out = (uint8_t *) raw_out;

  uint32_t seed = password ^ 0xa9a8a2c8u;
  for (size_t i = 0; i < len; ++i)
    {
        uint8_t a = 63 & in[i];  
        uint8_t b = 192 & in[i];  
        b = 3 & ( ( ( (uint32_t)b << 14) ^seed) >> 20);  
        a = 252 & ( (a << 2) ^ seed);  
        out[i] = a | b;  
        seed = (seed * 3687989 ^ seed ^ out[i]);
    }
}
int
main ()
{
  const uint8_t buf1[] =
    { 0x65, 0xd2, 0xb9, 0x84, 0x20, 0x80, 0x8c, 0x15, 0x59, 0xf2, 0xe1, 0x15,
0xf2, 0x2f, 0x5e, 0x63, 0xe5, 0x33, 0xe5, 0xf3, 0xe5, 0x33, };
  uint8_t buf2[100] = { };
  const uint32_t password = 0x96c99e94u;
  const size_t len = sizeof (buf1);
  decode (buf1, buf2, password, len);
  printf ("%s\n", buf2);
}
