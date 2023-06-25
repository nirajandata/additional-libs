//
// Created by nirarara on 6/25/23.
//

#ifndef CPP_ENV_VAR_GETENV_H
#define CPP_ENV_VAR_GETENV_H

#include <iostream>
#include <fstream>
#include <map>
#include <algorithms>
#include <array>
#include <tuple>

std::tuple<string,string> trim(std::string &line){
    std::erase(std::remove(line.begin(),line.end(),' '),line.end());
    array<int,4> locate;
    int count=0;
    for(size_t i=0;i<line.size();i++){
        if(line[i]=="'" or line[i]=='"'){
            locate[count]=i;
            count++;
        }
        assert(("Please! Only put quotes in the proper place, not inside key or value",count<4));
    }
    std::string key, value;
    key=line.substr(locate[0]+1,locate[1]-locate[0]);
    value=line.substr(locate[2]+1, locate[3]-locate[2]);
    return make_pair(key,value)
}
std::map<string,string> get_env_fromFile(std::string path=".env"){
    std::ifstream file(path);
    //we store the key and value in dictionary called baniya
    std::map<string,string> baniya;
    std::string line;

    while(getline(file,line)){
        std::string key, value;
       std::tie(key,value) =trim(line);
       baniya[key]=value;
    }

    file.close();
    return baniya;
}

//Kept as TODO for somedays as I have some homeworks to do for college
std::string get_env_fromOS(std::string token_name){

}
#endif //CPP_ENV_VAR_GETENV_H
