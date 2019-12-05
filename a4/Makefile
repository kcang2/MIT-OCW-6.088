# the compiler: gcc for C program, define as g++ for C++
# CXX if using g++
CXX = g++

# compiler flags:
#  -g    adds debugging information to the executable file
#  -Wall turns on most, but not all, compiler warnings
# CXXFLAGS if using g++
CXXFLAGS  = -g -Wall

# the build target executable:
TARGET = test_bst

# folder for object files (.o)
OBJDIR = objs

# Dependencies (local includes)
DEPS = bst.h

# default target to compile
default: $(TARGET)

# clean and dirs are not output files
.PHONY: dirs clean

# creates object files directory
dirs:
	/bin/mkdir -p $(OBJDIR)/

# removes objects directory and target
clean:
	/bin/rm -rf $(OBJDIR) $(TARGET)

# List(?) of objects
_OBJ = $(TARGET).o bst.o

# for each _OBJ, substitute the obj with objdir/obj
# basically append the obj folder name
# syntax (from, to, text)
OBJS = $(patsubst %, $(OBJDIR)/%, $(_OBJ))

# $@ ==  put output of compilation on LHS of : (ie. $(TARGET))
# In this case, compile with objs and put into target
# $^ == RHS of : (ie. $^ $(OBJS))
$(TARGET): dirs $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS)

# $< == only the first dependency (%.c)
$(OBJDIR)/%.o: %.cpp $(DEPS)
	$(CXX) $(CXXFLAGS) -c -o $@ $<

