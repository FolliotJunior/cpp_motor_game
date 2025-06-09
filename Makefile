MAIN        = main.cpp

SRC_DIR     = src
BUILD_DIR   = build
INCLUDE_DIR = include

WINDOW      = 	init_window.cpp		\
				init_shader.cpp		\
				draw_triangle.cpp

CPP_SRC     = $(addprefix $(SRC_DIR)/window/, $(WINDOW)) \
              $(SRC_DIR)/$(MAIN)

C_SRC       = $(SRC_DIR)/glad/glad.c

OBJ         = $(patsubst $(SRC_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(CPP_SRC)) \
              $(patsubst $(SRC_DIR)/%.c,   $(BUILD_DIR)/%.o, $(C_SRC))

NAME        = motor

CXX         ?= g++
CXXFLAGS    += -std=c++20 -Wall -Wextra -iquote$(INCLUDE_DIR)
CPPFLAGS	+= -Wall -Wextra -iquote$(INCLUDE_DIR)
LDFLAGS     += -lglfw -lGL

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) -o $(NAME) $(OBJ) $(LDFLAGS)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CXX) $(CPPFLAGS) -c $< -o $@

clean:
	$(RM) -r $(BUILD_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean
	make -j

debug: CXXFLAGS += -fsanitize=address
debug: re

.PHONY: all clean fclean re debug
