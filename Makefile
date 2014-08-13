all:
	gcc -o demo demo.c -std=gnu99 \
	  lua-5.1.5/src/lapi.c lua-5.1.5/src/ldo.c lua-5.1.5/src/llex.c lua-5.1.5/src/loslib.c lua-5.1.5/src/ltablib.c lua-5.1.5/src/lzio.c lua-5.1.5/src/lauxlib.c lua-5.1.5/src/ldump.c lua-5.1.5/src/lmathlib.c lua-5.1.5/src/lparser.c lua-5.1.5/src/ltm.c lua-5.1.5/src/print.c lua-5.1.5/src/lbaselib.c lua-5.1.5/src/lfunc.c lua-5.1.5/src/lmem.c lua-5.1.5/src/lstate.c lua-5.1.5/src/lcode.c lua-5.1.5/src/lgc.c lua-5.1.5/src/loadlib.c lua-5.1.5/src/lstring.c lua-5.1.5/src/ldblib.c lua-5.1.5/src/linit.c lua-5.1.5/src/lobject.c lua-5.1.5/src/lstrlib.c lua-5.1.5/src/lundump.c lua-5.1.5/src/ldebug.c lua-5.1.5/src/liolib.c lua-5.1.5/src/lopcodes.c lua-5.1.5/src/ltable.c lua-5.1.5/src/lvm.c \
	  -I lua-5.1.5/src
