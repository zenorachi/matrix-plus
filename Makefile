LIB_NAME = s21_matrix_oop.a

CC = gcc
CFLAGS := -lstdc++ -std=c++17 -pedantic -Wall -Werror -Wextra
MATH_FLAG = -lm
GFLAGS = -lcheck

UNAME = $(shell uname)

ifeq ($(UNAME), Linux)
CFLAGS += $(MATH_FLAG)
OPEN_REPORT = xdg-open
endif

ifeq ($(UNAME), Darwin)
OPEN_REPORT = open
endif

OBJ_FLAGS = -c -lstdc++ -std=c++17 -pedantic -Wall -Werror -Wextra

SRC_CLASS = class-methods/*.cc
SRC_SUPPORT = class-methods/support-methods/*.cc
SRC_EQUAL = class-methods/equal-methods/*.cc
SRC_ARITHMETIC = class-methods/arithmetic-methods/*.cc
SRC_OTHER = class-methods/other-methods/*.cc

SOURCE = $(SRC_CLASS) $(SRC_SUPPORT) $(SRC_EQUAL) $(SRC_ARITHMETIC) $(SRC_OTHER)

SRC_TEST = tests/*.cc
OBJ_TEST = tests/*.o

OBJ = *.o

EXECUTABLE = test

all: $(LIB_NAME)

clean:
	@rm -rf s21_matrix_oop.a
	@rm -rf $(EXECUTABLE)
	@rm -rf $(OBJ)
	@rm -rf *.dSYM
	@rm -rf report *.info *.gcno *.gcda
	@rm -rf main

test: $(LIB_NAME)
	$(CC) $(CFLAGS) $(SRC_TEST) $(LIB_NAME) -lgtest -o $(EXECUTABLE) && ./$(EXECUTABLE)

$(LIB_NAME): clean build
	ar rcs s21_matrix_oop.a $(OBJ)
	ranlib s21_matrix_oop.a
	@rm -rf *.o
	@echo && echo "\033[37;1;42m --- LIBRARY s21_matrix_oop.a CREATED SUCCESSFULLY --- \033[0m"

gcov_report: $(LIB_NAME)
	@$(CC) $(CFLAGS) $(SOURCE) $(SRC_TEST) $(LIB_NAME) -lgtest -o $(EXECUTABLE) --coverage
	@./$(EXECUTABLE)
	@rm -rf test_* test-test*
	@lcov -t "tests" -o tests.info -c -d .
	genhtml -o report tests.info
	$(OPEN_REPORT) report/index.html

style:
	clang-format --style=google -n *.h
	clang-format --style=google -n class-methods/*.cc class-methods/*/*.cc
	clang-format --style=google -n tests/*.cc

clang_format:
	clang-format --style=google -i *.h
	clang-format --style=google -i class-methods/*.cc class-methods/*/*.cc
	clang-format --style=google -i tests/*.cc

build:
	@$(CC) $(OBJ_FLAGS) $(SOURCE)

main:
	@$(CC) $(CFLAGS) main.cc $(LIB_NAME) -o main && ./main

fsanitize_check: $(LIB_NAME)
	$(CC) -fsanitize=address $(CFLAGS) tests/test_matrix_oop.cc $(LIB_NAME) -lgtest -o $(EXECUTABLE) && ./$(EXECUTABLE)

valgrind_check: $(LIB_NAME)
	$(CC) $(CFLAGS) tests/test_matrix_oop.cc $(LIB_NAME) -lgtest -o $(EXECUTABLE)
	valgrind --leak-check=full -s -q --track-origins=yes ./$(EXECUTABLE)

.PHONY: all clean test s21_matrix_oop.a gcov_report style clang_format main build fsanitize_check valgrind_check
