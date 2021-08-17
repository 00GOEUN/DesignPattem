#include "Object.h"
#include "ObjectPoolManager.h"
#include "PrototypeManager.h"


int main(void)
{
	PrototypeManager::GetInstance()->Initialize();
	ULONGLONG Time = GetTickCount64();


	while (true)
	{
		if (Time + 80 < GetTickCount64())
		{
			Time = GetTickCount64();
			system("cls");

			ObjectPoolManager::GetInstance()->Update();
			ObjectPoolManager::GetInstance()->Render();
		}
	}


	return 0;
}
