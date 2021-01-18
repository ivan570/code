#include <graphics.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int dr = DETECT, dm;
	initgraph(&dr, &dm, "C:\\Program Files (x86)\\Dev-Cpp\MinGW64\\x86_64-w64-mingw32\\lib");

	line(0,0,getmaxx(), getmaxy());
	return 0;
}
