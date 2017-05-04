.PHONY: clean

TEST_ARGS:=-lcriterion -DTEST -I.

insertion: insertion.c
bubble: bubble.c
selection: selection.c
gcd: gcd.c

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

clean:
	$(RM)  insertion gcd test_gcd test_insertion test_bubble test_selection
