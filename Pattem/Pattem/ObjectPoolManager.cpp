#include "ObjectPoolManager.h"

#include "Object.h"

ObjectPoolManager* ObjectPoolManager::Instance = nullptr;

//
//void ObjectPoolManager::Intialize()
//{
//	Key = 0;
//
//	TransInfo.Position = Vector3();
//}
//
//void ObjectPoolManager::Output(float _x, float _y, string _str)
//{
//	COORD Pos = { _x, _y };
//	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
//	cout << _str << endl;
//}
//
ObjectPoolManager::ObjectPoolManager()
{

}

ObjectPoolManager::~ObjectPoolManager()
{

}