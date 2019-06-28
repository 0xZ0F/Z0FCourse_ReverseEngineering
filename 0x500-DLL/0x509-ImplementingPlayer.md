# Implementing `Player`
Now that we've reversed the `Player` class, let's write our own program that makes a `Player` class and uses the functions related to the class.

<p align="center">
  <img src="[ignore]/Player/FinalCode.png">
</p>

The player's name doesn't have to be a `std::string`, it can probably be a `const* char` as well.

# Copy/Paste Code

```c++
#include <iostream>
#include <Windows.h>

class Player {
public:
	int score;
	float health;
	std::string name;
};

//void __cdecl InitializePlayer(class Player * __ptr64)
typedef void(WINAPI* IInitializePlayer)(Player*); // ?InitializePlayer@@YAXPEAVPlayer@@@Z
//void PrintPlayerStats(Player);
typedef void(WINAPI* IPrintPlayerStats)(Player); // PrintPlayerStats

int main()
{
	Player player;
	HMODULE dll = LoadLibraryA("DLL.DLL"); //Load our DLL.
	if (dll != NULL)
	{
		//Initialize Player
		IInitializePlayer InitializePlayer = (IInitializePlayer)GetProcAddress(dll, "?InitializePlayer@@YAXPEAVPlayer@@@Z");
		if (InitializePlayer != NULL) {
			InitializePlayer(&player);
		}
		else { printf("Can't load the function."); }

		//PrintPlayerStats
		IPrintPlayerStats PrintPlayerStats = (IPrintPlayerStats)GetProcAddress(dll, "PrintPlayerStats");
		if (InitializePlayer != NULL) {
			PrintPlayerStats(player);
		}
		else { printf("Can't load the function."); }
		
	}
}
```