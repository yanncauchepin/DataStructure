<p align="center">
  <img src="featured_image.png" alt="" width="80%">
</p>

---

# Data Structure

This code implements various data structure in low-level language :
- **Binary Search Tree** (BST) : Binary tree data structure where node has at most two children. Left child nodes are smaller and right child nodes are larger.
- **Hash Table** : Data structure that maps keys to values using a hash function. Provides constant-time average-case complexity for insertions, deletions, and lookups, making it efficient for storing and retrieving data. However, the performance of a hash table can degrade under certain conditions, such as a high collision rate or a poorly chosen hash function.
- **Linked list** : Linear data structure where each element contains a data field and reference to the next node. Linked lists come in various forms, such as singly linked lists, doubly linked lists, and circular linked lists. They offer dynamic memory allocation, efficient insertion and deletion operations, and sequential access. However, they have slower random access compared to arrays due to their lack of indexing.
- **Yale Format Compressed Sparse Row Matrix** (CSR) : Popular representation for sparse matrices, where most of the elements are zero. The matrix is stored as three arrays : the values array, the column index array, and the row pointer array.
- **Binary Tree Matrix** : Representation of a matrix using a binary tree data structure where each node in the three save the row and column coordinates with the corresponding value of the matrix. The splitting bewteen left and right is realised by a function which take into account both coordinates. The easiest function here is to first split by a single coordinate and then, in case of a tie, split by the second corrdinate. This format allows for efficient traversal and manipulation of the matrix, especially for sparse matrices where many elements are zero. However, it may not be as space-efficient as other sparse matrix formats.
- **Dictionay Of Keys Matrix** (DOK) : Sparse matrix where only non-zero elements are stored along with their coordinates as keys in a dictionary data structure. Each element"s value is associated with its corresponding row and column index. This format is suitable for dynamic construction of sparse matrices, offering fast insertion and retrieval operations without requiring pre-allocation of memory. However, it may not be as efficient for algebraic operations as other sparse matrix formats.

## Prerequisites

Before running this code, ensure you have the following :

- ***gcc*** compiler installed on your system.

## Usage

1. For each data structure represented in the folders **binary_search_tree**, **hash_table**, **linked_list** and **bst_yale_matrix**, the user must first navigate into the desired directory.
```bash
cd binary_search_tree
```
```bash
cd hash_table
```
```bash
cd linked_list
```
```bash
cd bst_yale_matrix
```

2. Navigate then to the **code** directory containing the source code and the ***Makefile*** file.
```bash
cd code
```
2. Compile the corresponding program by running ***make main***.
```bash
make main
```
3. The compiled program ***main*** is now located in the parent repository.
```bash
cd ..
```
4. Execute the compiled program by running ***./main***.
```bash
./main
```
*(Optional)* 5. Clean the repository by running ***make clean*** in the **code** directory.

```bash
cd code
make clean
```

## Monitor

For each implementation, the monitor is very similar : the user have to insert values until a critical value where the iterative scan is ending.

For data structure among **binary_search_tree**, **hash_table** and **linked_list**, the user have to inform :
- ***Value*** : Sequence of float until a critical value set to 0.

For data structure among **bst_yale_matrix**, the user have to iteratively inform :
- ***Row*** : Positive integer corresponding to the row index of the next value to insert.
- ***Column*** : Positive integer corresponding to the column index of the next value to insert.

If at least of those two variables is negative, the iterative monitor is ending. Otherwise, the user have then to inform for each valid coordinates :
- ***Value*** : Float corresponding to the value to insert.

### Exemple

For all data structure, a test file ***test.txt*** is located in the **test** directory to automatically insert values for the user, without using the monitor.
```bash
cd binary_search_tree
```
```bash
cd hash_table
```
```bash
cd linked_list
```
```bash
cd bst_yale_matrix
```
```bash
cd code
make main
cd ..
./main < test/test.txt
```