CXX=g++
CXXFLAGS=-I. -DTEST -std=c++11
LDFLAAGS=-lcriterion

.PHONY: clean

test_maximum_profit: maximum_profit.cpp test/test_maximum_profit.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@

clean:
	$(RM) test_maximum_profit
