
#include <stdio.h>
#include <stdlib.h>
#include "elgamal.h"

/* This is a C code for ElGamal encryption, it consists of three components:
*  the key generator, the encryption algorithm, and the decryption algorithm.
*/

/* Euclidean Algorithm for Greatest Common Divisor (GCD) */
llint
gcd (llint a, llint b)
{
  llint m = a, n = b, r;
  while (n > 0)
    {
      int r = m % n;
      m = n;
      n = r;
    }
  return m;
}

/* The do_sqrt() function calculates the nonnegative value of the square root of x. */
double
do_sqrt (llint number)
{
  double sqrt = number;

  while ((sqrt - (double) number / sqrt) > 0.00001)	//loop until precision satisfied
    {
      sqrt = (sqrt + number / sqrt) / 2;
    }
  return sqrt;
}



llint
fastExponention (llint bit, llint n, llint * y, llint * a)
{
  if (bit == 1)
    {
      *y = (*y * (*a)) % n;
    }

  *a = (*a) * (*a) % n;
}

llint
FindT (llint a, llint m, llint n)
{
  llint r;
  llint y = 1;

  while (m > 0)
    {
      r = m % 2;
      fastExponention (r, n, &y, &a);
      m = m / 2;
    }

  return y;
}

/* Function to check a given number is prime number or not */
int
isPrime (unsigned long long int n)
{
  int flag = 1;
  // Iterate from 2 to sqrt(n)
  for (unsigned long long int i = 2; i <= do_sqrt (n); i++)
    {

      // If n is divisible by any number between
      // 2 and n/2, it is not prime
      if (n % i == 0)
	{
	  flag = 0;
	  break;
	}
    }
  return flag;
}


/* Function to calculate public key and private key */
llint
KeyGeneration (struct elgamal_key_pair * ekey)
{
  do
    {
      do
	ekey->p = rand ();
      while (ekey->p % 2 == 0);

    }
  while (!isPrime (ekey->p));

  ekey->e1 = 2;
  do
    {
      ekey->d = rand () % (ekey->p - 2) + 1;	// 1 <= d <= p-2
    }
  while (gcd (ekey->d, ekey->p) != 1);

  ekey->e2 = FindT (ekey->e1, ekey->d, ekey->p);
}


/* Function to encrypt the plaintext to cipher text */
llint
elgamal_encryption (llint plaintext, struct elgamal_key_pair *ekey,
		    llint * C1, llint * C2)
{

  llint r;
  printf
    ("\n----------------------------------------------------------------------------------------\n\n");
  printf ("%sElgamal Encryption:%s\n", KYEL, KWHT);
  printf ("\n\tPlaintext '%lld'", plaintext);
  printf ("\n\tPublic key ( e1, e2, p ) : ( %lld, %lld, %lld )", ekey->e1,
	  ekey->e2, ekey->p);
  printf ("\n\tPrivate key ( d )        : ( %lld )", ekey->d);
  do
    {
      r = rand () % (ekey->p - 1) + 1;	// 1 < r < p
    }
  while (gcd (r, ekey->p) != 1);

  *C1 = FindT (ekey->e1, r, ekey->p);
  *C2 = FindT (ekey->e2, r, ekey->p) * plaintext % ekey->p;

  printf ("\n\tCiphertext ( C1, C2 )    : ( %lld, %lld )\n", *C1, *C2);
}


/* Function to decrypt the ciphertext to plaintext */
llint
elgamal_decryption (struct elgamal_key_pair *ekey, llint * C1, llint * C2)
{
  llint decipher =
    *C2 * FindT (*C1, ekey->p - 1 - ekey->d, ekey->p) % ekey->p;
  printf
    ("\n----------------------------------------------------------------------------------------\n\n");
  printf ("%sElgamal Decryption:%s\n", KYEL, KWHT);
  printf ("\n\tCiphertext ( C1, C2 ) : ( %lld, %lld )", *C1, *C2);
  printf ("\n\tThe decrypted message (plaintext) is : ");
  printf ("%lld\n\n", decipher);

}

void
main ()
{
  llint msg;
  struct elgamal_key_pair ekey;
  llint C1, C2;

  printf ("\nEnter a numeric message to encrypt (Plain text) : ");
  fflush (stdin);
  scanf ("%lld", &msg);

  KeyGeneration (&ekey);

  elgamal_encryption (msg, &ekey, &C1, &C2);

  elgamal_decryption (&ekey, &C1, &C2);
}
