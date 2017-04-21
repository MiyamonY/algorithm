.PHONY: clean

TEST_ARG:=-lcriterion -DTEST

insertion: insertion.c
	gcc -o $@ $<

test_insertion: insertion.c test_insertion.c
	gcc -o $@ $^ $(TEST_ARG)

gcd: gcd.c
	gcc -o $@ $<

test_gcd: gcd.c test_gcd.c
	gcc -o $@ $^ $(TEST_ARG)

clean:
	$(RM)  insertion gcd test_gcd test_insertion
