ifndef VERBOSE
.SILENT:
endif

APPNAME := program
OBJDIR  := objects
DEPDIR  := objects
SOURCES := $(shell find . -maxdepth 1 -name "*.cpp")

CXX := g++
CXXFLAGS := -g -std=c++23 -Wall -Wextra -Werror -pedantic -O3

OBJECTS_WRONG_DIR := $(foreach source, $(SOURCES), $(basename $(source)).o)
OBJECTS := $(addprefix $(OBJDIR)/, $(notdir $(OBJECTS_WRONG_DIR)))

define mkdir_target
test -d $(@D) \
  || ( echo "Creating directory $(@D)" && mkdir -p $(@D) ) \
  || echo Unable to create $(@D);
endef

.PHONY: all clean

all: $(APPNAME)

$(APPNAME): $(OBJECTS)
	$(mkdir_target)
	$(CXX) $(CXXFLAGS) -o $(APPNAME) $(OBJECTS)

$(OBJDIR)/%.o : %.cpp
	$(mkdir_target)
	@echo Compiling $<
	$(CXX) -c -o $@ $< $(CXXFLAGS)

clean:
	@echo Removing objects
	rm -f $(OBJECTS) > /dev/null 2>&1
	rm -rf $(OBJDIR) > /dev/null 2>&1
	@echo Removing executable
	rm -f $(APPNAME) > /dev/null 2>&1
