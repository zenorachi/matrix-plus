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
	@cp ../materials/linters/.clang-format .
	clang-format -n *.h
	clang-format -n class-methods/*.cc class-methods/*/*.cc
	@rm .clang-format

clang_format:
	@cp ../materials/linters/.clang-format .
	clang-format -i *.h
	clang-format -i class-methods/*.cc class-methods/*/*.cc
	@rm .clang-format

build:
	@$(CC) $(OBJ_FLAGS) $(SOURCE)

main:
	@$(CC) $(CFLAGS) $(SOURCE) main.cc -o test

fsanitize_check: $(LIB_NAME)
	$(CC) -fsanitize=address $(CFLAGS) tests/test_matrix_oop.cc $(LIB_NAME) -lgtest -o $(EXECUTABLE) && ./$(EXECUTABLE)

valgrind_check: $(LIB_NAME)
	$(CC) $(CFLAGS) tests/test_matrix_oop.cc $(LIB_NAME) -lgtest -o $(EXECUTABLE)
	valgrind --leak-check=full -s -q --track-origins=yes ./$(EXECUTABLE)

.PHONY: all clean test s21_matrix_oop.a gcov_report style clang_format main build fsanitize_check valgrind_check
