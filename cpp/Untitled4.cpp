//C:\TURBOC3\BGI

#include <graphics.h>
#include <conio.h>
int main()
{
    int gd = DETECT, gm;
    initgraph(&gd,&gm, "C:\\TURBOC3\\BGI");
    circle(300,300,50);
    closegraph();
    getch();
    return 0;
}

