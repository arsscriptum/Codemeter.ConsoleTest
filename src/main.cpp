
//==============================================================================
//
//     main.cpp
//
//============================================================================
//  guillaume plante <guillaume.plante@luminator.com>
//==============================================================================



#include "stdafx.h"

#include "cmdline.h"
#include "Shlwapi.h"
#include "log.h"
#include <codecvt>
#include <locale>
#include <vector>
#include <unordered_map>
#include <iterator>
#include <regex>
#include <filesystem>
#include <iostream>
#include <sstream>


using namespace std;

#pragma message( "Compiling " __FILE__ )
#pragma message( "Last modified on " __TIMESTAMP__ )

void banner();
void usage();
int start_httpd();

int main(int argc, TCHAR** argv, TCHAR envp)
{

#ifdef UNICODE
	const char** argn = (const char**)C::Convert::allocate_argn(argc, argv);
#else
	char** argn = argv;
#endif // UNICODE

	CmdLineUtil::getInstance()->initializeCmdlineParser(argc, argn);

	CmdlineParser* inputParser = CmdLineUtil::getInstance()->getInputParser();

	CmdlineOption cmdlineOptionHelp({ "-h", "--help" }, "display this help");
	CmdlineOption cmdlineOptionVerbose({ "-v", "--verbose" }, "verbose output");
	CmdlineOption cmdlineOptionPath({ "-p", "--path" }, "path");
	CmdlineOption cmdlineOptionNoBanner({ "-n", "--nobanner" }, "no banner");
	CmdlineOption cmdlineOptionWhatIf({ "-w", "--whatif" }, "whatif");

	inputParser->addOption(cmdlineOptionHelp);
	inputParser->addOption(cmdlineOptionVerbose);
	
	inputParser->addOption(cmdlineOptionNoBanner); 
	inputParser->addOption(cmdlineOptionWhatIf); 
	inputParser->addOption(cmdlineOptionPath); 


	bool optHelp = inputParser->isSet(cmdlineOptionHelp);
	bool optVerbose = inputParser->isSet(cmdlineOptionVerbose);
	bool optPath= inputParser->isSet(cmdlineOptionPath);
	bool optNoBanner = inputParser->isSet(cmdlineOptionNoBanner);
	bool optWhatIf = inputParser->isSet(cmdlineOptionWhatIf);
	if(optNoBanner == false){
		banner();
	}
	if(optHelp){
		usage();
		return 0;
	}

	COUTC("===============================================");
	COUTC("                  START HTTPD                  ");
	COUTC("===============================================");

	start_httpd();
	return 0;
}


int start_httpd() {
    // Define the path to the executable and the working directory
    const char* exePath = "C:\\Programs\\xampp\\apache\\bin\\httpd.exe";
    const char* workingDir = "C:\\Programs\\xampp";

    // Define the process and startup info structures
    STARTUPINFO si;
    PROCESS_INFORMATION pi;

    // Initialize the memory for the structures
    ZeroMemory(&si, sizeof(si));
    si.cb = sizeof(si);
    ZeroMemory(&pi, sizeof(pi));

    // Create the process
    if (!CreateProcess(
        exePath,      // Path to the executable
        NULL,         // Command line arguments
        NULL,         // Process handle not inheritable
        NULL,         // Thread handle not inheritable
        FALSE,        // Set handle inheritance to FALSE
        0,            // No creation flags
        NULL,         // Use parent's environment block
        workingDir,   // Set working directory
        &si,          // Pointer to STARTUPINFO structure
        &pi)          // Pointer to PROCESS_INFORMATION structure
    ) {
        std::cerr << "CreateProcess failed (" << GetLastError() << ").\n";
        return 1;
    }

    // Wait until the process exits
    WaitForSingleObject(pi.hProcess, INFINITE);

    // Close process and thread handles
    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);

    return 0;
}

void banner() {
	std::wcout << std::endl;
	COUTC("apache_start v2.1 - apache server laucher\n");
	COUTC("Built on %s\n", __TIMESTAMP__);
	COUTC("Copyright (C) 2000-2021 Guillaume Plante\n");
	std::wcout << std::endl;
}
void usage() {
	COUTCS("Usage: ctest [-h][-v][-n][-p] path \n");
	COUTCS("   -v          Verbose mode\n");
	COUTCS("   -h          Help\n");
	COUTCSNR("   -w          WhatIf: no actions, get url, test connection.");
	COUTY("  No downloads");
	COUTCS("   -n          No banner\n");
	COUTCS("   -p path     Destination path\n");
	std::wcout << std::endl;
}

