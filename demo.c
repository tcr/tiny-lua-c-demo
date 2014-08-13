/*
 * test.c
 * Example of a C program that interfaces with Lua.
 * Based on Lua 5.0 code by Pedro Martelletto in November, 2003.
 * Updated to Lua 5.1. David Manura, January 2007.
 */

#include <lua.h>
#include <lauxlib.h>
#include <stdlib.h>
#include <stdio.h>

// Read http://lua-users.org/wiki/SimpleLuaApiExample for more details.


static my_func (lua_State *L)
{
	double value = lua_tonumber(L, 1); /* get first argument passed to fn (on bottom/beginning of stack, thus +1); */
	printf("[C] Called from C! %f\n", value);

	/* return a value, push to top of stack, then return the number of args returned (normally 0 or 1) */
	lua_pushnumber(L, 10);
	return 1;
}

int
main(void)
{
    int status, result, i;
    double sum;
    lua_State *L;

    printf("starting lua script...\n");

    /*
     * All Lua contexts are held in this structure. We work with it almost
     * all the time.
     */
    L = luaL_newstate();

    luaL_openlibs(L); /* Load Lua libraries */

    /* Load the file containing the script we are going to run */
    status = luaL_loadfile(L, "demo.lua");
    if (status) {
        /* If something went wrong, error message is at the top of */
        /* the stack */
        fprintf(stderr, "Couldn't load file: %s\n", lua_tostring(L, -1));
        exit(1);
    }

    /* Add a C function we expose to the top of the stack. */
    lua_pushcfunction(L, my_func);
    /* Set the top of the stack value as a global. */
    lua_setglobal(L, "exposed_my_func");

    /* Ask Lua to run our little script */
    result = lua_pcall(L, 0, LUA_MULTRET, 0);
    if (result) {
        fprintf(stderr, "Failed to run script: %s\n", lua_tostring(L, -1));
        exit(1);
    }

    /* Get the returned value at the top of the stack (index -1) */
    sum = lua_tonumber(L, -1);

    printf("lua script returned %.0f\n", sum);

    lua_pop(L, 1);  /* Take the returned value out of the stack */
    lua_close(L);   /* Cya, Lua */

    return 0;
}