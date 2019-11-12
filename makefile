INC=-l./include
.PHONY: run

a.out: main.cpp
	@g++ main.cpp test-add.cpp test-sub.cpp 
run: a.out
	@./a.out
clean:
	@rm -f a.out