NAME = fractals
ICON = icon.png
DESCRIPTION = "Draw fractals on a calculator screen"
COMPRESSED = NO

CFLAGS = -Wall -Wextra -Oz
CXXFLAGS = -Wall -Wextra -Oz

include $(shell cedev-config --makefile)
