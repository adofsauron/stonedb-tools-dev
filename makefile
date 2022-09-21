TARGET	=	stonedb-tools
S_SRCS 	=	$(wildcard src/*.cpp)
B_SRCS 	= 	$(wildcard src/tianmu/*.cpp)
OBJS	=	$(patsubst src/%.cpp, src/%.o, $(S_SRCS))
OBJS	+= 	$(patsubst src/tianmu/%.cpp, src/tianmu/%.o, $(B_SRCS))

CFLAGS	+=	-std=c++17 -Isrc -Isrc/tianmu
CFLAGS 	+= 	-D__LINUX__
CFLAGS	+=  -ggdb3 -O0
CFLAGS  +=	-lstdc++fs
USEDE	=	-DSTONEDB_TOOLS_DEBUG

CC		=	g++

$(TARGET):$(OBJS)
	$(CC) $(USEDE) $(OBJS) $(CFLAGS) -o $@

%.o: %.cpp
	$(CC) -c $^ $(CFLAGS) $(USEDE)  -o $@


.PHONY : clean

clean:
	rm  $(TARGET)	-f
	rm $(OBJS) -f