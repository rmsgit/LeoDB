#include <iostream>
#include <winsock2.h>
#include <string.h>



#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"

#include "file_handle.c"
#include "lang/lang.cpp"


using namespace std;
using namespace rapidjson;

int main()
{
    WSADATA WSAData;

    SOCKET server, client;

    SOCKADDR_IN serverAddr, clientAddr;

    WSAStartup(MAKEWORD(2,0), &WSAData);
    server = socket(AF_INET, SOCK_STREAM, 0);

    serverAddr.sin_addr.s_addr = INADDR_ANY;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(5555);

    bind(server, (SOCKADDR *)&serverAddr, sizeof(serverAddr));
    listen(server, 0);

    cout << "Welcome LeoDB Version 1.0.." << endl;


   // string buffer;
    int clientAddrSize = sizeof(clientAddr);
    if((client = accept(server, (SOCKADDR *)&clientAddr, &clientAddrSize)) != INVALID_SOCKET)
    {
        cout << "Client connected!" << endl;

       while(true){
           char buffer[1024 * 1024] = "";
            recv(client, buffer, sizeof(buffer), 0);

            if(strncmp(buffer, "", 1) != 0 ){
               cout << "Client says: " << buffer << endl;
               Lang lang(buffer);

                char *gpName;

                //lang.getGraphName(gpName);
                if(lang.isVaildPattern()){
                    cout << "Graph  : " << lang.getGraphName() << endl;
                    cout << "Action : " << lang.getAction() << endl;
                    cout << "Data   : " << lang.getData() << endl;
                } else{
                    cout << "Invalid Input" << endl;
                }



//
//
//               Document d;
//               d.Parse(buffer);
//
//
//                Value &gpName = d["graph"];
//                Value &gpData = d["data"];
//
//                StringBuffer stBuffer;
//                Writer<StringBuffer> writer(stBuffer);
//                d.Accept(writer);
//


//                char sm[16];
//                char *data;
//
//
//                strcpy(sm, gpName.GetString());
//                strcpy(data, gpData.GetString());
//
//
//                writeFile("test.ext", data);
//                cout << "Sent : " << sm << endl;
//                int BytesSent = send(client, sm , sizeof(sm), 0);
//
//                char *dataFromFile;
//                readFile("test.ext", dataFromFile);
//                cout << "From File:" << dataFromFile << endl;




//                if(BytesSent == SOCKET_ERROR) cout << "Error to send" << WSAGetLastError() << endl;
//                strcpy(buffer, "");


               memset(buffer, sizeof(buffer), 0);

            }

        }
        closesocket(client);
        cout << "Client disconnected." << endl;
    }
}
