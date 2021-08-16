#include "Object.h"
#include "ObjectPoolManager.h"


bool check = false;

void Output(float _x, float _y, string _str);

int main(void)
{

	list<Object*> DesableList;
	list<Object*> EnableList;

	// if 없이 작성하면 -> 표시가 뜸 왜??
	if (GetAsyncKeyState(VK_RETURN))
		check = true;

	if (check)
	{
		//** DesableList 에 여분의 오브젝트가 있는지 확인 하고 없다면...
		if (DesableList.empty())
		{
			//** 5개의 오브젝트를 추가 생성한 후...
			for (int i = 0; i < 5; ++i)
				DesableList.push_back(new Object);
		}
		//** 추가 생성된 오브젝트 하나를 선택.
		list<Object*>::iterator iter = DesableList.begin();
		//** 초기화 에 필요한 구문 작성.
		(*iter)->Initialize();
		//** 사용할 리스트에 추가.
		EnableList.push_back((*iter));
		//** 현재 리스트에서 삭제.
		DesableList.pop_front();

		for (list<Object*>::iterator iter = EnableList.begin();
			iter != EnableList.end();)
		{
			int iResult = (*iter)->Update();
			(*iter)->Render();
			if (iResult == 1)
			{
				//** 현재 리스트에서 삭제.
				DesableList.push_back((*iter));
				//** 사용할 리스트에 추가.
				iter = EnableList.erase(iter);
			}
			else
				++iter;
		}

	}

	{
		//** 현재 리스트에 남아있는 오브젝트의 개수 확인. (DesableList)
		string Buffer = "DesableList : " + to_string(DesableList.size());
		Output(10, 1, Buffer);
		Buffer.clear();
		//** 현재 리스트에 남아있는 오브젝트의 개수 확인. (EnableList)
		Buffer = "EnableList : " + to_string(EnableList.size());
		Output(10, 2, Buffer);
	}

	//** DesableList 전제 삭제
	for (list<Object*>::iterator iter = DesableList.begin();
		iter != DesableList.end(); ++iter)
	{
		delete (*iter);
		(*iter) = nullptr;
	}
	DesableList.clear();

	//** EnableList 전제 삭제
	for (list<Object*>::iterator iter = EnableList.begin();
		iter != EnableList.end(); ++iter)
	{
		delete (*iter);
		(*iter) = nullptr;
	}
	EnableList.clear();
	return 0;
}

void Output(float _x, float _y, string _str)
{
	COORD Pos = { (SHORT)_x, (SHORT)_y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
	cout << _str << endl;
}