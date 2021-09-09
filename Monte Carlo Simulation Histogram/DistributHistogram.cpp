﻿#include "pch.h"
#include "tipsware.h"

NOT_USE_MESSAGE

#define GRAPH_WIDTH   520  // 그래프의 폭
#define GRAPH_HEIGHT  590  // 그래프의 높이

#define CENTER_X      (GRAPH_WIDTH/2)  // 그래프의 중심 점 (x)
#define CENTER_Y      (GRAPH_HEIGHT/2) // 그래프의 중심 점 (y)

#define ZOOM_LEVEL    10

#define MAX_TRY 3000000
#define SCALING_FACTOR 100
#define RANGE 100

void DrawBackgroundOfGraph()
{
    Rectangle(20, 0, GRAPH_WIDTH, GRAPH_HEIGHT, RGB(0, 0, 0));

    SelectFontObject("굴림", 10, 1);
    SetTextColor(RGB(0, 0, 0));

    for (int i = 0; i < 10; i++) {
        TextOut(0, i * (GRAPH_HEIGHT / 10), "%d", (600-i*60) * SCALING_FACTOR);
        Line(20, i * (GRAPH_HEIGHT/ 10), 25, i * (GRAPH_HEIGHT / 10), RGB(182, 198, 198));
    }

    for (int i = 0; i < RANGE; i++) {
        Line(23 + i * 5, GRAPH_HEIGHT - 5, 23 + i * 5, GRAPH_HEIGHT, RGB(182, 198, 198));
        if (i % 10 == 0) {
            TextOut(18 + i * 5, GRAPH_HEIGHT + 1, "%d", i);
        }
    }
}

int main()
{
    DrawBackgroundOfGraph();
    HWND g_hWnd = GetForegroundWindow();
    SetWindowPos(g_hWnd, NULL, 50, 50, 1000, 700, 0);

    int numArr[RANGE] = { 0, };
    int uniArr[RANGE] = { 0, };

    SelectPenObject(RGB(255, 255, 0));

    int randTemp;

    for (int i = 0; i < MAX_TRY; i++) {
        randTemp = rand() % RANGE;
        numArr[randTemp] += 1;
    }
    // TODO
    for (int i = 0; i < RANGE; i++) {

        Rectangle((23 + i * 5) - 1.0, GRAPH_HEIGHT, (23 + i * 5) + 1.0, GRAPH_HEIGHT - (numArr[i] / (GRAPH_HEIGHT / 6)), RGB(0, 0, 255));
        //for (int j = 0; j < RANGE; j++) {
        //    Rectangle((23 + i) - 1.0, GRAPH_HEIGHT, (23 + i) + 1.0, GRAPH_HEIGHT - numArr[j], RGB(0, 0, 255));
        //}
    }
    //Rectangle(46 - 1.0, GRAPH_HEIGHT, 46 + 1.0, GRAPH_HEIGHT - 100, RGB(0, 0, 255));
    //Rectangle(123 - 1.0, GRAPH_HEIGHT, 123 + 1.0, GRAPH_HEIGHT - 250, RGB(0, 0, 255));
    
    //

    ShowDisplay();
    return 0;
}