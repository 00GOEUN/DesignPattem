#pragma once
#include "Headers.h"

class Object
{
private:
	string str;
	Transform TransInfo;
public:
	void Initialize()
	{
		str = "->";
		TransInfo.Position = Vector3(4.0f, 15.0f);
	}

	int Update()
	{
		TransInfo.Position.x++;

		if (TransInfo.Position.x >= 100)
			return 1;

		return 0;
	}

	void Render()
	{
		COORD Pos = { (SHORT)TransInfo.Position.x, (SHORT)TransInfo.Position.y };
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
		cout << str << endl;
	}
public:
	Object() { }
	Object(const Transform& _TransInfo) : TransInfo(_TransInfo) { }
	~Object() { }
};