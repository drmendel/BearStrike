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

#include <datahandler.hpp>

const std::string mergeURL(const std::string& function = "", const std::string& symbol = "", const std::string& apiKey = "", const std::string& extraOptions = "")
{
    std::string error = "";
    std::string andExtraOptions = extraOptions;
    if(function.empty()) error += "MERGE_URL ERROR: No function\n";
    if(symbol.empty()) error += "MERGE_URL ERROR: No symbol\n";
    if(apiKey.empty()) error += "MERGE_URL ERROR: No apiKey\n";
    if(!extraOptions.empty()) andExtraOptions.insert(0, "&");
    if(!error.empty()) {
        std::cerr << error;
        return "";
    } 
    return baseURL + functionURL + function + symbolURL + symbol + apikeyURL + apiKey + andExtraOptions;
}

const std::string mergeFolderPath(const std::string& dataType = "", const std::string& symbol = "")
{
    std::string error = "";
    if(dataType.empty()) error += "MERGE_FILEPATH ERROR: No dataType\n";
    if(symbol.empty()) error += "MERGE_FILEPATH ERROR: No symbol\n";
    if(!error.empty()) {
        std::cerr << error;
        return "";
    }
    return baseFilePath + folderDelimiter + dataType + folderDelimiter + symbol;
}