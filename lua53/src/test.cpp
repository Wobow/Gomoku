// http://acamara.es/blog/2012/08/running-a-lua-5-2-script-from-c/

#include        <iostream>
#include	"Lua.hpp"

bool		helloworld()
{
  Lua		lua;

  // initialisation de l'API C Lua
  if (!lua.init())
    return false;
  // ouverture du script
  if (!lua.open("scripts/helloworld.lua"))
    return false;
  // lancement du script
  if (!lua.run())
    return false;
  return true;
}

bool		args()
{
  Lua		lua;

  if (!lua.init())
    return false;

  lua.newTable(); // on déclare un nouveau tableau pour les arguments
  lua.push(1, "arg1"); // correspond à arg[1] = "arg1"
  lua.push(2, 42); // arg[2] = 42
  lua.push(3, 13.37);
  lua.push(4, true);
  lua.push(5, "dernier argument");
  lua.setGlobal("arg"); // on nomme la table "arg" pour la retrouver dans le script lua

  if (!lua.open("scripts/args.lua"))
    return false;
  if (!lua.run())
    return false;
  return true;
}

bool	        ret()
{
  Lua		lua;

  if (!lua.init())
    return false;
  if (!lua.open("scripts/ret.lua"))
    return false;
  if (!lua.run())
    return false;

  while (lua.stackSize()) // tant qu'il y a des variables sur la stack
    {
      switch (lua.getType()) // on récupère le type de la variable
	{
	case LUA_TNUMBER:
	  std::cout << "script returned the number: " << lua.pop<double>() << std::endl;
	  break;
	case LUA_TTABLE:
	  std::cout << "script returned a table" << std::endl;
	  lua.pop();
	  break;
	case LUA_TSTRING:
	  std::cout << "script returned the string: " << lua.pop<std::string>() << std::endl;
	  break;
	case LUA_TBOOLEAN:
	  std::cout << "script returned the boolean: " << lua.pop<bool>() << std::endl;
	  break;
	default:
	  std::cout << "script returned an unknown-type value" << std::endl;
	  lua.pop();
	}
    }  
  return true;
}

void		print_table(Lua &lua, int tab)
{
  lua.push(); // on push une valeur null qui represente la fin de la table (un peu comme un \0)
  while (lua.next()) // tant qu'il y a des valeurs dans la table
    {
      for (int i = 0; i < tab; i++) // ca c'est juste pour l'indentation (table dans table)
	std::cout << ' ';
      switch (lua.getKeyType())
	{
	  // on fait des lua.getKey() au lieu de lua.pop() cette fois-ci
	case LUA_TNUMBER:
	  std::cout << lua.getKey<double>();
	  break;
	case LUA_TSTRING:
	  std::cout << lua.getKey<std::string>();
	  break;
	case LUA_TBOOLEAN:
	  std::cout << lua.getKey<bool>();
	  break;
	default:
	  std::cout << "unknown-type";
	}
      std::cout << " = ";
      switch (lua.getValueType())
	{
	  // et ici on fait des lua.getValue()
	case LUA_TNUMBER:
	  std::cout << lua.getValue<double>() << std::endl;
	  break;
	case LUA_TTABLE:
	  std::cout << std::endl;
	  print_table(lua, tab + 2); // si la valeur est une table on rappelle la fonction #récursivité
	  break;
	case LUA_TSTRING:
	  std::cout << lua.getValue<std::string>() << std::endl;
	  break;
	case LUA_TBOOLEAN:
	  std::cout << lua.getValue<bool>() << std::endl;
	  break;
	default:
	  std::cout << "unknown-type" << std::endl;
	}
      lua.pop(); // on pop la variable contenue dans la table
    }
  std::cout << std::endl;
}

bool		table()
{
  Lua		lua;

  if (!lua.init())
    return false;
  if (!lua.open("scripts/table.lua"))
    return false;
  if (!lua.run())
    return false;

  if (lua.getType() != LUA_TTABLE) // je vérifie si c'est une table, au cas où lol
      return false;
  print_table(lua, 0);
  return true;
}

int		main()
{
  std::cout << "helloworld.lua:" << std::endl;
  helloworld();
  std::cout << std::endl;

  std::cout << "args.lua:" << std::endl;
  args();
  std::cout << std::endl;

  std::cout << "ret.lua:" << std::endl;
  ret();
  std::cout << std::endl;

  std::cout << "table.lua:" << std::endl;
  table();
  std::cout << std::endl;

  return 0;
}
