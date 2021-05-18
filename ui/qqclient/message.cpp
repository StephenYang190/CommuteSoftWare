#include "message.h"

message::message()
{
    type = "";
    ori_id = "";
    des_id = "";
    ms = "";
}

int message::newmessage(std::string rev_ms)
{
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
