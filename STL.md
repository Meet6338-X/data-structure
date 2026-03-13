#include<math.h>
#include<string.h>

all library in #include<bits/stdc++.h>

using namespace std;

void - don't return anything

int - return number

##example int sum(int a,int b){return a+b}

cout -- prints

STL is divided into 4 parts
Algorithms
Containers
Functions
Iterators

//Pairs
we can store couple of integers
using pair<int,int> p = {1,3};
p.first = 1
p.second = 3

pair <int , pair<int,int>> p = {1,{3,4}};
p.second.second = 4
p.first = 1

we can also use array in pair
like pair<int,int> arr[] = {{1,2},{
2,5},{5,1}};
arr[1].second = 5

//Vector
declare
vector<int> v; create emty container

emplace_back(2) - dynamically with curle brackets
push_back(1) - only single element in end increase size

vector<int> v(5,100)
-output = {100,100,100,100,100}

call like arr v[1] = 100;

vector<int>::iterator it = v.brgin();
