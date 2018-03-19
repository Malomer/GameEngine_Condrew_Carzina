#include "CondrewCarzina.h"
#include <SFML/Graphics.hpp>

void CondrewCarzina::Initialize() {
	gameState = GameState::Uninitialized;

	if (CheckStorage(0)) {
		return;
	}

	if (CheckMemory(0, 0)) {
		return;
	}

	if (ReadCPUSpeed() > 0) {
		return;
	}

	gameState = GameState::ShowingSplash;
}

void CondrewCarzina::Start() {
	if (gameState != Uninitialized)
		return; 
	
	mainWindow.create(sf::VideoMode(1024, 768, 32), "The game that can hopefully make us pass");
	gameState = CondrewCarzina::Playing;
	/*
	while (!IsExiting()) {
		GameLoop();
	}
	*/

	mainWindow.close();
}


bool CondrewCarzina::CheckStorage(const long diskSpaceNeeded) {
	int const drive = _getdrive(); 
	struct _diskfree_t diskfree; 
	_getdiskfree(drive, &diskfree); 
	unsigned __int64 const neededClusters = diskSpaceNeeded / (diskfree.sectors_per_cluster * diskfree.bytes_per_sector); 
	if (diskfree.avail_clusters < neededClusters) { 
		return false; // Not enough disk space
	} 
	return true; 
}

bool CondrewCarzina::CheckMemory(const long physicalRAMNeeded, const long virtualRAMNeeded) {
	MEMORYSTATUSEX status; 
	GlobalMemoryStatusEx(&status); 
	if (status.ullTotalPhys < physicalRAMNeeded) { 
		std::cout << "CheckMemory: Not enough physical memory.";
		return false; 
	}
	if (status.ullAvailVirtual < virtualRAMNeeded) { 
		std::cout << "CheckMemory: Not enough virtual memory.";
		return false; 
	} 
	char *buff = new char[virtualRAMNeeded]; 
	if (buff) 
		delete[] buff; 
	else {
		std::cout << "CheckMemory: Not enough contiguous memory.";
		return false; 

	} 
}

DWORD CondrewCarzina::ReadCPUSpeed() {
	DWORD BufSize = sizeof(DWORD);
	DWORD dwMHz = 0; 
	DWORD type = REG_DWORD; 
	HKEY hKey; 
	long lError = RegOpenKeyEx(HKEY_LOCAL_MACHINE, "HARDWARE\\DESCRIPTION\\System\\CentralProcessor\\0", 0, KEY_READ, &hKey); 
	if(lError == ERROR_SUCCESS) {
		RegQueryValueEx(hKey, "~MH", NULL, &type, (LPBYTE) &dwMHz, &BufSize); 
	} 
	return dwMHz; 
}

bool IsOnlyInstance(LPCTSTR gameTitle) {
	HANDLE handle = CreateMutex(NULL, TRUE, gameTitle);
	if (GetLastError() != ERROR_SUCCESS) {
		HWND hWnd = FindWindow(gameTitle, NULL);
		if (hWnd) {
			// An instance of your game is already running.
			ShowWindow(hWnd, SW_SHOWNORMAL);
			SetFocus(hWnd);
			SetForegroundWindow(hWnd);
			SetActiveWindow(hWnd);
			return false;
		}
	}
	return true;
}
