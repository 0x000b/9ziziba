#include<windows.h>
#include<cstdint>
#include<stdio.h>

// For URLDownloadToFile
#include <urlmon.h>
#pragma comment(lib, "urlmon.lib")

// For filesystem operations
#include<filesystem>*
//#include<fstream>

#define N3ass Sleep(30000);
#define Url L"https://cdn.discordapp.com/attachments/773595180108480566/1123741562531225661/video0.mp4?ex=68f0c8a2&is=68ef7722&hm=981deff8b4ca39143733a0ee86ec89032326f37ae79f0bf1fced531f62938f45&"
#define WIDTH 7 // For formatting output
#define DIV 1024 // To convert bytes to KB
#define MAX_PATH 1024 // Maximum path length



void DownloadFile(void)
{
	WCHAR theBlobURL[] = Url;
	WCHAR outfilename[] = L"downloaded_file.mp4";
	HRESULT hr = URLDownloadToFile(NULL, theBlobURL, outfilename, 0, NULL);
}
void OpenFile(void) {
	ShellExecuteA(0, "open", "downloaded_file.mp4", 0, 0, SW_SHOWNORMAL);

}

int main() {
	
	MEMORYSTATUSEX statex;
	
	statex.dwLength = sizeof(statex);	
	WCHAR filename[] = L"downloaded_file.mp4";


	while (true) {
		GlobalMemoryStatusEx(&statex);
		if (statex.dwMemoryLoad > 80) {
			if (std::filesystem::exists(L"downloaded_file.mp4"))
			{
				OpenFile();
				N3ass;	
			}
			else {
				DownloadFile();
				OpenFile();
				N3ass;
			}; 
		}
		else {
			Sleep(10000); // Sleep for 3 seconds
		}
	};
	

	return 0;
}