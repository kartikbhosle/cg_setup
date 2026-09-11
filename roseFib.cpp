#include <graphics.h>
#include <conio.h>
#include <math.h>
#include <windows.h>

#define PI 3.14159265358979323846

// ======================================================
// 64 PETAL ROSE CURVE - LEFT SIDE
// ======================================================
void drawRose(int cx, int cy, int maxRadius)
{
    int k = 32;   // 32 -> 64 petals

    for (double theta = 0; theta <= 2 * PI; theta += 0.0005)
    {
        double r = maxRadius * cos(k * theta);

        int x = cx + (int)(r * cos(theta));
        int y = cy + (int)(r * sin(theta));

        // Keep drawing inside left half
        if (x > 20 && x < getmaxx() / 2 - 15 &&
            y > 70 && y < getmaxy() - 50)
        {
            int color = ((int)(theta * 20) % 14) + 1;
            putpixel(x, y, color);
        }
    }

    // Center
    setcolor(YELLOW);
    setfillstyle(SOLID_FILL, YELLOW);
    fillellipse(cx, cy, 7, 7);
}


// ======================================================
// FIBONACCI SUNFLOWER - RIGHT SIDE
// ======================================================
void drawSunflower(int cx, int cy, int maxRadius)
{
    // Golden angle
    double goldenAngle = 137.507764 * PI / 180.0;

    for (int i = 0; i < 650; i++)
    {
        double angle = i * goldenAngle;

        // Fibonacci-style radial growth
        double radius = maxRadius * sqrt((double)i / 650.0);

        int x = cx + (int)(cos(angle) * radius);
        int y = cy + (int)(sin(angle) * radius);

        int size;

        if (i < 100)
            size = 2;
        else
            size = 2 + (i % 3);

        int color = (i % 14) + 1;

        setcolor(color);
        setfillstyle(SOLID_FILL, color);

        fillellipse(x, y, size, size);
    }

    // Large center
    setcolor(YELLOW);
    setfillstyle(SOLID_FILL, YELLOW);
    fillellipse(cx, cy, maxRadius / 6, maxRadius / 6);
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


// ======================================================
// MAIN
// ======================================================
int main()
{
    // Create graphics window
    initwindow(1200, 700, "Rose Curve + Fibonacci Sunflower");

    // Maximize the graphics window
    HWND hwnd = GetForegroundWindow();
    ShowWindow(hwnd, SW_MAXIMIZE);

    setbkcolor(BLACK);
    cleardevice();

    int width = getmaxx();
    int height = getmaxy();

    int middle = width / 2;

    // --------------------------------------------------
    // TITLE
    // --------------------------------------------------

    setcolor(WHITE);
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);

    //outtextxy(middle / 2 - 90, 35,
           //   "64 PETAL ROSE");

    //outtextxy(middle + middle / 2 - 130, 35,
         //     "FIBONACCI SUNFLOWER");


    // --------------------------------------------------
    // VERTICAL DIVIDER
    // --------------------------------------------------

    setcolor(DARKGRAY);
    line(middle, 20, middle, height - 20);


    // --------------------------------------------------
    // ROSE
    // --------------------------------------------------

    int roseCX = middle / 2;
    int roseCY = height / 2 + 20;

    int roseRadius = (middle < height)
                     ? middle / 2 - 50
                     : height / 2 - 80;

    drawRose(roseCX, roseCY, roseRadius);


    // --------------------------------------------------
    // SUNFLOWER
    // --------------------------------------------------

    int sunCX = middle + middle / 2;
    int sunCY = height / 2 + 20;

    int sunRadius = (middle < height)
                    ? middle / 2 - 50
                    : height / 2 - 80;

    drawSunflower(sunCX, sunCY, sunRadius);


    // --------------------------------------------------
    // LABELS
    // --------------------------------------------------

    setcolor(LIGHTMAGENTA);
    // outtextxy(roseCX - 90, height - 45,
    //           "Rose Curve : 64 Petals");

    setcolor(LIGHTGREEN);
    // outtextxy(sunCX - 110, height - 45,
    //           "Fibonacci Pattern");

    
    color(width / 2 - 70, height - 35);


    getch();

    closegraph();

    return 0;
}
