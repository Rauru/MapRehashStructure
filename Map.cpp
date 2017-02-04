#include "Map.h"

int Map::funcionHash(string key, int rerun)
{
    int suma=0;
    for(int i=0;i<key.size();i++)
    {
        suma+=key[i];
    }
    return suma+rerun;
}

Map::Map()
{
    int size = 10000;
    array_key = new string[size];
    array_value = new int[size];

    for(int i=0;i<size;i++)
        array_key[i]="";
}

void Map::put(string key, int value)
{
    int rerun = 0;
    int pos;
    do
    {
        pos = funcionHash(key,rerun);
        rerun++;
    }while(array_key[pos]!="");

    array_key[pos]=key;
    array_value[pos]=value;
}

int Map::get(string key)
{
    int rerun = 0;
    int pos;
    do
    {
        pos = funcionHash(key,rerun);
        rerun++;

    }while(array_key[pos]!=key);

    return array_value[pos];
}

bool Map::exists(string key)
{
    int rerun = 0;
    int pos;
    bool exist = false;
    do
    {
        pos = funcionHash(key,rerun);
        rerun++;
        if(array_key[pos] ==key)
            {
                return true;
            }
            if(pos== 1000)
                {
                    return false;
                }

    }while(array_key[pos]!=key);


    return exist;
}

void Map::remove(string key)
{
    int rerun = 0;
    int pos;
    bool exist = false;
    do
    {
        pos = funcionHash(key,rerun);
        rerun++;
        if(array_key[pos]==key)
            {
                array_key[pos]="";
                array_value[pos]=0;
                break;
            }

    }while(array_key[pos]!=key);


}
