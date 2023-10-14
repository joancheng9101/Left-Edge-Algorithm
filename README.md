# Left-Edge-Algorithm
## Program
### Use Left-Edge Algorithm to minimize the resource usage.
#### Sort intervals in a list by their left edge coordinates.
#### Consider one color at a time and assign as many intervals as possible to the color by scanning the list.
#### Increase color counter when possible intervals are exhausted, and repeat.
##  Problem statement
### You are given a sequencing graph consisting of 𝑣 vertices including two NOP nodes which are the source and sink.
### The vertices are numbered from 0 to 𝑛 (i.e, 𝑛 = 𝑣 − 1 ), the source is the vertex 0 and the sink is the vertex 𝑛.
### Each vertex represents an operation with specific period.
### What’s the minimum usage of resources of this graph?
![problem](./img/p1.png)
## Input
### The first line contains two integers 𝑣 and 𝑟 (where 2 < 𝑣 < 100, 0 < 𝑟 < 5) denoting the number of vertices (from 0 to 𝑣 − 1) in the sequencing graph and the number of resource types provided (from 1 to 𝑟).
### Following 𝑣 lines show the information of an adjacent matrix, where the non-zero element in each line denotes a directed edge (r, c) from 𝑣𝑟 to 𝑣𝑐 .
### 𝑣 lines follow. The 𝑖-th line contains three integers 𝑟𝑖, 𝑡1𝑖 and 𝑡2𝑖 denoting that the 𝑖-th vertex uses the 𝑟𝑖-resource type and its period is 𝑡1𝑖 to 𝑡2𝑖.
### Note that the resource type of 𝑣0 and 𝑣n are always marked 0 (NOP). 
## Output
### You need to iterative report the number of resource 𝑟𝑖 used in this sequencing graph following sequences of vertices shared these resource.
### You need to output your report to a file named with benchmarkName.txt
## Example
### Input
![input](./img/p2.png)
### Output
![output](./img/p3.png)
