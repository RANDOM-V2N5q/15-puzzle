#include "MainHeader.h"

int main(int argc, char *argv[]) {
	srand(time(NULL));
	App app(argc, argv);
	app.run();
	return 0;
}