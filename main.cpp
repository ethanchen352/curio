#include "curio.h"

int main() {
	initialize();

	while (true) {
		run_command(input_handler());
	}

	return 0;
}



