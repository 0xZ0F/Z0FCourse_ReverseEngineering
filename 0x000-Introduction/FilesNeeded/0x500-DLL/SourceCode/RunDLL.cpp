#include <iostream>
#include <Windows.h>

class Player {
public:
	int score;
	float health;
	std::string name;
};

//extern "C" void __declspec(dllexport) __cdecl SayHello()
typedef void(WINAPI* ESayHello)(void);
//void __declspec(dllexport) __cdecl PrintArray(int x[])
typedef void(WINAPI* EPrintArray_Int)(int[]);
typedef void(WINAPI* EPrintArray_Char)(char[], int);
//void __declspec(dllexport) InitializeClass(Player* player)
typedef void(WINAPI* EInitializeClass)(Player*);
//extern "C" void __declspec(dllexport) PrintPlayerStats(Player* player)
typedef void(WINAPI* EPrintPlayerStats)(Player);
//extern "C" void __declspec(dllexport) MysteryFunc1(Player* player)
typedef void* (WINAPI* EMysteryFunc)(Player*, int* []);

int main()
{
	Player player;

	// Load lib and validate:
	std::cout << ">> Loading DLL..." << std::endl;
	HMODULE dll = LoadLibraryA("DLL.DLL");
	if (dll != NULL) {
		// SayHello:
		ESayHello SayHello = (ESayHello)GetProcAddress(dll, "SayHello");
		if (SayHello != NULL) {
			std::cout << ">> Calling SayHello()..." << std::endl;
			SayHello();
		}
		else { std::cout << "!! Can't load function SayHello()." << std::endl; }

		// PrintArray:
		EPrintArray_Char PrintArray = (EPrintArray_Char)GetProcAddress(dll, "?PrintArray@@YAXQEADH@Z");
		if (PrintArray != NULL) {
			std::cout << ">> Calling PrintArray(char) with array of { 'A','B','C','D'}..." << std::endl;
			char myArray[4] = { 'A','B','C','D' };
			PrintArray(myArray, 4);
		}
		else { std::cout << "!! Can't load function PrintArray(char)." << std::endl; }

		// SetupPlayer:
		EInitializeClass InitializeClass = (EInitializeClass)GetProcAddress(dll, "?InitializePlayer@@YAXPEAVPlayer@@@Z");
		if (InitializeClass != NULL) {
			std::cout << ">> Calling InitializeClass()..." << std::endl;
			InitializeClass(&player);
		}
		else { std::cout << "!! Can't load function InitializeClass()." << std::endl; }

		// PrintPlayerStats:
		EPrintPlayerStats PrintPlayerStats = (EPrintPlayerStats)GetProcAddress(dll, "PrintPlayerStats");
		if (PrintPlayerStats != NULL) {
			std::cout << ">> Calling PrintPlayerStats()..." << std::endl;
			PrintPlayerStats(player);
		}
		else { std::cout << "!! Can't load function PrintPlayerStats()." << std::endl; }

		//MysteryFunc1
		EMysteryFunc MysteryFunc = (EMysteryFunc)GetProcAddress(dll, "MysteryFunc");
		std::cout << ">> Calling MysteryFunc()..." << std::endl;
		if (MysteryFunc != NULL) {
			int* arr[4];
			void* ret = MysteryFunc(&player, arr);
			std::cout << "Info:" << std::endl;
			std::cout << arr[0] << std::endl;
			std::cout << arr[1] << std::endl;
			std::cout << arr[2] << std::endl;
			std::cout << arr[3] << std::endl;
			std::cout << ret << std::endl;
		}
		else { std::cout << "!! Can't load function MysteryFunc()." << std::endl; }
	}
	else { std::cout << "!! Can't load DLL." << std::endl; }
	return 0;
}

// PrintArray:
		/*EPrintArray_Char PrintArray = (EPrintArray_Char)GetProcAddress(dll, "?PrintArray@@YAXQEAD@Z");
		if (PrintArray != NULL) {
			char myArray[10] = { 'A','B','C' };
			PrintArray(myArray);
		}
		else { std::cout << "Can't load function." << std::endl; }*/