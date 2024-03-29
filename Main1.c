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

	// �������� �������� �������.

	wchar_t commandLine[] = L"notepad.exe";

	if (!CreateProcess(NULL, // -

		commandLine,     // ��������� ������.

		NULL,                 // ���������� �������� �� �����������.

		NULL,                 // ���������� ������ �� �����������.

		FALSE,                // ��������� ������������ ����������� � FALSE.

		0,                    // ������� �������� ���.

		NULL,                 // ����������� ���� ������������ ��������.

		NULL,                 // ����������� ��������� ������� ��������.

		&si,                  // ��������� �� ��������� STARTUPINFO.

		&pi)                 // ��������� �� ��������� PROCESS_INFORMATION.

		)

		//ErrorExit("CreateProcess failed.");
		printf("CreateProcess failed");
	else
		printf("CreateProcess finished");

	// ����� �� ��� ���, ���� �������� ������� �� ������ �� ������.

	WaitForSingleObject(pi.hProcess, INFINITE);

	// ������� ����������� �������� � ������.

	CloseHandle(pi.hProcess);

	CloseHandle(pi.hThread);

}