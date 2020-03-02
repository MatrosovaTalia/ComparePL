# Results of benchmark execution

## Counting sort

| Metric | C | C++ | Java | JavaScript | Kotlin | Swift |
| ------ | - | --- | ---- | ---------- | ------ | ----- |
| Execution time(ms) | 0.001 | 0.167 | 1 | 0.946 | 0 | 0.333 |
| Max RSS Memory(kb) | 1656 | 3504 | 87904 | 28616 | 39832 | 111564 |
| Minor (frame) pf | 63 | 128 | 15217 | 6769 | 3918 | 10257 |
| Voluntary con. switches | 1 | 1 | 1385 | 48 | 456 | 8 |
| Involuntary con. switches | 0 | 0 | 441 | 45 | 52 | 27 |

## Insertion sort

| Metric | C | C++ | Java | JavaScript | Kotlin | Swift |
| ------ | - | --- | ---- | ---------- | ------ | ----- |
| Execution time(ms) | 0.0009 | 0.0009 | 8 | 4.678 | 8 | 2.961 |
| Max RSS Memory(kb) | 1728 | 3540 | 91440 | 29560 | 39892 | 111808 |
| Minor (frame) pf | 64 | 129 | 16679 | 6717 | 3938 | 10208 |
| Voluntary con. switches | 1 | 1 | 1451 | 40 | 484 | 12 |
| Involuntary con. switches | 0 | 1 | 630 | 34 | 136 | 22 |

## Merge sort

| Metric | C | C++ | Java | JavaScript | Kotlin | Swift |
| ------ | - | --- | ---- | ---------- | ------ | ----- |
| Execution time(ms) | 0.0001 | 0.0001 | 2 | 10.593 | 29 | 2.259|
| Max RSS Memory(kb) | 1644 | 3476 | 92592 | 31032 | 43692 | 113016 |
| Minor (frame) pf | 61 | 127 | 17112 | 7331 | 5030 | 10560 |
| Voluntary con. switches | 1 | 1 | 1400 | 37 | 485 | 18 |
| Involuntary con. switches | 0 | 0 | 695 | 50 | 127 | 14 |