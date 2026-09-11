#include <graphics.h>
#include <conio.h>
#include <math.h>

#define PI 3.14159

void drawTree(int x1, int y1, double angle, int depth)
{
    if (depth == 0)
        return;

    // Smaller branch length
    int length = depth * 6;

    int x2 = x1 + (int)(cos(angle) * length);
    int y2 = y1 - (int)(sin(angle) * length);

    // Branch color
    int color = (depth * 2) % 15 + 1;
    setcolor(color);

    line(x1, y1, x2, y2);

    // Left branch
    drawTree(x2, y2, angle - PI / 8, depth - 1);

    // Right branch
    drawTree(x2, y2, angle + PI / 8, depth - 1);
}

void color(int x, int y)
{
    char name[] = {
        75, 97, 114, 116, 105, 107,
        32,
        66, 104, 111, 115, 108, 101,
        0
    };

    setcolor(WHITE);
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);

    outtextxy(x, y, name);
}

int main()
{
    int width = 800;
    int height = 600;

    initwindow(width, height, "Fractal Tree");

    setbkcolor(BLACK);
    cleardevice();

    // Title
    setcolor(WHITE);
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 1);
    outtextxy(340, 40, "Colorful Fractal Tree");

    // Centered trunk
    setcolor(GREEN);
    line(400, 520, 400, 420);

    // Centered fractal tree
    drawTree(400, 420, PI / 2, 9);

    color(width / 2 - 70, height - 35);

    getch();
    closegraph();

    return 0;
}