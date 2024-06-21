
//==============================================================================
//
//   log.h - exported_h
//
//==============================================================================
//  guillaume plante <guillaume.plante@luminator.com>
//==============================================================================

#ifndef __CODEMETERCLIENT_H__
#define __CODEMETERCLIENT_H__

#include <mutex>

#include "CodeMeter.h"


class CodemeterClient {
public:
    // Function to get the singleton instance
    static CodemeterClient& getInstance();

    // Delete copy constructor and assignment operator to prevent copies
    CodemeterClient(CodemeterClient const&) = delete;
    void operator=(CodemeterClient const&) = delete;

    // Function to initialize the client
    bool Initialize();

    // Function to destroy the client
    void Destroy();

    // Function to execute tests
    void ValidateClient();

private:
    // Private constructor
    CodemeterClient();

    bool initialized;
    std::mutex mutex_;

    CMACCESS cmAcc;
};

#endif // __CODEMETERCLIENT_H__
