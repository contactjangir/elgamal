
.PHONY = all clean

all:
	gcc elgamal.c -o elgamal
clean:
	rm elgamal
