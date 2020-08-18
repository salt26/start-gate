#include <windows.h>
#include <iostream>
#include <cstdlib>
#include <strsafe.h>

LONG GetDWORDRegKey(HKEY hKey, const std::wstring &strValueName, DWORD &nValue, DWORD nDefaultValue)
{
    nValue = nDefaultValue;
    DWORD dwBufferSize(sizeof(DWORD));
    DWORD nResult(0);
    LONG nError = ::RegQueryValueExW(hKey,
        strValueName.c_str(),
        0,
        NULL,
        reinterpret_cast<LPBYTE>(&nResult),
        &dwBufferSize);
    if (ERROR_SUCCESS == nError)
    {
        nValue = nResult;
    }
    return nError;
}


LONG GetBoolRegKey(HKEY hKey, const std::wstring &strValueName, bool &bValue, bool bDefaultValue)
{
    DWORD nDefValue((bDefaultValue) ? 1 : 0);
    DWORD nResult(nDefValue);
    LONG nError = GetDWORDRegKey(hKey, strValueName.c_str(), nResult, nDefValue);
    if (ERROR_SUCCESS == nError)
    {
        bValue = (nResult != 0) ? true : false;
    }
    return nError;
}


LONG GetStringRegKey(HKEY hKey, const std::wstring &strValueName, std::wstring &strValue, const std::wstring &strDefaultValue)
{
    strValue = strDefaultValue;
    WCHAR szBuffer[512];
    DWORD dwBufferSize = sizeof(szBuffer);
    ULONG nError;
    nError = RegQueryValueExW(hKey, strValueName.c_str(), 0, NULL, (LPBYTE)szBuffer, &dwBufferSize);
    if (ERROR_SUCCESS == nError)
    {
        strValue = szBuffer;
    }
    return nError;
}

int main() {
	HKEY hKey;
	LONG lRes = RegOpenKeyExW(HKEY_LOCAL_MACHINE, L"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run", 0, KEY_ALL_ACCESS, &hKey);
	bool bExistsAndSuccess (lRes == ERROR_SUCCESS);
	bool bDoesNotExistsSpecifically (lRes == ERROR_FILE_NOT_FOUND);
	std::wstring strValueOfBinDir;
	std::wstring strKeyDefaultValue;
	LONG l = GetStringRegKey(hKey, L"StartGate", strValueOfBinDir, L"bad");
	GetStringRegKey(hKey, L"", strKeyDefaultValue, L"bad");
	std::cout<<l<<" ";
	if (l == 0)	std::wcout<<strValueOfBinDir;
	std::cout<<std::endl;
	if (l == 0 || l == 2) {
	    WCHAR buffer[MAX_PATH * 4];
		GetCurrentDirectoryW(MAX_PATH * 4, buffer);
		int i;
		for (i = 0; i < MAX_PATH * 4 - 1; i++) {
			if (buffer[i] == '\0') break;
		}
		if (i > 0 && buffer[i-1] != '\\') {
			buffer[i] = '\\';
			buffer[i+1] = '\0';
		}
		StringCchCatW(buffer, MAX_PATH * 4, L"StartGate.exe");
		std::wcout<<buffer<<std::endl;
		LPCWSTR value = TEXT(L"StartGate");
		LPCWSTR data = buffer;
		std::wcout<<wcslen(data)+1<<std::endl;
		LONG nError = RegSetValueExW(hKey, value, 0, REG_SZ, (LPBYTE)data, (wcslen(data)+1)*sizeof(data));
		if (nError == ERROR_SUCCESS) {
			printf("Success writing to Registry.\n");
		} else {
			printf("Error writing to Registry.\n");
		}
		
	}
	LONG closeOut = RegCloseKey(hKey);
	if (closeOut == ERROR_SUCCESS) {
		printf("Success closing key.\n");
	} else {
		printf("Error closing key.\n");
	}
	system("PAUSE");
	return 0;
}
