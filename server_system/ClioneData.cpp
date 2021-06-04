//
// Created by TongdaYang on 2021/4/24.
//

#include "ClioneData.h"
#include <iostream>
#include <fstream>

using namespace std;

int message::newmessage(std::string rev_ms) {
    int star = 0;
    int i = 0;
    while(i < rev_ms.size())
    {
        if(rev_ms[i] == ';')
        {
            type = rev_ms.substr(star, i - star);
            i++;
            star = i;
            break;
        }
        i++;
    }
    while(i < rev_ms.size())
    {
        if(rev_ms[i] == ';')
        {
            ori_id = rev_ms.substr(star, i - star);
            i++;
            star = i;
            break;
        }
        i++;
    }
    while(i < rev_ms.size())
    {
        if(rev_ms[i] == ';')
        {
            des_id = rev_ms.substr(star, i - star);
            i++;
            star = i;
            break;
        }
        i++;
    }
    while(i < rev_ms.size())
    {
        if(rev_ms[i] == ';')
        {
            ms = rev_ms.substr(star, i - star);
            break;
        }
        i++;
    }

    return 0;
}

ClioneData::ClioneData(std::string data_path) {
    ifstream in;
    in.open(data_path, ios::in);
    path = data_path;

    string clien_info_from_file;
    while(in >> clien_info_from_file)
    {
        string frnds_info_from_file;
        in >> frnds_info_from_file;
        client_info client(clien_info_from_file, frnds_info_from_file);
        clients.push_back(client);
    }

    in.close();
}

int ClioneData::find_client(string idname) {
    for(int i = 0; i < clients.size(); i++)
    {
        if(clients[i].id == idname)
            return i;
    }
    return -1;
}

int ClioneData::login(std::string &id, std::string &password, SOCKET &client){
    int iresult;
    iresult = this->find_client(id);
    if(iresult == -1)
    {
        return -1;
    }
    else
    {
        string depassword = clients[iresult].password;
        if(depassword == password) {
            clients[iresult].flag = true;
            clients[iresult].tosocket = client;
            return 1;
        }
    }

    return 0;
}

ClioneData::~ClioneData() {
//    ofstream out;
//    out.open(path, ios::out);
//
//    for(int i = 0; i < clients.size(); i++)
//    {
//        out << clients[i].id << ";" << clients[i].password << endl;
//    }
//
//    out.close();
}

ClioneData::ClioneData() {}

int ClioneData::init(std::string data_path) {
    ifstream in;
    in.open(data_path, ios::in);
    if(!in)
    {
        cout << "Failed to open the file" << endl;
        return 1;
    }
    path = data_path;

    string clien_info_from_file = "";
    while(in >> clien_info_from_file)
    {
        string frnds_info_from_file;
        in >> frnds_info_from_file;
        client_info client(clien_info_from_file, frnds_info_from_file);
        clients.push_back(client);
        clien_info_from_file = "";
    }

    in.close();

    return 0;
}

int ClioneData::logout(string &id) {
    int iresult;
    iresult = this->find_client(id);
    if(iresult == -1)
    {
        return -1;
    }
    else
    {
        clients[iresult].flag = false;
        clients[iresult].tosocket = INVALID_SOCKET;
    }

    return 0;
}

int ClioneData::sendfrnds(string &id) {
    int n = this->find_client(id);
    if(n == -1)
        return -1;

    for(int i = 0; i < clients[n].frnds.size(); i++)
    {
        int frnd = this->find_client(clients[n].frnds[i]);
        if(frnd == -1)
            return -1;
        if(clients[frnd].flag)
        {
            string nwmss = "2;";
            nwmss += clients[n].frnds[i] + ";0;1;";
            send(clients[n].tosocket, (char *)nwmss.data(), nwmss.size(), 0);
            cout << "send :" << nwmss << endl;

            nwmss = "2;" + id + ";0;1;";
            send(clients[frnd].tosocket, (char *)nwmss.data(), nwmss.size(), 0);
            cout << "send :" << nwmss << endl;
        }
    }
    return 0;
}

int ClioneData::waitack(SOCKET client) {
    int iResult;
    int recvbuflen = 512;
    while(1)
    {
        message mss;
        char recvbuf[recvbuflen];
        string recvms;
        iResult = recv(client, recvbuf, recvbuflen, 0);
        if (iResult > 0) {
            recvms = recvbuf;
            cout << "receive : " << recvms << endl;
            mss.newmessage(recvms);
            if(mss.type == "3")
            {
                cout << "confine" << endl;
                break;
            }
            else
            {
                continue;
            }
        } else if (iResult == 0) {
            printf("Connection closing...\n");
            return 1;
        }
        else {
            printf("recv failed: %d\n", WSAGetLastError());
            return 1;
        }
    }

    return 0;
}

int ClioneData::msstransform(message mss) {
    int n = this->find_client(mss.des_id);
    cout << "n : " << n << endl;
    if(n == -1)
        return -1;

    string nwmss = "1;";
    nwmss += mss.ori_id + ";";
    nwmss += mss.des_id + ";";
    nwmss += mss.ms + ";";
    send(clients[n].tosocket, (char *)nwmss.data(), nwmss.size(), 0);
    cout << nwmss.data() << endl;
    return 0;
}