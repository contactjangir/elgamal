
#ifndef __ELGAMAL_H__
#define __ELGAMAL_H__


/* format specifier for different cosole colors */
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define KWHT  "\x1B[37m"

typedef long long int llint;

/* structyre for holding RSA key pair */
struct elgamal_key_pair
{
  llint e1;
  llint e2;
  llint p;
  llint d;
};

#endif
