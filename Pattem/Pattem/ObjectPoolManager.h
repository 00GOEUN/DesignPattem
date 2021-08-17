#pragma once
#include "Headers.h"


class Object;
class ObjectPoolManager
{
private:
	int Key;
	Transform TransInfo;

private:
	static ObjectPoolManager* Instance;
public:
	static ObjectPoolManager* GetInstance()
	{
		if (Instance == nullptr)
			Instance = new ObjectPoolManager;
		return Instance;
	}
private:
	//** ���� ����� ������Ʈ (������ �� ������Ʈ ����Ʈ)
	list<Object*> EnableList;

	//** ����� ��ģ ������Ʈ ����Ʈ (������ ���� ����)
	list<Object*> DesableList;

public:
	void Update();
	void Render();
	void Release();

public:
	ObjectPoolManager();
	~ObjectPoolManager();
};
