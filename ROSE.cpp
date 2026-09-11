#include <graphics.h>
#include <conio.h>
#include <math.h>
#include <windows.h>

#define PI 3.14159

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
    initwindow(800, 600, "Rose Curve");

    HWND hwnd = GetForegroundWindow();
ShowWindow(hwnd, SW_MAXIMIZE);

    setbkcolor(BLACK);
    cleardevice();

    int cx = 400;
    int cy = 300;

    // Number of petals
    int k = 64;

    // Draw rose
    for (double theta = 0;
         theta <= 2 * PI;
         theta += 0.001)
    {
        // Rose equation
        double r = 200 * cos(k * theta);

        int x = cx + (int)(r * cos(theta));
        int y = cy + (int)(r * sin(theta));

        // Multiple colors
        int color = ((int)(theta * 10) % 14) + 1;

        putpixel(x, y, color);
    }

    // Center
    setcolor(YELLOW);
    setfillstyle(SOLID_FILL, YELLOW);
    fillellipse(cx, cy, 8, 8);

    setcolor(WHITE);
    outtextxy(370, 550, "ROSE CURVE");

    color(370, 550);

    getch();
    closegraph();

    return 0;
}