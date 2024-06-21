
//==============================================================================
//
//  cm.cpp
//
//==============================================================================
//  guillaume plante <guillaume.plante@luminator.com>
//==============================================================================



#include "stdafx.h"
#include "log.h"
#include "cm.h"

#include <iostream>

// Function to get the singleton instance
CodemeterClient& CodemeterClient::getInstance() {
    static CodemeterClient instance; // Guaranteed to be destroyed and instantiated on first use
    return instance;
}

// Private constructor
CodemeterClient::CodemeterClient() : initialized(false) {
    // Constructor code here
}

// Function to initialize the client
bool CodemeterClient::Initialize() {
    std::lock_guard<std::mutex> lock(mutex_);
    if (!initialized) {
        // Initialization code here
        
        memset(&cmAcc, 0, sizeof(cmAcc));

        cmAcc.mflCtrl |= CM_ACCESS_NOUSERLIMIT;

        HCMSysEntry hcmse = CmAccess(CM_ACCESS_LAN_LOCAL, &cmAcc);

        if (NULL == hcmse) {
            return false;
        }
        
        std::cout << "CodemeterClient initialized." << std::endl;
        initialized = true;
    }
    return initialized;
}

// Function to destroy the client
void CodemeterClient::Destroy() {
    std::lock_guard<std::mutex> lock(mutex_);
    if (initialized) {
        // Cleanup code here
        std::cout << "CodemeterClient destroyed." << std::endl;
        initialized = false;
    }
}

// Function to execute tests
void CodemeterClient::ValidateClient() {
    std::lock_guard<std::mutex> lock(mutex_);
    if (initialized) {
        // Test execution code here
        std::cout << "Executing tests..." << std::endl;
    }
    else {
        std::cout << "CodemeterClient is not initialized." << std::endl;
    }
}
