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
5. The output provides the average run-time for the **insert** and **lookup** function.   
6. GitHub Actions runs 

## Run Locally

```bash
mkdir build && cd build
cmake ..
make
ctest --output-on-failure
```


## Sources Used
