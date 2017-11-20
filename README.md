# Dijkstra-Algorithm-with-variable-edge-cost
A program can calculate OSPF with variable edge cost and consider edge loading

### How to compile 
If you are using UNIX/Linux environment, you can use our makefile to compile code easily.

```bash
make
```

If you want to clean the object files and executable files, you can just type:

```bash
make clean
```

then makefile will delete object files and executable files for you.

#### Notes
We try our best to use POSIX header files to develop our program, but we still use 
```C
limit.h
```
to develop program. If your computer doesn't have this header file, please install it by youself.


### How to use this program
After compiling, you can get a executable files named as ```DJ_Algorithm_EXE```, you can run it like this:
```bash
./DJ_Algorithm_EXE
```
First of all, our program will guide you to build up your topology. 
After building topology, program will ask you to enter routing information such as start node and end node. Program will calculate the shortest path based on Dijkstra algorithm. 

### Our features
#### Dynamic routing calculation
Of course, program will store the routes you entered before. When you ever enter a new routing information, program may not only calculate new routing information's path but also re-calculte old routing informations path.




