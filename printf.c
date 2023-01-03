#include <stdio.h>
#include <unistd.h>

int main() {
	char msg[] = "Hello World\n";
	write(STDOUT_FILENO, msg, sizeof(msg) - 1);
	return 0;
}
