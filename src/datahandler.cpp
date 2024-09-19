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

const std::string readApiKey(const std::string& filePath)
{
    std::ifstream file(filePath);
    if(!file.is_open())
    {
        std::cerr << "READ_API_KEY ERROR: Could not open API KEY file at \"" << filePath << "\"" << std::endl; 
        return "";
    }
    std::stringstream buffer;
    buffer << file.rdbuf();
    file.close();
    return buffer.str();
}