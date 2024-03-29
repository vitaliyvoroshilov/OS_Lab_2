#include <Windows.h>
#include <Winbase.h>
#include <stdio.h>


void main(VOID)

{

	STARTUPINFO si;

	PROCESS_INFORMATION pi;

	ZeroMemory(&si, sizeof(si));

	si.cb = sizeof(si);

	ZeroMemory(&pi, sizeof(pi));

	// Запустим дочерний процесс.

	wchar_t commandLine[] = L"notepad.exe";

	if (!CreateProcess(NULL, // -

		commandLine,     // Командная строка.

		NULL,                 // Дескриптор процесса не наследуемый.

		NULL,                 // Дескриптор потока не наследуемый.

		FALSE,                // Установим наследование дескриптора в FALSE.

		0,                    // Флажков создания нет.

		NULL,                 // Используйте блок конфигурации родителя.

		NULL,                 // Используйте стартовый каталог родителя.

		&si,                  // Указатель на структуру STARTUPINFO.

		&pi)                 // Указатель на структуру PROCESS_INFORMATION.

		)

		//ErrorExit("CreateProcess failed.");
		printf("CreateProcess failed");
	else
		printf("CreateProcess finished");

	// Ждать до тех пор, пока дочерний процесс не выйдет из работы.

	WaitForSingleObject(pi.hProcess, INFINITE);

	// Закроем дескрипторы процесса и потока.

	CloseHandle(pi.hProcess);

	CloseHandle(pi.hThread);

}