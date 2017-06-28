CXX=g++
CXXFLAGS=-I. -std=c++11
LDFLAGS=

.PHONY: clean

test_maximum_profit: maximum_profit.cpp test/test_maximum_profit.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $(LDFLAGS) -DTEST -lcriterion $^ -o $@

test_insersion_sort: insersion_sort.cpp test/test_insersion_sort.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $(LDFLAGS) -DTEST -lcriterion $^ -o $@

clean:
	$(RM) test_maximum_profit
