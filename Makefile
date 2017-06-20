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

test_merge_sort: merge_sort.c test/test_merge_sort.c
	gcc -o $@ $^ $(TEST_ARGS)

test_partition: partition.c test/test_partition.c
	gcc -o $@ $^ $(TEST_ARGS)

test_quick_sort: quick_sort.c test/test_quick_sort.c
	gcc -o $@ $^ $(TEST_ARGS)

test_counting_sort: counting_sort.c test/test_counting_sort.c
	gcc -o $@ $^ $(TEST_ARGS)

test_rooted_tree: rooted_tree.c test/test_rooted_tree.c
	gcc -o $@ $^ $(TEST_ARGS)

test_binary_tree: binary_tree.c test/test_binary_tree.c
	gcc -o $@ $^ $(TEST_ARGS)

test_tree_walk: binary_tree.c test/test_tree_walk.c
	gcc -o $@ $^ $(TEST_ARGS)

test_binary_search_tree: binary_search_tree.c test/test_binary_search_tree.c
	gcc -o $@ $^ $(TEST_ARGS) -Wl,-wrap,malloc,-wrap,free

test_complete_binary_tree: complete_binary_tree.c test/test_complete_binary_tree.c
	gcc -o $@ $^ $(TEST_ARGS)

test_maximum_heap: maximum_heap.c test/test_maximum_heap.c
	gcc -o $@ $^ $(TEST_ARGS)

test_fibonacchi_number: fibonacchi_number.c test/test_fibonacchi_number.c
	gcc -o $@ $^ $(TEST_ARGS)

test_longest_common_subsequence: longest_common_subsequence.c test/test_longest_common_subsequence.c
	gcc -o $@ $^ $(TEST_ARGS)

clean:
	$(RM)  insertion gcd test_gcd test_insertion test_bubble test_selection
