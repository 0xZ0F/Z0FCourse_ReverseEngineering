#include <iostream>
#include <string>

class Player {
public:
	int score;
	float health;
	std::string name;
};

extern "C" void __declspec(dllexport) SayHello() {
	std::cout << "Hello!" << std::endl;
}

void __declspec(dllexport) PrintArray(int arr[], int size) {
	for (int i = 0; i < size; i++) {
		std::cout << arr[i] << std::endl;
	}
}
void __declspec(dllexport) PrintArray(char arr[], int size) {
	for (int i = 0; i < size; i++) {
		std::cout << arr[i] << std::endl;
	}
}

void __declspec(dllexport) InitializePlayer(Player* player) {
	player->score = 32;
	player->health = 100.0f;
	player->name = "PLACEHOLDER";
}

extern "C" void __declspec(dllexport) PrintPlayerStats(Player player) {
	printf("PRINTING PLAYER STATS\n");
	printf("Score: %d\n", player.score);
	printf("Health: %f\n", player.health);
	printf("Name: %s\n", player.name.c_str());
}
//Set array to be addrs of elements in Player class. Ret the base addr:
extern "C" __declspec(dllexport) void* MysteryFunc(Player* player, int* arr[]) {
	arr[0] = (int*)player;
	arr[1] = (int*)& player->score;
	arr[2] = (int*)& player->health;
	arr[3] = (int*)& player->name;
	return player;
}