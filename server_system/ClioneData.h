//
// Created by TongdaYang on 2021/4/24.
//

#ifndef SERVER_SYSTEM_CLIONEDATA_H
#define SERVER_SYSTEM_CLIONEDATA_H
#include <string>
#include <winsock2.h>
#include <windows.h>
#include <ws2tcpip.h>
#include <stdlib.h>
#include <stdio.h>
#include <vector>


class message{
public:
    /* Message type | 0 for login | 1 for communicate | 2 for send friends data | 3 for ack*/
    std::string type;
    std::string ori_id;
    std::string des_id;
    std::string ms;
    message()
    {
        type = "";
        ori_id = "";
        des_id = "";
        ms = "";
    }
    int newmessage(std::string rev_ms);
    ~message(){}

};
class client_info{
public:
    std::string id;
    std::string password;
    bool flag;
    SOCKET tosocket;
    std::vector<std::string> frnds;

    client_info(std::string clien_info_from_file, std::string frnds_info_from_file)
    {
        /* ID and PassWord Data*/
        int star = 0;
        int i = 0;
        while(i < clien_info_from_file.size())
        {
            if(clien_info_from_file[i] == ';')
            {
                id = clien_info_from_file.substr(star, i - star);
                i++;
                star = i;
                break;
            }
            i++;
        }
        password = clien_info_from_file.substr(star, clien_info_from_file.size() - star);
        /* Friends Data*/
        star = 0;
        i = 0;
        while(i < frnds_info_from_file.size())
        {
            if(frnds_info_from_file[i] == ';')
            {
                frnds.push_back(frnds_info_from_file.substr(star, i - star));
                i++;
                star = i;
                continue;
            }
            i++;
        }
        /* Online state*/
        flag = false;
        /* Connection sockeet*/
        tosocket = INVALID_SOCKET;
    }
    client_info()
    {
        tosocket = INVALID_SOCKET;
        id = "";
    }
};
class ClioneData {
private:
    std::vector<client_info> clients;
    std::string path;
public:
    ClioneData(std::string data_path);
    ClioneData();
    int init(std::string data_path);
    int find_client(std::string idname);
    int login(std::string &id, std::string &password, SOCKET &client);
    int logout(std::string &id);
    int sendfrnds(std::string &id);
    int waitack(SOCKET client);
    int msstransform(message mss);
    ~ClioneData();
};


#endif //SERVER_SYSTEM_CLIONEDATA_H
