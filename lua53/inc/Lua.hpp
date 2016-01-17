#pragma once

extern "C"
{
#include		<lauxlib.h>
#include		<lualib.h>
#include		<lua.h>
}
#include		<iostream>
#include		<sstream>

class			Lua
{
private:
  lua_State		*_state;
  luaL_Reg		*_libs;
  bool			_arg;

public:
  Lua();
  ~Lua();

  bool			init();

  void			pushArg(bool b);
  void			pushArg(int n);
  void			pushArg(double n);
  void			pushArg(const std::string &s);
  //  void			push(int k, const std::string &v);

  lua_State	        *getState() { return _state; }
};

Lua::Lua() :
  _state(NULL),
  _libs(NULL),
  _arg(false)
{
}

Lua::~Lua()
{
  if (_state)
    lua_close(_state);
  if (_libs)
    delete[] _libs;
}

bool			Lua::init()
{
  // new Lua state
  std::cout << "[C++] Starting Lua state" << std::endl;
  if ((_state = luaL_newstate()) == NULL)
    return false;

  // load Lua libraries
  std::cout << "[C++] Loading Lua libraries" << std::endl;
  _libs = new luaL_Reg[3]
    {
      {"base", luaopen_base},
      {"io", luaopen_io},
      {NULL, NULL}
    };

  for(const luaL_Reg *lib = _libs; lib->func != NULL; lib++)
    {
      std::cout << " loading '" << lib->name << "'" << std::endl;
      luaL_requiref(_state, lib->name, lib->func, 1);
      lua_settop(_state, 0);
    }
  return true;
}

void			Lua::pushArg(bool b)
{
  _arg = true;
  lua_pushboolean(_state, b);
}

void			Lua::pushArg(int n)
{
  _arg = true;
  lua_pushinteger(_state, n);
}

void			Lua::pushArg(double n)
{
  _arg = true;
  lua_pushnumber(_state, n);
}

void			Lua::pushArg(const std::string &s)
{
  _arg = true;
  lua_pushstring(_state, s.c_str());
}
