# From https://gist.github.com/samuelsmal/e43f2001cfc81fee18b6
# Requires the following project directory structure:
#  /bin
#  /obj
#  /src

# Use 'make remove' to clean up the hole project

# Name of target file
TARGET     = rps

CXX        = clang++
CXXFLAGS   = -std=c++20 \
             -Wall -Wextra -Werror \
             -pedantic-errors -pedantic \
             -Os

LD         = clang++ -o
LDFLAGS    = -Wall -pedantic

SRCDIR     = src
OBJDIR     = obj
BINDIR     = bin

SOURCES   := $(wildcard $(SRCDIR)/*.cpp)
INCLUDES  := $(wildcard $(SRCDIR)/*.h)
OBJECTS   := $(SOURCES:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)

RM         = rm -f

$(BINDIR)/$(TARGET): $(OBJECTS)
	@$(LD) $@ $(LDFLAGS) $(OBJECTS)
	@echo "Linking complete!"

$(OBJECTS): $(OBJDIR)/%.o : $(SRCDIR)/%.cpp
	@$(CXX) $(CXXFLAGS) -c $< -o $@
	@echo "Compiled "$<" successfully!"

.PHONY: clean
clean:
	@$(RM) $(OBJECTS)
	@echo "Cleanup complete!"

.PHONY: remove
remove: clean
	@$(RM) $(BINDIR)/$(TARGET)
	@echo "Executable removed!"