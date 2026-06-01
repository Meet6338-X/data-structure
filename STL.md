# Standard Template Library (STL) in C++

## Introduction
The Standard Template Library (STL) is a powerful set of C++ template classes to provide general-purpose classes and functions with templates that implement many popular and commonly used algorithms and data structures like vectors, lists, queues, and stacks.

## Components of STL
STL is divided into four main components:

1. **Algorithms** - Functions for performing operations on containers (sorting, searching, etc.)
2. **Containers** - Classes for storing data (vector, list, map, set, etc.)
3. **Iterators** - Objects that point to elements in containers and allow traversal
4. **Functions** - Function objects (functors) that can be used like functions

## Detailed Overview

### 1. Containers
Containers are holder objects that store collections of other objects.

#### Sequence Containers
- **vector**: Dynamic array with fast random access
- **deque**: Double-ended queue, efficient insertion/deletion at both ends
- **list**: Doubly linked list, efficient insertion/deletion anywhere
- **forward_list**: Singly linked list
- **array**: Fixed-size array (since C++11)

#### Associative Containers
- **set/multiset**: Sorted unique/non-unique elements (typically implemented as Red-Black trees)
- **map/multimap**: Sorted key-value pairs (unique/non-unique keys)

#### Unordered Associative Containers (since C++11)
- **unordered_set/unordered_multiset**: Hash table implementation for unique/non-unique elements
- **unordered_map/unordered_multimap**: Hash table for key-value pairs

#### Container Adapters
- **stack**: LIFO container adapter
- **queue**: FIFO container adapter
- **priority_queue**: Container adapter that provides constant time lookup of the largest (by default) element

### 2. Algorithms
Algorithms are functions that operate on ranges of elements defined by iterators.

#### Non-modifying Algorithms
- `find`, `find_if`, `find_if_not`: Search for elements
- `count`, `count_if`: Count occurrences
- `for_each`: Apply function to each element
- `equal`: Check if two ranges are equal
- `mismatch`: Find first mismatch between two ranges

#### Modifying Algorithms
- `copy`, `copy_if`, `copy_n`: Copy elements
- `move`, `move_if_noexcept`: Move elements (C++11)
- `swap`, `iter_swap`, `swap_ranges`: Swap elements
- `transform`: Apply function to elements and store result
- `replace`, `replace_if`: Replace elements
- `fill`, `fill_n`: Fill elements with value
- `generate`, `generate_n`: Generate elements using function

#### Removing Algorithms
- `remove`, `remove_if`: Remove elements (logically, returns new end iterator)
- `unique`: Remove consecutive duplicates
- `remove_copy`, `remove_copy_if`: Copy while removing elements

#### Mutating Algorithms
- `reverse`, `reverse_copy`: Reverse elements
- `rotate`, `rotate_copy`: Rotate elements
- `random_shuffle`, `shuffle`: Shuffle elements (random_shuffle deprecated in C++14, removed in C++17)
- `partition`, `stable_partition`: Partition elements based on predicate
- `shuffle`: Randomly shuffle using random number generator (C++11)

#### Sorting and Related Algorithms
- `sort`: Sort elements using operator< or custom comparator
- `stable_sort`: Sort while preserving relative order of equal elements
- `partial_sort`: Sort first N elements
- `nth_element`: Place Nth element in correct position
- `is_sorted`, `is_sorted_until`: Check if range is sorted

#### Sorted Range Algorithms
- `binary_search`: Check if element exists in sorted range
- `lower_bound`, `upper_bound`: Find bounds for insertion
- `equal_range`: Find both lower and upper bounds
- `merge`: Merge two sorted ranges
- `inplace_merge`: Merge two consecutive sorted ranges in-place
- `includes`: Check if one sorted range is subset of another

#### Numeric Algorithms
- `accumulate`: Sum elements
- `inner_product`: Compute inner product
- `partial_sum`: Compute partial sums
- `adjacent_difference`: Compute adjacent differences
- `iota`: Fill with sequentially increasing values (since C++11)

### 3. Iterators
Iterators are objects that point to elements within a container and allow traversal.

