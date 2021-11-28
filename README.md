 # CRYPTO ASSIGNMENT #4
 # The ElGamal encryption system is an asymmetric key encryption algorithm for public-key cryptography which is based on the Diffie–Hellman key exchange.

 Name: Ram Chandra Jangir

Roll Number : CS21M517

Registered Mail ID: contactjangir@gmail.com

----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

# How to compile and run the program:

 # Step-1 :
Clone this project using below command and you will get below list of files.

git clone https://github.com/contactjangir/elgamal.git

cd elgamal

elgamal $ tree
.

├── elgamal    --> This is my precompiled elgamal program binary, you may run directly too.

├── elgamal.c

├── elgamal.h

├── Makefile

├── output.txt     -->  I have run elgamal binary and output is stored in this file.

├── Ram-Assignment-4.pdf

└── README.md

0 directories, 7 files


 # Step-2 :
It is already having a precompiled binary elgamal which can be run directly on Ubuntu system.

OR
How to compile

make

# Step-3 :
How to run this program:

rjangir@rjangir-linux:/local/mnt/workspace/rjangir/WORKSPACE/elgamal$ ./elgamal

Enter a numeric message to encrypt (Plain text) : 101

----------------------------------------------------------------------------------------

Elgamal Encryption:

        Plaintext '101'
        Public key ( e1, e2, p ) : ( 2, 913754177, 1350490027 )
        Private key ( d )        : ( 783368691 )
        Ciphertext ( C1, C2 )    : ( 184141051, 1188726853 )

----------------------------------------------------------------------------------------

Elgamal Decryption:

        Ciphertext ( C1, C2 ) : ( 184141051, 1188726853 )
        The decrypted message (plaintext) is : 101

