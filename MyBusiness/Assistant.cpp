#include "Assistant.h"
#include "tinyxml/tinystr.h"
#include "tinyxml/tinyxml.h"



#include <iostream>

using namespace std;

void CAssistant::TinyXmlSerialize()
{
    std::string seperator ="\\";
    std::string file = "D:\\Study" + seperator + "test.xml";
    // 文件不存在创建
    TiXmlDocument* myDocument = new TiXmlDocument(file.c_str());
    myDocument->LoadFile();
    TiXmlElement* RootElement = myDocument->RootElement();
    cout << RootElement->Value() << endl;
    TiXmlElement* FirstPerson = RootElement->FirstChildElement();
    TiXmlElement* NameElement = FirstPerson->FirstChildElement();
    TiXmlElement* AgeElement = NameElement->NextSiblingElement();
    TiXmlAttribute* IDAttribute = FirstPerson->FirstAttribute();
    cout << NameElement->FirstChild()->Value() << endl;
    cout << AgeElement->FirstChild()->Value() << endl;
    cout << IDAttribute->Value() << endl;
}
void CAssistant::TinyXmlDeSerialize()
{
    TiXmlDocument* myDocument = new TiXmlDocument();
    TiXmlElement* RootElement = new TiXmlElement("Persons");
    myDocument->LinkEndChild(RootElement);
    TiXmlElement* PersonElement = new TiXmlElement("Person");
    RootElement->LinkEndChild(PersonElement);
    PersonElement->SetAttribute("ID", "1");
    TiXmlElement* NameElement = new TiXmlElement("name");
    TiXmlElement* AgeElement = new TiXmlElement("age");
    PersonElement->LinkEndChild(NameElement);
    PersonElement->LinkEndChild(AgeElement);
    TiXmlText* NameContent = new TiXmlText("诸葛村夫");
    TiXmlText* AgeContent = new TiXmlText("22");
    NameElement->LinkEndChild(NameContent);
    AgeElement->LinkEndChild(AgeContent);

    std::string seperator = "\\";
    std::string fullPath = "D:\\Study" + seperator + "dahuaxiyou.xml";
    myDocument->SaveFile(fullPath.c_str());//保存到文件
	
}

#include <fstream>
#include "jsoncpp/json/json.h"
#pragma warning(disable : 4996)
void CAssistant::JsoncppSerialize()
{
    Json::Reader reader;
    Json::Value root;
    std::string cfilename = "D:\\Study\\test.json";
    std::ifstream in(cfilename,std::ios::binary);
    if (!in.is_open())
    {
        cout << "Error opening file\n";
        return;
        }
    if (reader.parse(in, root))
    {
        if (root.size() == 0)  
            return;
        for (int i = 0; i < (int)root.size(); i++)
        {
            string Dlgname = root[i]["DlgName"].asString();
            int FirstRowHeight = root[i]["FirstRowHeight"].asInt();
            int RowHeight = root[i]["RowHeight"].asInt();
            int ColWidth_size = root[i]["ColWidth"].size();
            cout << Dlgname << " " << endl
                 << FirstRowHeight << " " << endl
                 << RowHeight << " " << endl
                 << ColWidth_size << " " << endl;
        }
    }
    in.close();
}

void CAssistant::JsoncppDeSerialize()
{
    Json::Value root;
    Json::Value NewDlg;
    root.clear();
    for (int i = 0; i < 3; i++) {
        NewDlg["DlgName"] = "lll";
        NewDlg["FirstRowHeight"] = i;
        NewDlg["RowHeight"] = i;
        int ColWidth_size = i;
        NewDlg["ColWidth"] = i;
        root.append(NewDlg);  // 插入数组成员 
    }

    std::string out = root.toStyledString();
    std::ofstream os;
    std::string cfilename = "D:\\Study\\lill.json";
    os.open(cfilename, std::ios::binary);
    os << out;
    os.close();
}