#### Iterator Categories
- **Input Iterator**: Read-only, single pass
- **Output Iterator**: Write-only, single pass
- **Forward Iterator**: Read/write, multiple passes, forward only
- **Bidirectional Iterator**: Forward and backward traversal
- **Random Access Iterator**: Full pointer arithmetic, constant time access to any element

#### Iterator Adaptors
- **reverse_iterator**: Iterate backwards
- **insert_iterator**: Insert elements while iterating (back_inserter, front_inserter, inserter)
- **move_iterator**: Convert dereferenced value to rvalue (C++11)
- **stream_iterator**: Iterate over streams (istream_iterator, ostream_iterator)

### 4. Function Objects (Functors)
Function objects are objects that can be called like functions.

#### Predicates
- Unary predicates: Take one argument, return bool
- Binary predicates: Take two arguments, return bool

#### Standard Functors (in <functional>)
- Arithmetic: `plus`, `minus`, `multiplies`, `divides`, `modulus`, `negate`
- Comparisons: `equal_to`, `not_equal_to`, `greater`, `less`, `greater_equal`, `less_equal`
- Logical: `logical_and`, `logical_or`, `logical_not`
- Bitwise: `bit_and`, `bit_or`, `bit_xor`, `bit_not`

#### Binders and Function Adaptors
- `bind`: Bind arguments to a function (since C++11)
- `function`: Type-erased function wrapper (since C++11)
- `mem_fn`: Create pointer to member function (since C++11)
- `ref`, `cref`: Reference wrappers (since C++11)

#### Lambda Expressions (since C++11)
Anonymous functions that can capture variables from surrounding scope.

### 5. Utility Components
- **pair**: Simple container for two values
- **tuple**: Fixed-size collection of heterogeneous values (since C++11)
- **array**: Fixed-size sequence container (since C++11)
- **bitset**: Fixed-size sequence of bits
- **valarray**: Array for numerical computations

### 6. Memory Allocators
Allocators abstract the memory model and allow containers to manage storage allocation and deallocation.

### Key Points to Remember
1. **Iterator Validity**: Operations on containers may invalidate iterators
2. **Complexity Guarantees**: STL specifies complexity requirements for operations
3. **Exception Safety**: Most STL operations provide basic or strong exception guarantee
4. **Thread Safety**: Concurrent read is safe, concurrent write requires synchronization
5. **Custom Comparators**: Use functors or lambdas for custom sorting/ordering
6. **Reserve and Capacity**: Use `reserve()` for vectors to avoid reallocations
7. **Associative Containers**: Keys must be comparable via `operator<` or custom comparator
8. **Unordered Containers**: Require hash function and equality predicate for keys

### Common Mistakes
1. Using `==` to compare iterators from different containers
2. Modifying a container while iterating without updating iterators properly
3. Assuming `list::operator[]` exists (it doesn't)
4. Using algorithms that require sorted ranges on unsorted data
5. Forgetting to include necessary headers (`<vector>`, `<algorithm>`, etc.)
6. Using `endl` excessively (use `'\n'` for better performance)
7. Not using `const_iterators` when appropriate
8. Assuming `unordered_*` containers maintain insertion order (they don't)

### Example Usage
```cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

int main() {
    // Vector example
    std::vector<int> numbers = {5, 2, 8, 1, 9};
    std::sort(numbers.begin(), numbers.end());
    
    // Map example
    std::map<std::string, int> ageMap;
    ageMap["Alice"] = 25;
    ageMap["Bob"] = 30;
    
    // Algorithm example
    auto it = std::find(numbers.begin(), numbers.end(), 8);
    if (it != numbers.end()) {
        std::cout << "Found: " << *it << std::endl;
    }
    
    // Lambda example
    std::for_each(numbers.begin(), numbers.end(), [](int n){
        std::cout << n << " ";
    });
    
    return 0;
}
```

## Conclusion
The STL is a fundamental part of modern C++ programming, providing efficient, reusable, and well-tested components. Mastery of STL enables writing concise, readable, and high-performance code.

---
*Note: This document covers the core aspects of STL as per C++11/14/17 standards. For the most current information, refer to the latest C++ standard documentation.*