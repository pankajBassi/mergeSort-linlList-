CXX = g++
VERSION = -std=c++14
CFLAGS = -pedantic -Wall -Wextra $(VERSION) $(NO_DEBUGGING_STATEMENTS)
LFLAGS = -Wall $(VERSION) 

INCS = Term.h\
   Polynomial.h
SRCS = Term.cpp\
   Polynomial.cpp\
	doMath.cpp
OBJS = $(SRCS:.cpp=.o)
EXEC = doMath

all: $(SRCS) $(EXEC)

# To make an object from source
#.cpp.o: 
%.o:%.cpp $(INCS)
	$(CXX) $(CFLAGS) -c $< -o $@

$(EXEC): $(OBJS) 
	$(CXX) $(LFLAGS) $(OBJS) -o $@

# for Windows
clean:
	del *.o  $(EXEC).exe
	@echo clean done

# for UNIX / Linux 
remove:
	\rm -f *.o  $(EXEC)
	@echo clean done

