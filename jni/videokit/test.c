#include <stdio.h>

char msgbuf[256];

#define FAKE_FPRINTF(_ignored, fmt, ...) { sprintf(msgbuf, fmt, ## __VA_ARGS__); fprintf(stdout,"%s",msgbuf); }

int main() {
	FAKE_FPRINTF(whatever, "Having a good time with %s!\n", "Jim");
	FAKE_FPRINTF(whatever, "Having a good time on my own.\n");
	return 0;
}

