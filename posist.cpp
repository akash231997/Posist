#include<bits/stdc++.h>
#include <string>
using namespace std;

string key;
int num =1;
struct node{
    string ownname;
    int ownid;
    string timestamp;
    string data;
    int nodeNum;
    string id;
    string refid;
    string childrefid;
    string genesisrefid;
    string hashvalue;
    vector<struct node*> child;
};

string convert(string s, int key)
{
    for(int i=0;i<s.size();i++)
    {
        s[i]=(s[i]+key)%26;

    }
    return s;
}

string makehash(string t, string d,  int nodeNum, string id, string refid, string childrefid, string genesisrefid)
{
     int r=rand()%8461 + 63;
    t=convert(t,r);
    d=convert(d,r);
    id=convert(id,r);
    refid=convert(refid,r);
    childrefid=convert(childrefid,r);
    genesisrefid=convert(genesisrefid,r);

    nodeNum+=r;
    string y="";
    y+=t+d+id+refid+childrefid+genesisrefid+to_string(nodeNum);
    return y;

}

string encrypdata(int ownid, int val, string name)
{

    ownid+=atoi(key);
    val+=atoi(key);
    for(int i=0;i<name.size();i++)
    {
        name[i]=(name[i]+atoi(key))%26;

    }

    return to_string(ownid)+ "#" +to_string(val)+ "#" +name + "#";
}

struct node createnode()
{
    string own;
    int ownid, nodeid, val;
    cout<<"Owner name ";
    cin>>own;
    cout<<"Owner id ";
    cin>>ownid;
   time_t now = time(0);
   char* dt = ctime(&now);
    cout<<"Node id ";
    cin>>nodeid;
    cout<<"Value";
    cin>>val;

    cout<<"Key for encryption ";
    cin>>key;

    struct node* temp=(struct node*)malloc(sizeof(struct node));

    temp->ownname=own;
    temp->ownid=ownid;
    temp->timestamp = dt;
    temp->data=encrypdata(ownid, val, own);
    temp->id=nodeid;
    temp->nodeNum=num;
    temp->refid="";
    temp->childrefid="";
    temp->genesisrefid = to_string(&temp);
    temp->data=hashvalue(dt, temp->data, num, to_string(nodeid), "", "", to_string(&temp));

    num++;
    key="";
    return temp;
}

int main()
{
    struct node* genesisnode;

    genesisnode=createnode();


    return 0;
}
