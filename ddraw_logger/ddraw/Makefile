-include config.mk

TARGET    = ddraw.dll
LDFLAGS   = -Wl,--enable-stdcall-fixup -s -static -shared
CFLAGS    = -Iinc -O2 -march=i486 -Wall
LIBS      = -lgdi32 -lwinmm -ldbghelp -lole32

CC        = i686-w64-mingw32-gcc
CXX       = i686-w64-mingw32-g++
WINDRES  ?= i686-w64-mingw32-windres

SRCS     := $(wildcard *.cpp)
OBJS     := $(SRCS:cpp=o)

.PHONY: clean all
all: $(TARGET)

%.o: %.rc
	$(WINDRES) -J rc $< $@

$(TARGET): $(OBJS)
	$(CXX) $(LDFLAGS) -o $@ $^ ddraw.def $(LIBS)

clean:
	$(RM) $(TARGET) $(OBJS)
