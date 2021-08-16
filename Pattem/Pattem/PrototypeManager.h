#pragma once
#include "Headers.h"


class Object;
class PrototypeManager
{
private:
	static PrototypeManager* Instance;
public:
	static PrototypeManager* GetInstance()
	{
		if (Instance == nullptr)
			Instance = new PrototypeManager;
		return Instance;
	}
private:
	map<string, Object*> PrototypeList;
public:
	void Initialize();
	Object* FineObject(string _str);
private:
	PrototypeManager();
public:
	~PrototypeManager();
};