# cpp-env-var
### A small C++ library for handling environmenal variable 

```I know that it's very easy and simple but I will it it for personal use as it's annoying for me to code to read .env everytime```

It will have two features:
1. environmental variable from file (by default, it will be .env)
2. ~~It will fetch environmental variable from the OS~~ (No no, I won't be writing for that, just use std::getenv())
   (But if someone want to contribute the second part,I'm down. You can send pull requests for that ^-^ )

Sample code :

```cpp
#include "getenv.h"

int main(){
   std::map<std::string,std::string> h= get_env_fromFile();
   std:: cout << h["hello"];
}

```

Sample env file :
Remember to use quotes(single/double) for both keys and values
```yaml
"test"="nirajan"
" hello "  = "world"
```