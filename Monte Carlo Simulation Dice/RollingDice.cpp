#include "pch.h"
#include "tipsware.h"
#include "time.h"
#define _USE_MATH_DEFINES
#include "math.h"

NOT_USE_MESSAGE

#define MAX_TRY 10000

int main()
{
	//srand(time(NULL));

	SelectPenObject(RGB(0, 0, 0));

	int hit = 0;
	int miss = 0;
	float relProb = 5.0 / 36.0;
	float prob = 0;

	int randTemp1;
	int randTemp2;

	int arr1[MAX_TRY];
	int arr2[MAX_TRY];
	float count = 0;
	// TODO 

	for (int i = 0; i < MAX_TRY; i++) {
		randTemp1 = rand() % 6 + 1;
		randTemp2 = rand() % 6 + 1;

		arr1[i] = randTemp1;
		arr2[i] = randTemp2;
	}

	for (int i = 0; i < MAX_TRY; i++) {
		if (arr1[i] + arr2[i] == 8) {
			count += 1.0;
			TextOut(120 * (i / 20), 20 * (i % 20), "try %d: %d,%d (hit!)", 1 + i, arr1[i], arr2[i]);
		}
		else {
			TextOut(120 * (i / 20), 20 * (i % 20), "try %d: %d,%d", 1 + i, arr1[i], arr2[i]);
		}
	}
	//TextOut(120 * (0 / 20), 20 * (0 % 20), "try %d: %d,%d (hit!)", 0 + 1, 6, 2);
	//TextOut(120 * (1 / 20), 20 * (1 % 20), "try %d: %d,%d", 0 + 2, 6, 6);
	
	prob = count / MAX_TRY;

	SetTextColor(RGB(128, 0, 0));
	// 실제 주사위 값
	TextOut(0, 420, "실제 값: %.6f", relProb);
	// 계산된 값
	TextOut(0, 440, "계산된 값: %.6f", prob);

	ShowDisplay();

	return 0;
}
