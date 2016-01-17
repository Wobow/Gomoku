// http://acamara.es/blog/2012/08/running-a-lua-5-2-script-from-c/

#include	"Lua.hpp"

int		main()
{
  Lua		lua;

  lua.init();
  lua_State *lua_state = lua.getState();
  // start the arg table in Lua
  std::cout << "[C++] Creating the arg table" << std::endl;
  lua.pushArg(1);
  lua.pushArg(49);
  lua.pushArg(2);
  lua.pushArg("Life is a beach");
  /*
  lua_createtable(lua_state, 2, 0);
  lua_pushnumber(lua_state, 1);
  lua_pushnumber(lua_state, 49);
  lua_settable(lua_state, -3);
  lua_pushnumber(lua_state, 2);
  lua_pushstring(lua_state, "Life is a beach");
  lua_settable(lua_state, -3);
  */
  lua_setglobal(lua_state, "arg");

  // load the script
  std::cout << "[C++] Loading the Lua script" << std::endl;
  int status = luaL_loadfile(lua_state, "scripts/variables.lua");
  std::cout << " return: " << status << std::endl;

  // run the script with the given arguments
  std::cout << "[C++] Running script" << std::endl;
  int result = 0;
  if(status == LUA_OK)
    {
      result = lua_pcall(lua_state, 0, LUA_MULTRET, 0);
    }
  else
    {
      std::cout << " Could not load the script." << std::endl;
    }
  if (result == LUA_OK)
    {
      // print the values returned from the script
      std::cout << "[C++] Values returned from the script:" << std::endl;
      std::stringstream str_buf;
      while(lua_gettop(lua_state))
	{
	  str_buf.str(std::string());
	  str_buf << " ";
	  switch(lua_type(lua_state, lua_gettop(lua_state)))
	    {
	    case LUA_TNUMBER:
	      str_buf << "script returned the number: "
		      << lua_tonumber(lua_state, lua_gettop(lua_state));
	      break;
	    case LUA_TTABLE:
	      str_buf << "script returned a table";
	      break;
	    case LUA_TSTRING:
	      str_buf << "script returned the string: "
		      << lua_tostring(lua_state, lua_gettop(lua_state));
	      break;
	    case LUA_TBOOLEAN:
	      str_buf << "script returned the boolean: "
		      << lua_toboolean(lua_state, lua_gettop(lua_state));
	      break;
	    default:
	      str_buf << "script returned an unknown-type value";
	    }
	  lua_pop(lua_state, 1);
	  std::cout << str_buf.str() << std::endl;
	}
    }
  else
    std::cout << " Could not call the script" << std::endl;
  // close the Lua state
  std::cout << "[C++] Closing the Lua state" << std::endl;
  return 0;
}
