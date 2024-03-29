#include <Windows.h>
#include <stdio.h>

DWORD WINAPI IncThread(LPVOID lpParam) {
	int var = (int)lpParam;
	for (int i = 0; i < 100000000; i++) {
		var++;
	}
}

DWORD WINAPI DecThread(LPVOID lpParam) {
	int var = (int)lpParam;
	for (int i = 0; i < 100000000; i++) {
		var--;
	}
}

int main() {
	volatile long var = 0;
	HANDLE threads[20];
	for (int i = 0; i < 20; i += 2) {
		if (!(threads[i] = CreateThread(NULL, 0, IncThread, (int*)&var, 0, NULL)))
			printf("CreateThread Failed! ");
		else
			printf("CreateThread Finished! ");

		if(!(threads[i + 1] = CreateThread(NULL, 0, DecThread, (int*)&var, 0, NULL)))
			printf("CreateThread Failed! ");
		else
			printf("CreateThread Finished! ");
	}
	WaitForMultipleObjects(20, threads, TRUE, INFINITE);
	for (int i = 0; i < 20; i++) {
		CloseHandle(threads[i]);
	}
	printf("\n%d", var);

}