//
// Created by coastcao(操海兵) on 2019-08-07.
//

#include <iostream>
#include "tinyxml2.h"

using namespace tinyxml2;
using namespace std;

bool example_1()
{
    static const char* xml =
            "<information>"
            "	<attributeApproach v='2' />"
            "	<textApproach>"
            "		<v>2</v>"
            "	</textApproach>"
            "</information>";

    XMLDocument doc;
    doc.Parse( xml );

    int v0 = 0;
    int v1 = 0;

    XMLElement* attributeApproachElement = doc.FirstChildElement()->FirstChildElement( "attributeApproach" );
    attributeApproachElement->QueryIntAttribute( "v", &v0 );

    XMLElement* textApproachElement = doc.FirstChildElement()->FirstChildElement( "textApproach" );
    textApproachElement->FirstChildElement( "v" )->QueryIntText( &v1 );

    printf( "Both values are the same: %d and %d\n", v0, v1 );

    return !doc.Error() && ( v0 == v1 );
}

bool example_2()
{
    static const char* xml =
            "<speak>"
            "这个是 <say-as interpret-as='characters'>SSML</say-as> 样例。"
            "我可以停顿三秒 <break time='3s'/>。"
            "<prosody rate='slow' pitch='-2st'>我可以慢慢说。</prosody>"
            "我可以说数字，您的号码为：<say-as interpret-as='cardinal'>10</say-as>."
            "或者我可以说序号。您处于 <say-as interpret-as='ordinal'>10</say-as> 号位。"
            "我可以替换短语，比如： <sub alias='World Wide Web Consortium'>W3C</sub>."
            "我可以说一个含有两个句子的段落："
            "<p><s>这是第一句；</s><s>而这是第二句。</s></p>"
            "最后，我们有请Pony说两句。<voice name='Pony'>谢谢，加油！</voice>"
            "</speak>"
            ;
    cout << "raw xml test:" << xml << endl << endl;

    XMLDocument doc;
    doc.Parse( xml );

    int v0 = 0;
    int v1 = 0;

    cout << "access the root element\n";
    XMLElement* root_ele = doc.FirstChildElement();
    cout << "root element:" << root_ele << "\tname:" << root_ele->Name()  << endl;

    if(root_ele->GetText())
        cout << "root content:" << root_ele->GetText() << endl << endl;
    else
        cout << "no text in root element\n";

    cout << "access all the child elements of root element\n";
    for(auto child = root_ele->FirstChildElement(); child; child=child->NextSiblingElement()){
        cout << "--" << child->Name() << endl; // << ":" << child->GetText() << endl;
    }
    cout << endl;

    cout << "access all the children of root element\n";
    for(auto child = root_ele->FirstChild(); child; child=child->NextSibling()){
        auto text = child->ToText();
        if(text != NULL)
            cout << "--"  << text << ":" << child->ToText()->Value() << endl; // << ":" << child->GetText() << endl;
        else
            cout << "--an element,name:" << child->ToElement()->Name() << "\n";
    }
    cout << endl;

    const char* first_say_as = "";
    root_ele->FirstChildElement( "say-as" )->QueryStringAttribute("interpret-as", &first_say_as);
    cout << "first say-as:" << first_say_as << endl << endl;

    return !doc.Error() && ( v0 == v1 );
}

int main(){
    if( example_2()){
        cout << "example_2 passed\n";
    } else {
        cout << "example_2 failed\n";
    }
}