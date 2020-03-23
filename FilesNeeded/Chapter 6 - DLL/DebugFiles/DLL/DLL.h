#include <iostream>
#include <string>

class Player {
public:
	int score;
	float health;
	std::string name;
};

extern "C" void __declspec(dllexport) SayHello();

void __declspec(dllexport) PrintArray(int arr[], int size);
void __declspec(dllexport) PrintArray(char arr[], int size);
void __declspec(dllexport) InitializePlayer(Player* player);
extern "C" void __declspec(dllexport) PrintPlayerStats(Player player);

//Set array to be addrs of elements in Player class. Ret the base addr:
extern "C" __declspec(dllexport) void* MysteryFunc(Player* player, int* arr[]);