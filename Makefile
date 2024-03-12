#names
OUT=rts_server
LIBDYOUT=lib$(OUT).so
LIBSTAOUT=lib$(OUT).a
CC=g++

#flags
CPPFLAGS= -std=c++20
CXXFLAGS= -W -Wall
DFLAGS= -O0 -g -g3
GCOVFLAGS= -O0 --coverage -ftest-coverage -fprofile-arcs
OPTIFLAGS= -O3
GTEST_LIBS= -lgtest_main -lgtest -lpthread

#links
LAPINLINKS=-L./ -llapin -lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system -lstdc++ -lm -ldl -lpthread -lopencv_imgproc -lopencv_objdetect -lopencv_highgui -lopencv_video -lopencv_core -lavcall -lusb -lopencv_videoio

#options
ifeq ($(DEBUG), 1)
	OPTFLAGS = $(DFLAGS)
endif
ifeq ($(GCOV), 1)
	OPTFLAGS += $(GCOVFLAGS)
endif
ifeq ($(OPTFLAGS),)
	OPTFLAGS = $(OPTIFLAGS)
endif

#others
INCLUDE=-I./include/
TESTINCLUDE=-I./test/include/

FLAGS=$(CPPFLAGS) $(CXXFLAGS) $(OPTFLAGS)

SRC=$(shell find src/ -name "*.cpp")
TESTSRC=$(shell find test/ -name "*.cpp")

OBJ=$(SRC:.cpp=.o)
TESTOBJ=$(TESTSRC:.cpp=.o)
TESTOUT=$(TESTOBJ:.o=.test)

MAKE=make re
##Rules##

all: cc

cc: $(OUT)

$(OUT): $(OBJ)
ifeq ($(LIBLAPIN), 1)
	$(CC) $(OBJ) $(INCLUDE) $(FLAGS) $(LAPINLINKS) -o $(OUT)
else
	$(CC) $(OBJ) $(INCLUDE) $(FLAGS) -o $(OUT)
endif

lib: $(LIBSTAOUT) $(LIBDYOUT) test

$(LIBSTAOUT): $(OBJ)
	ar cr $(LIBSTAOUT) $(OBJ)

$(LIBDYOUT): $(OBJ)
	$(CC) -shared -o $(LIBDYOUT) $(OBJ)

test: $(LIBSTAOUT) $(TESTOBJ) $(TESTOUT)
ifeq ($(GCOV), 1)
	lcov --capture --directory . --output-file coverage.info
	genhtml coverage.info --output-directory report
endif

report:
	gcov $(SRC)
	lcov --capture --directory . --output-file coverage.info
	genhtml coverage.info --output-directory report

.cpp.o:
	$(CC) -c $< $(INCLUDE) -o $@ $(FLAGS) -fPIC

%.test: %.o
ifeq ($(GTEST), 1)
ifeq ($(LIBLAPIN), 1)
	$(CC) $(INCLUDE) $< $(FLAGS) $(GTEST_LIBS) $(LIBSTAOUT) $(LAPINLINKS) -o $@
else
	$(CC) $(INCLUDE) $< $(FLAGS) $(GTEST_LIBS) $(LIBSTAOUT) -o $@
endif
else
ifeq ($(LIBLAPIN), 1)
	$(CC) $(INCLUDE) $< $(FLAGS) $(LIBSTAOUT) $(LAPINLINKS) -o $@
else
	$(CC) $(INCLUDE) $< $(FLAGS) $(LIBSTAOUT) -o $@
endif
endif
	./$@
ifeq ($(GCOV), 1)
	gcov $@
endif

clean:
	@rm -f $(OBJ)
	@rm -f $(TESTOBJ)
	@rm -f $(shell find ./ -name "*~")
	@rm -f $(shell find ./ -name "*.gcno")
	@rm -f $(shell find ./ -name "*.gcda")
	@rm -f $(shell find ./ -name "*.gcov")
	@rm -f vgcore*
	@rm -f coverage.info
	@rm -f -r report

fclean: clean
	@rm -f $(OUT)
	@rm -f test/test$(OUT)
	@rm -f $(LIBSTAOUT)
	@rm -f $(LIBDYOUT)
	@rm -f $(TESTOUT)

testclean:
	@rm -f test/*.test

re: fclean all

relib: fclean lib

retest: testclean test
