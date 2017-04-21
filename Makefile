.PHONY: clean

insertion: insertion.c
	gcc -o $@ $<

test_insertion: insertion.c test_insertion.c
	gcc -o $@ $^ -lcriterion -DTEST

clean:
	$(RM) test_insertion insertion
