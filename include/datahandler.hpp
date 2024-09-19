/* █████████████████████████████████████████████████████████████████████████████████████████████████████████████ */
/* █▌                                                                                                         ▐█ */
/* █▌     ██████╗  █████╗ ████████╗ █████╗     ██╗  ██╗ █████╗ ███╗   ██╗██████╗ ██╗     ███████╗██████╗      ▐█ */
/* █▌     ██╔══██╗██╔══██╗╚══██╔══╝██╔══██╗    ██║  ██║██╔══██╗████╗  ██║██╔══██╗██║     ██╔════╝██╔══██╗     ▐█ */
/* █▌     ██║  ██║███████║   ██║   ███████║    ███████║███████║██╔██╗ ██║██║  ██║██║     █████╗  ██████╔╝     ▐█ */
/* █▌     ██║  ██║██╔══██║   ██║   ██╔══██║    ██╔══██║██╔══██║██║╚██╗██║██║  ██║██║     ██╔══╝  ██╔══██╗     ▐█ */
/* █▌     ██████╔╝██║  ██║   ██║   ██║  ██║    ██║  ██║██║  ██║██║ ╚████║██████╔╝███████╗███████╗██║  ██║     ▐█ */
/* █▌     ╚═════╝ ╚═╝  ╚═╝   ╚═╝   ╚═╝  ╚═╝    ╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═══╝╚═════╝ ╚══════╝╚══════╝╚═╝  ╚═╝     ▐█ */
/* █▌                                                                                                         ▐█ */
/* █████████████████████████████████████████████████████████████████████████████████████████████████████████████ */

#ifndef INCLUDE_DATA_HANDLER_HPP
#define INCLUDE_DATA_HANDLER_HPP

#include <nlohmann/json.hpp>
#include <curl/curl.h>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <filesystem>

// ========================================================== API ONLINE COMMUNICATIONS ==========================================================

#ifdef _WIN32
    #define folderDelimiter "\\"
#else
    #define folderDelimiter "/"
#endif

const std::string baseURL = "https://www.alphavantage.co/query?";
const std::string baseFilePath = "data";
const std::string functionURL = "function=";
const std::string symbolURL = "&symbol=";
const std::string apikeyURL = "&apikey=";
const std::string apiKeyPath = "data" + std::string(folderDelimiter) + ".apikey";

const std::string mergeURL(const std::string&, const std::string&, const std::string&, const std::string&);
const std::string mergeFolderPath(const std::string&, const std::string&);

const std::string readApiKey(const std::string&);

bool makeDirectory(const std::string&);
size_t writeCallback(void*, size_t, size_t, void*);

#endif
