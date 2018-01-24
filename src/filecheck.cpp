#include "filecheck.hpp"




namespace GPEUP {
	
	int FileCheck::md5(const std::string path, std::string & sum) {
#ifdef WIN32
		int res = md5_win(path, sum);
#endif
		return res;
	}

	DWORD FileCheck::md5_win(const std::string path, std::string & sum) {
		DWORD dwStatus = 0;
		BOOL bResult = FALSE;
		HCRYPTPROV hProv = 0;
		HCRYPTHASH hHash = 0;
		HANDLE hFile = NULL;
		BYTE rgbFile[BUFSIZE];
		DWORD cbRead = 0;
		BYTE rgbHash[MD5LEN];
		DWORD cbHash = 0;
		CHAR rgbDigits[] = "0123456789abcdef";
		LPCTSTR filename = path.c_str(); //When unicode is supported, change line to L"text.txt";
		// Logic to check usage goes here.

		hFile = CreateFile(filename,
			GENERIC_READ,
			FILE_SHARE_READ,
			NULL,
			OPEN_EXISTING,
			FILE_FLAG_SEQUENTIAL_SCAN,
			NULL);

		if (INVALID_HANDLE_VALUE == hFile)
		{
			dwStatus = GetLastError();
			printf("Error opening file %s\nError: %d\n", filename,
				dwStatus);
			return dwStatus;
		}

		// Get handle to the crypto provider
		if (!CryptAcquireContext(&hProv,
			NULL,
			NULL,
			PROV_RSA_FULL,
			CRYPT_VERIFYCONTEXT))
		{
			dwStatus = GetLastError();
			printf("CryptAcquireContext failed: %d\n", dwStatus);
			CloseHandle(hFile);
			return dwStatus;
		}

		if (!CryptCreateHash(hProv, CALG_MD5, 0, 0, &hHash))
		{
			dwStatus = GetLastError();
			printf("CryptAcquireContext failed: %d\n", dwStatus);
			CloseHandle(hFile);
			CryptReleaseContext(hProv, 0);
			return dwStatus;
		}

		while (bResult = ReadFile(hFile, rgbFile, BUFSIZE,
			&cbRead, NULL))
		{
			if (0 == cbRead)
			{
				break;
			}

			if (!CryptHashData(hHash, rgbFile, cbRead, 0))
			{
				dwStatus = GetLastError();
				printf("CryptHashData failed: %d\n", dwStatus);
				CryptReleaseContext(hProv, 0);
				CryptDestroyHash(hHash);
				CloseHandle(hFile);
				return dwStatus;
			}
		}

		if (!bResult)
		{
			dwStatus = GetLastError();
			printf("ReadFile failed: %d\n", dwStatus);
			CryptReleaseContext(hProv, 0);
			CryptDestroyHash(hHash);
			CloseHandle(hFile);
			return dwStatus;
		}

		cbHash = MD5LEN;
		if (CryptGetHashParam(hHash, HP_HASHVAL, rgbHash, &cbHash, 0))
		{
			//printf("MD5 hash of file %s is: ", filename);
			std::ostringstream out;
			for (DWORD i = 0; i < cbHash; i++)
			{
				//printf("%c%c", rgbDigits[rgbHash[i] >> 4],
				//	rgbDigits[rgbHash[i] & 0xf]);
				out << rgbDigits[rgbHash[i] >> 4] << rgbDigits[rgbHash[i] & 0xf];
			}
			sum = out.str();
			printf("\n");
		}
		else
		{
			dwStatus = GetLastError();
			printf("CryptGetHashParam failed: %d\n", dwStatus);
		}

		CryptDestroyHash(hHash);
		CryptReleaseContext(hProv, 0);
		CloseHandle(hFile);

		return dwStatus;
	}

	bool checkfile(const std::string path, const std::string knownchecksum) {
		return true;
	}
}