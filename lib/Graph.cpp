//
// Created by Ruwan on 6/23/2017.
//

#include <iostream>

#include "rapidjson/document.h"
#include "rapidjson/pointer.h"

using namespace rapidjson;
using namespace std;

class Obj{
    int index;
    string data;
    Obj(int index, string data){
        this->index = index;
        this->data  = data;
    }
};
class Axis{
    Obj objects[];
    int index;
    string name;
};

class Graph{
    Axis axis[];
    string name;
    Document document;
    Graph(){

    }
    void save(string json, string fileName){

    }
    bool isError(){

    }
};

Graph test();

test/

