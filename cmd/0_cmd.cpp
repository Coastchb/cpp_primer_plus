/**
 * Created by coast on 2019/3/22
 */
#include <iostream>
#include <string>
#include <stdlib.h>
#include <regex>
#include <vector>
using namespace std;

// 1: execute the system command and get the returns
// 2: extract the expected values from string

int execmd(const char* cmd,char* result) {
  char buffer[256];                         //定义缓冲区
  FILE* pipe = popen(cmd, "r");            //打开管道，并执行命令
  if (!pipe)
    return 0;                      //返回0表示运行失败

  while(!feof(pipe)) {
    if(fgets(buffer, 256, pipe)){             //将管道输出到result中
      //cout << "buff:" << buffer << endl;
      strcat(result,buffer);
    }
  }
  pclose(pipe);                            //关闭管道
  return 1;                                 //返回1表示运行成功
}

int extract(char src_str[]) {
  smatch result;
  //regex pattern("\\w+\\^([A-Za-z]+-([A-Za-z]+)\\+[A-Za-z]+).*");
  regex pattern("\"([^,:]+)\"");

  string str = src_str;
  cout << str << endl;

  //string* tmp_str = new string[1];
  vector<string> all_vec;
  int count = 0;
  while (regex_search(str, result, pattern))
  {
    //for(auto x: result) cout << x << endl;
    cout << result[1] << endl;
    //*(tmp_str + count) = "a"; //result[1];
    all_vec.push_back(result[1]);
    count += 1;
    str = result.suffix().str();
  }

  cout << "extraction finished, extracted num:" << count << endl;


  vector<string> ret;
  if(count % 2 != 0){
    cout << "invalid count:" << count << endl;
    exit(1);
  }

  for (int i = 1; i < count/2; i++) {
    //cout << all_vec.at(i) << "\t" << all_vec.at(i+count/2) << endl;
    ret.push_back(all_vec.at(i) + "\t" + all_vec.at(i+count/2));
  }

  for (auto t: ret) {
    cout << t << endl;
  }


  return 0;
}


int main(){
  string keys = "2DgGSC-8.33497.8yeNchBP6L9n";
  string sentence = "人民法院案件受理制度改革，下月起法院将有案必立";
  string command = "curl -X POST \\\n"
                   "     -H \"Content-Type: application/json\" \\\n"
                   "     -H \"Accept: application/json\" \\\n"
                   "     -H \"X-Token: " + keys + "\" \\\n"
                   "     --data \"\\\"" + sentence + "\\\"\" \\\n"
                   "     'http://api.bosonnlp.com/tag/analysis?space_mode=0&oov_level=3&t2s=0' 1>&1";

  //system("echo ok");
  //auto ret = system(("echo `" + command + "`").c_str());
  //auto ret = system(command.c_str());

  char result[2048*4]="";                   //定义存放结果的字符串数组
  if(1==execmd(command.c_str(), result)){
    cout << string(result).size() << endl;
    cout << "result:" << result << endl;
  }

  //string result = "[{\"word\":[\"人民法院\",\"案件\"],\"tag\":[\"nl\",\"n\"]}]";
  cout << "result:" << result << endl;

  // now we extract the content
  extract(result);
}