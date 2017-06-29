CXX=g++
CXXFLAGS=-I. -std=c++11
LDFLAGS=

.PHONY: clean

test_maximum_profit: maximum_profit.cpp test/test_maximum_profit.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $(LDFLAGS) -DTEST -lcriterion $^ -o $@

test_insersion_sort: insersion_sort.cpp test/test_insersion_sort.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $(LDFLAGS) -DTEST -lcriterion $^ -o $@

test_bubble_sort: bubble_sort.cpp test/test_bubble_sort.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $(LDFLAGS) -DTEST -lcriterion $^ -o $@

test_selection_sort: selection_sort.cpp test/test_selection_sort.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $(LDFLAGS) -DTEST -lcriterion $^ -o $@

test_stable_sort: stable_sort.cpp test/test_stable_sort.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $(LDFLAGS) -DTEST -lcriterion $^ -o $@

test_shell_sort: shell_sort.cpp test/test_shell_sort.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $(LDFLAGS) -DTEST -lcriterion $^ -o $@

test_stack: stack.cpp test/test_stack.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $(LDFLAGS) -DTEST -lcriterion $^ -o $@

test_queue: queue.cpp test/test_queue.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $(LDFLAGS) -DTEST -lcriterion $^ -o $@

clean:
	$(RM) test_maximum_profit
