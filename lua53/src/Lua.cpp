#include		<iostream>
#include		"Lua.hpp"

Lua::Lua() :
  _state(NULL),
  _argIndex(1)
{
}

Lua::~Lua()
{
  if (_state)
    lua_close(_state);
}

bool			Lua::init()
{
  if ((_state = luaL_newstate()) == NULL)
    return false;
  _libs["base"] = luaopen_base;
  _libs["io"] = luaopen_io;
  for(libMap::iterator it = _libs.begin(); it != _libs.end(); it++)
    {
      luaL_requiref(_state, it->first.c_str(), it->second, 1);
      lua_settop(_state, 0);
    }
  return true;
}

void			Lua::push(bool b)
{
  lua_pushboolean(_state, b);
}

void			Lua::push(int n)
{
  lua_pushinteger(_state, n);
}

void			Lua::push(double d)
{
  lua_pushnumber(_state, d);
}

void			Lua::push(const char *s)
{
  lua_pushstring(_state, s);
}

void			Lua::push(const std::string &s)
{
  push(s.c_str());
}

void			Lua::push()
{
  lua_pushnil(_state);
}

void			Lua::newTable()
{
  lua_newtable(_state);
}

void			Lua::pop()
{
  lua_pop(_state, 1);
}

int			Lua::getType()
{
  return lua_type(_state, lua_gettop(_state));
}

int			Lua::getKeyType()
{
  return lua_type(_state, -2);
}

int			Lua::getValueType()
{
  return lua_type(_state, -1);
}

int			Lua::stackSize()
{
  return lua_gettop(_state);
}

bool			Lua::next()
{
  return lua_next(_state, -2);
}

void			Lua::setGlobal(const std::string &s)
{
  lua_setglobal(_state, s.c_str());
}

bool			Lua::open(const std::string &filename)
{
  return luaL_loadfile(_state, filename.c_str()) == LUA_OK;
}

bool			Lua::run()
{
  return lua_pcall(_state, 0, LUA_MULTRET, 0) == LUA_OK;
}

void			Lua::pop(bool &b, int index)
{
  b = lua_toboolean(_state, index);
}

void			Lua::pop(int &n, int index)
{
  n = lua_tointeger(_state, index);
}

void			Lua::pop(double &d, int index)
{
  d = lua_tonumber(_state, index);
}

void			Lua::pop(const char *&s, int index)
{
  s = lua_tostring(_state, index);
}

void			Lua::pop(std::string &s, int index)
{
  s = lua_tostring(_state, index);
}
