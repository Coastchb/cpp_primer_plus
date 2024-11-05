#include "rapidjson-master/include/rapidjson/rapidjson.h"
#include "rapidjson-master/include/rapidjson/filereadstream.h"
#include "rapidjson-master/include/rapidjson/document.h"
#include <string>
#include <iostream>

using namespace std;

const int BUFFER_SIZE = 65536;
rapidjson::Document g_SpeakConfigJson;

int main() {
    string cfgPath("/Users/coastcao/projects/RS_DL/NS_config_DSSM_v1_1.py");
	FILE* pFile = fopen(cfgPath.c_str(), "rb");
	if (pFile == NULL) {
		std::cerr << "ERROR:OpenFileFailed:"<<cfgPath<<":"<<strerror(errno)<< endl;
		return -3;
	}
    
    char buffer[BUFFER_SIZE] = {0};

	rapidjson::FileReadStream confS(pFile, buffer, sizeof(buffer));
    g_SpeakConfigJson.ParseStream(confS);
	if (g_SpeakConfigJson.HasParseError()) {
		std::cerr <<"ERROR:ParseJsonFileFailed:"<<g_SpeakConfigJson.GetErrorOffset()
				  // <<":"<<rapidjson::GetParseError_En(g_SpeakConfigJson.GetParseError())<< endl;
				  <<":"<<g_SpeakConfigJson.GetParseError()<< endl;
		return -4;
	}
    fclose(pFile);
	if (!g_SpeakConfigJson.IsObject()) {
		std::cerr <<"ERROR:JsonFileNotObject"<< endl;
		return -5;
    }
    
    cout << g_SpeakConfigJson["model_feature"].GetString() << endl;
    return 0;
}
