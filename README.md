# Dictionary Benchmark

## Student Information
- Name: Kevin Rodriguez
- Student ID: 008858727
- repository: https://github.com/Pwingles/dictionary-benchmark 

## Structure
- `src/`: Contains `Dictionary` interface and `UnsortedVectorDict` implementation.
- `.github/workflows/test.yml`: GitHub Actions CI setup.

## How It Works

1. UnsortedVectorDict.cpp is complete and the main function contains the necessary code to test it. 
2. SortedVectorDict.cpp is complete and the main function contains the necessary code to test it.
3. UnsortedLinkedList.cpp is complete and the main function contains the necessary code to test it.
4. SortedLinkedList.cpp is complete and the main function contains the necessary code to test it
5. The output provides the average run-time for the **insert** and **lookup** and **remove** function.   
6. GitHub Actions runs 

## Run Locally

```bash
mkdir build && cd build
cmake ..
make
ctest --output-on-failure
```


## Sources Used
### Most of the code was written by me, Kevin Rodriguez
#### with help from:
### Adithya K's response:
on StackOverflow for inserting into a sorted vector (data.size() + index, value:
- https://stackoverflow.com/questions/46376120/how-to-insert-an-element-into-a-sorted-vector-using-binary-search

### ChatGPT for help with: 
- Figuring out SEGFAULT when attempting to update temp node simultaniously
with the traversing node. Making my insert fail.
- Debugging to an out of bound vector index when inserting into a sorted vector.


