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
	//** 실제 사용한 오브젝트 (랜더링 될 오브젝트 리스트)
	list<Object*> EnableList;

	//** 사용을 마친 오브젝트 리스트 (랜더링 되지 않음)
	list<Object*> DesableList;
	//public:
	//	void Intialize();
	//	void Output(float _x, float _y, string _str);

public:
	ObjectPoolManager();
	~ObjectPoolManager();
};
