LICENSE_PATH=~
WINE_TOOL_CHAIN_PATH=~/.wine/drive_c/HighTec/toolchains/tricore/v4.9.3.0-infineon-1.0


blink: blink.c
	wine $(WINE_TOOL_CHAIN_PATH)/bin/tricore-gcc.exe $< -mlicense-dir=$(LICENSE_PATH) -o $@

