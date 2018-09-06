#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define NEW_LINE printf("\n");

unsigned long long diffie_hellman(int x, int a, int b) {
	return ( (unsigned long long) pow(a, x) ) % b;
}


int main(int argc, char const *argv[])
{
	int a, b, x, y;

	unsigned long long rAlice, rBob, pkAlice, pkBob;

	printf("Common number A: ");
	scanf(" %d", &a);

	printf("Common number B: ");
	scanf(" %d", &b);

	printf("Alice's secrete number: ");
	scanf(" %d", &x);

	printf("Bob's secrete number: ");
	scanf(" %d", &y);

	NEW_LINE;

	rAlice = diffie_hellman(x, a, b);
	rBob = diffie_hellman(y, a, b);

	printf("Alice's public key: %llu\n", rAlice);
	printf("Bob's public key: %llu\n", rBob);

	pkAlice = diffie_hellman(x, rBob, b);
	pkBob = diffie_hellman(y, rAlice, b);

	printf("Alice's private key: %llu\n", pkAlice);
	printf("Alice's private key: %llu\n", pkBob);

	return 0;
}