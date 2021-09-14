#include "pch.h"
#include "tipsware.h"
#include <random>
#include <iostream>

NOT_USE_MESSAGE

#define MAX_POINTS 10000
#define RADIUS 10
#define POINTS_RADIUS 3

#define GRAPH_WIDTH   600
#define GRAPH_HEIGHT  600

#define CENTER_X      (GRAPH_WIDTH/2)
#define CENTER_Y      (GRAPH_HEIGHT/2)

#define ZOOM_LEVEL    10

inline void MyMoveTo(int a_x, int a_y)
{
	MoveTo(a_x * ZOOM_LEVEL + CENTER_X, -(a_y * ZOOM_LEVEL - CENTER_Y));
}

inline void MyLineTo(int a_x, int a_y)
{
	LineTo(a_x * ZOOM_LEVEL + CENTER_X, -(a_y * ZOOM_LEVEL - CENTER_Y));
}


void DrawBackgroundOfGraph()
{
	Rectangle(0, 0, GRAPH_WIDTH, GRAPH_HEIGHT, RGB(232, 248, 248), RGB(87, 101, 126));

	Line(CENTER_X, 0, CENTER_X, GRAPH_HEIGHT, RGB(232, 248, 248));
	for (int i = 0; i < GRAPH_HEIGHT / ZOOM_LEVEL; i++) {
		Line(CENTER_X - 2, i * ZOOM_LEVEL, CENTER_X + 3, i * ZOOM_LEVEL, RGB(182, 198, 198));
	}
	Line(0, CENTER_Y, GRAPH_WIDTH, CENTER_Y, RGB(232, 248, 248));
	for (int i = 0; i < GRAPH_WIDTH / ZOOM_LEVEL; i++) {
		Line(i * ZOOM_LEVEL, CENTER_Y - 2, i * ZOOM_LEVEL, CENTER_Y + 3, RGB(182, 198, 198));
	}

	SelectFontObject("굴림", 20, 1);
	SetTextColor(RGB(255, 255, 255));
	TextOut(560, 310, "x축");
	TextOut(310, 5, "y축");
}

using namespace std;

int main()
{
	srand(time(NULL));
	DrawBackgroundOfGraph();

	SelectPenObject(RGB(0, 0, 0));

	MyMoveTo(RADIUS, RADIUS);
	MyLineTo(RADIUS, -RADIUS);
	MyMoveTo(-RADIUS, RADIUS);
	MyLineTo(-RADIUS, -RADIUS);
	MyMoveTo(-RADIUS, -RADIUS);
	MyLineTo(RADIUS, -RADIUS);
	MyMoveTo(RADIUS, RADIUS);
	MyLineTo(-RADIUS, RADIUS);

	float calPi = 0;

	// TODO
	int randTemp1;
	int randTemp2;
	int tmp = 0;
	float count = 0;

	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> dis(-100, 100);
	std::uniform_int_distribution<int> dis1(-100, 100);

	for (int i = 0; i < MAX_POINTS * 4; i++) {
		randTemp1 = dis(gen);
		randTemp2 = dis1(gen);

		tmp = (randTemp1 * randTemp1) + (randTemp2 * randTemp2);
		if (tmp <= 10000) {
			Ellipse(CENTER_X - randTemp1, CENTER_Y + randTemp2, CENTER_X - randTemp1 + POINTS_RADIUS, CENTER_Y + randTemp2 + POINTS_RADIUS, RGB(255, 0, 0), RGB(255, 0, 0));
			count += 1;
		}
		else {
			Ellipse(CENTER_X - randTemp1, CENTER_Y + randTemp2, CENTER_X - randTemp1 + POINTS_RADIUS, CENTER_Y + randTemp2 + POINTS_RADIUS, RGB(255, 255, 0), RGB(255, 255, 0));
		}
	}
	//Ellipse(CENTER_X + randTemp1, CENTER_Y + randTemp2, CENTER_X + randTemp1 + POINTS_RADIUS, CENTER_Y + randTemp2 + POINTS_RADIUS, RGB(255, 0, 0), RGB(255, 0, 0));

	//
	calPi =  (count / MAX_POINTS);
	TextOut(20, 20, "계산된 pi 값: %f", calPi);
	TextOut(20, 40, "실제 pi 값: %f", M_PI);
	TextOut(20, 60, "오차율: %.2f%c", fabs(((calPi / M_PI)-1.0)*100.0), 37);

	ShowDisplay();
	return 0;
}