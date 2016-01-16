extern "C"
{
#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>
}

/*
** http://acamara.es/blog/2012/08/running-a-lua-5-2-script-from-c/
**
** g++ test.cpp -llua53 -L. -I./include -o topkek
*/

int main()
{
// create new Lua state
    lua_State *lua_state;
    lua_state = luaL_newstate();

    // load Lua libraries
    static const luaL_Reg lualibs[] =
    {
        { "base", luaopen_base },
        { NULL, NULL}
    };

    const luaL_Reg *lib = lualibs;
    for(; lib->func != NULL; lib++)
    {
        lib->func(lua_state);
        lua_settop(lua_state, 0);
    }

    // run the Lua script
    luaL_dofile(lua_state, "helloworld.lua");

    // close the Lua state
    lua_close(lua_state);
    return 0;
}
