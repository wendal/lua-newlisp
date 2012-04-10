
//#include <stdio.h>
//#include <stdlib.h>
//#include <ctype.h>
//#include <errno.h>
//#include <string.h>
 
//#include <unistd.h>
//#include <fcntl.h>
//#include <sys/stat.h>
//#include <limits.h>
 
#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"

#include "newLISP.h"
 
int luaopen_newLISP(lua_State *L);

static int newLISP_eval(lua_State *L) {
   char * str = lua_tostring(L, 1);
   char * result = newlispEvalStr(str);
   lua_pushstring(L, result);
   return 1;
}
 
static const luaL_reg newLISP_lib[] = {
   {"eval", newLISP_eval},
   {0,0}
};
 
int luaopen_newLISP(lua_State *L) {
   luaL_register(L, "newLISP", newLISP_lib);
   return 1;
}
