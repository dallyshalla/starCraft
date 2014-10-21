
CXX := g++
CXXFLAGS := -g

INCLUDES := -I.
INCLUDES += -I./include

BUILD_DIR := _build
SOURCE_DIR := src

$(BUILD_DIR)/% : $(BUILD_DIR)/%.o
	$(CXX) $(CXXFLAGS) $< -o $@

$(BUILD_DIR)/%.o : $(SOURCE_DIR)/%.cc | build_dir
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

.PHONY: all
all : $(BUILD_DIR)/main2

.PHONY : build_dir
build_dir :
	@mkdir -p $(BUILD_DIR)

.PHONY : clean
clean :
	rm -r $(BUILD_DIR)

