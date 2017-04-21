.PHONY: clean

TEST_ARG:=-lcriterion -DTEST -I.

insertion: insertion.c
bubble: bubble.c
gcd: gcd.c


test: test_insertion test_gcd test_bubble

test_insertion: insertion.c test/test_insertion.c
	gcc -o $@ $< $(TEST_ARG)

test_gcd: gcd.c test/test_gcd.c
	gcc -o $@ $^ $(TEST_ARG)

test_bubble: bubble.c test/test_bubble.c
	gcc -o $@ $^ $(TEST_ARG)

clean:
	$(RM)  insertion gcd test_gcd test_insertion test_bubble
