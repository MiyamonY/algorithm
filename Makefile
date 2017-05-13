.PHONY: clean

CC=gcc
TEST_ARGS:=-lcriterion -DTEST -I.
LDFLAGS += -lm

koch_curve: koch_curve.c
	$(CC) -o $@ $< $(LDFLAGS)

test: test_insertion test_gcd test_bubble

test_insertion: insertion.c test/test_insertion.c
	gcc -o $@ $< $(TEST_ARGS)

test_gcd: gcd.c test/test_gcd.c
	gcc -o $@ $^ $(TEST_ARGS)

test_bubble: bubble.c test/test_bubble.c
	gcc -o $@ $^ $(TEST_ARGS)

test_selection: selection.c test/test_selection.c
	gcc -o $@ $^ $(TEST_ARGS)

test_stable: stable.c test/test_stable.c
	gcc -o $@ $^ $(TEST_ARGS)

test_stack: stack.c test/test_stack.c
	gcc -o $@ $^ $(TEST_ARGS)

test_queue: queue.c test/test_queue.c
	gcc -o $@ $^ $(TEST_ARGS)

test_double_linked_list: double_linked_list.c test/test_double_linked_list.c
	gcc -o $@ $^ $(TEST_ARGS)

test_linear_search : linear_search.c test/test_linear_search.c
	gcc -o $@ $^ $(TEST_ARGS)

test_binary_search : binary_search.c test/test_binary_search.c
	gcc -o $@ $^ $(TEST_ARGS)

test_dictionary : dictionary.c test/test_dictionary.c
	gcc -o $@ $^ $(TEST_ARGS)

test_exhaustive_search: exhaustive_search.c test/test_exhaustive_search.c
	gcc -o $@ $^ $(TEST_ARGS)

test_koch_curve: koch_curve.c test/test_koch_curve.c
	gcc -o $@ $^ $(TEST_ARGS) -lm

clean:
	$(RM)  insertion gcd test_gcd test_insertion test_bubble test_selection
