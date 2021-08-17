#include "ObjectPoolManager.h"
#include "Object.h"

ObjectPoolManager* ObjectPoolManager::Instance = nullptr;



ObjectPoolManager::ObjectPoolManager()
{

}

ObjectPoolManager::~ObjectPoolManager()
{
	Release();
}


void ObjectPoolManager::Update()
{
	if (GetAsyncKeyState(VK_RETURN))
	{
		//** DesableList �� ������ ������Ʈ�� �ִ��� Ȯ�� �ϰ� ���ٸ�...
		if (DesableList.empty())
		{
			//** 5���� ������Ʈ�� �߰� ������ ��...
			for (int i = 0; i < 5; ++i)
				DesableList.push_back(new Object);
		}


		//** �߰� ������ ������Ʈ �ϳ��� ����.
		list<Object*>::iterator iter = DesableList.begin();

		//** �ʱ�ȭ �� �ʿ��� ���� �ۼ�.
		(*iter)->Initialize();

		//** ����� ����Ʈ�� �߰�.
		EnableList.push_back((*iter));

		//** ���� ����Ʈ���� ����.
		DesableList.pop_front();
	}

	for (list<Object*>::iterator iter = EnableList.begin();
		iter != EnableList.end();)
	{
		int iResult = (*iter)->Update();

		if (iResult == 1)
		{
			//** ���� ����Ʈ���� ����.
			DesableList.push_back((*iter));
			//** ����� ����Ʈ�� �߰�.
			iter = EnableList.erase(iter);
		}
		else
			++iter;
	}
}


void ObjectPoolManager::Render()
{
	for (list<Object*>::iterator iter = EnableList.begin();
		iter != EnableList.end(); ++iter)
		(*iter)->Render();



	{
		//** ���� ����Ʈ�� �����ִ� ������Ʈ�� ���� Ȯ��. (DesableList)
		COORD Pos = { (SHORT)10, (SHORT)5 };
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);

		string Buffer = "DesableList : " + to_string(DesableList.size());
		cout << Buffer << endl;
	}

	{
		COORD Pos = { (SHORT)10, (SHORT)6 };
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);

		string Buffer = "EnableList : " + to_string(EnableList.size());
		cout << Buffer << endl;
	}
}

void ObjectPoolManager::Release()
{
	//** DesableList ���� ����
	for (list<Object*>::iterator iter = DesableList.begin();
		iter != DesableList.end(); ++iter)
	{
		delete (*iter);
		(*iter) = nullptr;
	}
	DesableList.clear();

	//** EnableList ���� ����
	for (list<Object*>::iterator iter = EnableList.begin();
		iter != EnableList.end(); ++iter)
	{
		delete (*iter);
		(*iter) = nullptr;
	}
	EnableList.clear();
}