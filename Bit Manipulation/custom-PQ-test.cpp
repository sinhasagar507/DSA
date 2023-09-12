	// Prim's Algorithm for MST 
	// : O(V+E)
	
#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii; // Represents (node, weight) pair 
#define INF INT_MAX 

struct Triple 
{ 
	int a;
	int b; 
	int c; 
	 
	// Constructor
	Triple(int a, int b, int c)
	{
		this->a=a; 
		this->b=b; 
		this->c=c; 
	}
}; 

struct CustomComparator
{
	bool operator()(const Triple& x, const Triple& y){
		return x.a > y.a;
	}
};

int main()
{ 
	priority_queue<Triple, vector<Triple>, CustomComparator> pq;
	pq.push(Triple(1, 0, -3)); 
	pq.push(Triple(0, 1, 1)); 
    return 0;
}

// #include <queue>
// #include <vector>
// 
// struct MyStruct {
    // int firstElement;
    // int secondElement;
    // int thirdElement;
// 
    // // Define a constructor if needed
    // MyStruct(int first, int second, int third) : firstElement(first), secondElement(second), thirdElement(third) {}
// };
// 
// struct CustomComparator {
    // bool operator()(const MyStruct& a, const MyStruct& b) {
        // // Compare based on the first element of the structure
        // return a.firstElement > b.firstElement;  // Ascending order
    // }
// };
// 
// int main() {
    // std::priority_queue<MyStruct, std::vector<MyStruct>, CustomComparator> pq;
// 
    // // Insert elements into the priority queue
    // pq.push(MyStruct(5, 1, 2));
    // pq.push(MyStruct(2, 3, 4));
    // pq.push(MyStruct(8, 2, 1));
// 
    // // Retrieve and print elements
    // while (!pq.empty()) {
        // MyStruct topElement = pq.top();
        // // Print or use the elements as needed
        // pq.pop();
    // }
// 
    // return 0;
// }
// 