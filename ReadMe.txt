Traveling Salesman Problem

This program takes a file as input which contains cities and their latitude and longitude in the following format:
CITY NAME, DEGREES LAT. N, MINUTES LAT. N, DEGREES LONG. W, MINUTES LONG. W

It then returns a list of all of the cities to visit during a tour in the optimal order that minimizes distance. The tour will end on the first city visited.

If the amount of cities to visit is less than 32, it will provide a dynamic programming solution, which will be the correct, optimal solution. If the amount of cities to visit is greater than 32, it will create a minimum spanning tree (using Prim's algorithm) and will return the result of traversing that. This is an approximate solution, which will be no greater than 2 time the optimal solution. The dynamic programming solution has a runtime of O(2^n*n^2) and the minimum spanning tree solution has a runtime of O(n^2).

Possible optimizations/improvements:
Use Christofides Algorithm for the minimum spanning tree, which produces a result that is at most 1.5 times the optimal solution (however, it runs slightly slower, at O(n^3))

Create a base class that both TravelingSalesmanDP and TravelingSalesmanMST inherit from

Use a vector<> instead of a map<> for the optimal routes in TravelingSalesmanDP if we can guarantee that the maximum number of cities for the use of DP (in other words, the maximum number of cities we would want the correct result of) would never surpass 32.

Validate input file is formatted correctly

Ouput results to a file that is taken as input