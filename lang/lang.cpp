//
// Created by Ruwan on 6/22/2017.
//
#include <string.h>
#include <iostream>

#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"

using namespace rapidjson;
using namespace std;

class Lang{
    Document document;
    string text;
public:
    Lang(string txt){
        //strcpy(text, txt.c_str());
        this->text = txt;
        this->document.Parse(this->text.c_str());
        StringBuffer stBuffer;
        Writer<StringBuffer> writer(stBuffer);
        this->document.Accept(writer);


        cout <<  "construct function gpName: "<< txt << endl;

    };
    bool isVaildPattern(){
        return  !this->document.HasParseError();
    }

    string getGraphName(){
        return get("graph");
    }
    string getAction(){
        return get("action");
    }
    string getData(){
        return get("data");
    }

private:
    string get(string key){
            if(this->document.HasMember(key.c_str())){
                Value& graphName = this->document[key.c_str()];
                string retSt (graphName.GetString());
                return  retSt;
            }else{
                string stNUll ("");
                return stNUll;
            }

            cout << "Passer error" << endl;



        //strcpy(gpName, graphName.GetString());
		//ruwan DDDDD 22


    }

};
