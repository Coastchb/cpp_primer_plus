/**
 * Created by coast on 2019/3/22
 */


// process Chinese characters

#include <iostream>
#include <regex>
//#include <tchar.h> //_T
using namespace std;


int main()
{
  /*string s0 = "学正楼";
  cout << s0[0] ;
  cout << s0[1] << endl;
*/

  //wcout.imbue(locale("chs", locale::ctype));  //据说有平台问题
  //wstring s1 = L"学正楼";
  //wcout << s1[0];

  std::locale loc("");
  std::wcout.imbue(loc);

  std::wstring text(L"我的IP地址是:109.168.0.1.");
  std::wstring newIP(L"127.0.0.1");
  std::wstring regString(L"(\\d+)\\.(\\d+)\\.(\\d+)\\.(\\d+)");

  // 表达式选项 - 忽略大小写
  std::regex_constants::syntax_option_type fl = std::regex_constants::icase;

  // 编译一个正则表达式语句
  std::wregex regExpress(regString, fl);

  // 保存查找的结果
  std::wsmatch ms;

  // 判断是否全行匹配
  if (std::regex_match(text, ms, regExpress))
  {
    std::wcout << L"正则表达式:" << regString << L"匹配:" << text << L"成功." << std::endl;
  }
  else
  {
    std::wcout << L"正则表达式:" << regString << L"匹配:" << text << L"失败." << std::endl;
  }

  // 查找
  if (std::regex_search(text, ms, regExpress))
  {
    std::wcout << L"正则表达式:" << regString << L"查找:" << text << L"成功." << std::endl;
    for (size_t i = 0; i < ms.size(); ++i)
    {
      std::wcout << L"第" << i << L"个结果:\"" << ms.str(i) << L"\" - ";
      std::wcout <<L"起始位置:" << ms.position(i) << L"长度" << ms.length(i) << std::endl;
    }
    std::wcout << std::endl;

    // 替换1
    text = text.replace(ms[0].first, ms[0].second, newIP);
    std::wcout << L"替换1后的文本:" << text << std::endl;
  }
  else
  {
    std::wcout << L"正则表达式:" << regString << L"查找:" << text << L"失败." << std::endl;
  }

  // 替换2
  newIP = L"255.255.0.0";
  std::wstring newText = std::regex_replace(text, regExpress, newIP);
  std::wcout << L"替换2后的文本:" << newText << std::endl;

  // 结束
  std::wcout << L"按回车键结束...";
  std::wcin.get();
  return 0;


  getchar();
  return 0;
}