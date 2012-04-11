
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

static int newLISP_eval2(lua_State *L) {
   const char * str = lua_tostring(L, 1);
   const char * result = newlispEvalStr(str);
   lua_pushstring(L, result);
   return 1;
}

static int newLISP_eval_stream(lua_State *L, STREAM *strStream) {
   CELL * cell = evaluateStream(strStream, 0, 1);

   STREAM libStrStream = {0, NULL, NULL, 0, 0};
   openStrStream(&libStrStream, 8192, 1);
   printCell(cell, 0, (UINT)&libStrStream);

   char * result = libStrStream.buffer;
   lua_pushstring(L, result);
   return 1;
}


static int newLISP_eval(lua_State *L) {
   const char * str = lua_tostring(L, 1);
   STREAM strStream = {0, NULL, NULL, 0, 0};
   makeStreamFromString(&strStream, str);
   return newLISP_eval_stream(L, &strStream);
}

static int newLISP_eval_file(lua_State *L) {
   const char * str = lua_tostring(L, 1);
   STREAM strStream = {0, NULL, NULL, 0, 0};
   makeStreamFromFile(&strStream, str, MAX_FILE_BUFFER, 0);
   return newLISP_eval_stream(L, &strStream);
}


 
static const luaL_reg newLISP_lib[] = {
   {"eval", newLISP_eval},
   {"eval_file", newLISP_eval_file},
   {"eval2", newLISP_eval2},
   {0,0}
};
 
int luaopen_newLISP(lua_State *L) {
   char * str = "()";
   newlispEvalStr(str);
   luaL_register(L, "newLISP", newLISP_lib);
   return 1;
}
