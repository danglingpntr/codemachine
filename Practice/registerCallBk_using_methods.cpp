#include <iostream>
using namespace std;

std::string buildCompleteMessage(std::string rawData, std::string (* encrypterFunPtr)(std::string) )
{
    // Add some header and footer to data to make it complete message
    rawData = "[abc]" + rawData + "[def]";
    // Call the callBack provided i.e. function pointer to encrypt the
    return encrypterFunPtr(rawData);
}

std::string encryptDataByLetterInc(std::string data)
{
    for(int i = 0; i < data.size(); i++)
    {
        if( (data[i] >= 'a' && data[i] <= 'z' ) || (data[i] >= 'A' && data[i] <= 'Z' ) )
            data[i]++;
    }
    return data;
}

std::string encryptDataByLetterDec(std::string data)
{
    for(int i = 0; i < data.size(); i++)
    {
        if( (data[i] >= 'a' && data[i] <= 'z' ) || (data[i] >= 'A' && data[i] <= 'Z' ) )
            data[i]--;
    }
    return data;
}

int main()
{
    std::string msg = buildCompleteMessage("wxy", &encryptDataByLetterInc);
    std::cout << msg << std::endl;
    msg = buildCompleteMessage("ijk", &encryptDataByLetterDec);
    std::cout << msg << std::endl;
    return 0;
}