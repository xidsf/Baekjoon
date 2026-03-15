#include <iostream>
#include <cstring>
using namespace std;

bool isClear[64][64] = { 0, };
bool rotMap[64][64][4] = {0,};
int ruleA[64][64] = { 0, };
int ruleB[64][64] = { 0, };
int currentPosH, currentPosW, currentRot;
int currentRule = 0; // 0 : A, 1 : B

int maxH, maxW;

int main()
{
	cin >> maxH >> maxW;
	cin >> currentPosH >> currentPosW >> currentRot;
	string input;
	for (int i = 0; i < maxH; i++)
	{
		cin >> input;
		for (int j = 0; j < maxW; j++)
		{
			ruleA[i][j] = input[j] - '0';
		}
	}
	for (int i = 0; i < maxH; i++)
	{
		cin >> input;
		for (int j = 0; j < maxW; j++)
		{
			ruleB[i][j] = input[j] - '0';
		}
	}

	int currentMove = 0;
	int lastCleanMove = 0;

	while(true)
	{
		if (rotMap[currentPosH][currentPosW][currentRot] && currentRule == 1)
		{
			break;
		}

		if (!isClear[currentPosH][currentPosW])
		{
			isClear[currentPosH][currentPosW] = true;
			lastCleanMove = currentMove;
			currentRule = 0;
			memset(rotMap, 0, sizeof(rotMap));
		}
		else
		{
			currentRule = 1;
			rotMap[currentPosH][currentPosW][currentRot] = true;
		}
		
		currentRot = currentRot + (currentRule == 0 ? ruleA[currentPosH][currentPosW] : ruleB[currentPosH][currentPosW]);
		currentRot = currentRot % 4;

		switch (currentRot)
		{
		case 0:
			currentPosH--;
			break;
		case 1:
			currentPosW++;
			break;
		case 2:
			currentPosH++;
			break;
		case 3:
			currentPosW--;
			break;
		}
		currentMove++;

		if (currentPosH < 0 || currentPosH >= maxH || currentPosW < 0 || currentPosW >= maxW)
		{
			break;
		}
	}


	cout << lastCleanMove + 1;
	return 0;
}