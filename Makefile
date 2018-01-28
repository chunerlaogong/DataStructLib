#makefile by ****
#2015年1月4日09:07:28
cc = g++
cpp = -fPIC -Wall -g

inc += -I./include

objs+=$(patsubst %.cpp,%.o, $(wildcard src/*.cpp))

%.o:%.cpp
	$(cc) $(cpp) $(inc) -o $@ -c $<
	@echo "$@"

module=./DataStruct

all:$(module)

$(module):$(objs)
		$(cc) $(cpp) $(inc) -o $(module) $^ $(libs)
		@echo "$@"

clean:
		@rm -f $(objs) $(module)
		@echo "clean done."