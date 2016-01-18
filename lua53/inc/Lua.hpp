#pragma once

extern "C"
{
#include		<lauxlib.h>
#include		<lualib.h>
#include		<lua.h>
}
#include		<map>

#include		<iostream>

class			Lua
{
public:
  typedef std::map<std::string, lua_CFunction> libMap;
  lua_State		*_state;
  libMap		_libs;
  size_t		_argIndex;

public:
  Lua();
  ~Lua();

  bool			init();

  template <typename K, typename V>
  void			push(K key, V value)
  {
    push(key);
    push(value);
    lua_settable(_state, -3);
  }
  void			push(bool b);
  void			push(int n);
  void			push(double n);
  void			push(const char *s);
  void			push(const std::string &s);
  void			push();
  void			newTable();

  template <typename T>
  T			pop()
  {
    T		        var;

    pop(var, lua_gettop(_state));
    pop();
    return var;
  }
  template <typename T>
  T			getKey()
  {
    T			var;

    pop(var, -2);
    return var;
  }
  template <typename T>
  T			getValue()
  {
    T			var;

    pop(var, -1);
    return var;
  }
  void			pop();

  int			getType();
  int			getKeyType();
  int			getValueType();

  int			stackSize();
  bool			next();
  void			setGlobal(const std::string &s);

  bool			open(const std::string &filename);
  bool			run();

private:
  void			pop(bool &b, int index);
  void			pop(int &n, int index);
  void			pop(double &d, int index);
  void			pop(const char *&s, int index);
  void			pop(std::string &s, int index);
};
