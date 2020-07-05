
#  BSTinsert 

| Metric | JavaScript | Swift | C | Kotlin | Java | Dart | 
| - |  - |  - |  - |  - |  - |  - | 
| Execution time (ms) | 11.62397  | 14.65106  | 4.556192  | 25.96611  | 3.850934  | 2.627  | 
| Max RSS Memory(kb) | 29736  | 16360  | 1960  | 54068  | 85084  | 14052  | 
| Minor (frame) pf | 7049  | 882  | 138  | 7822  | 14987  | 2116  | 
| Voluntary con. switches | 28  | 0  | 0  | 130  | 602  | 2  | 
| Involuntary con. switches | 42  | 1  | 1  | 564  | 1833  | 6  | 

#  BSTremove 

| Metric | JavaScript | Swift | C | Kotlin | Java | Dart | 
| - |  - |  - |  - |  - |  - |  - | 
| Execution time (ms) | 7.908861  | 17.54605  | 1.776948  | 5.012103  | 3.448782  | 2.086  | 
| Max RSS Memory(kb) | 29488  | 16512  | 1992  | 54344  | 86296  | 14032  | 
| Minor (frame) pf | 7096  | 883  | 140  | 7862  | 14823  | 2121  | 
| Voluntary con. switches | 28  | 1  | 0  | 97  | 408  | 2  | 
| Involuntary con. switches | 39  | 0  | 1  | 518  | 1563  | 6  | 

#  countingSort 

| Metric | JavaScript | Swift | C | Kotlin | Java | Dart | C++ | 
| - |  - |  - |  - |  - |  - |  - |  - | 
| Execution time (ms) | 10.33302  | 0.284075  | 3.971354  | 4.250059  | 7.448454  | 1.764  | 0.557193  | 
| Max RSS Memory(kb) | 31072  | 16160  | 5616  | 51760  | 84828  | 14840  | 4088  | 
| Minor (frame) pf | 7401  | 872  | 1050  | 7143  | 15682  | 2241  | 234  | 
| Voluntary con. switches | 88  | 0  | 0  | 111  | 636  | 1  | 0  | 
| Involuntary con. switches | 37  | 1  | 1  | 467  | 1769  | 6  | 1  | 

#  gradientBitmapCalculator 

| Metric | JavaScript | Swift | C | Kotlin | Java | Dart | Go | 
| - |  - |  - |  - |  - |  - |  - |  - | 
| Execution time (ms) | 17.79160  | 2.979040  | 1.053587  | 76.4878  | 23.84044  | 48.817  | 3.193215  | 
| Max RSS Memory(kb) | 36860  | 14180  | 2700  | 39384  | 87380  | 31412  | 2912  | 
| Minor (frame) pf | 8778  | 844  | 307  | 3988  | 15199  | 6873  | 443  | 
| Voluntary con. switches | 14  | 0  | 0  | 47  | 527  | 20  | 5  | 
| Involuntary con. switches | 27  | 1  | 1  | 320  | 1436  | 37  | 36  | 

#  insertionSort 

| Metric | JavaScript | Swift | C | Kotlin | Java | Dart | C++ | 
| - |  - |  - |  - |  - |  - |  - |  - | 
| Execution time (ms) | 94.62543  | 22.53496  | 23.41938  | 32.77034  | 50.44921  | 199.819  | 15.0999  | 
| Max RSS Memory(kb) | 29672  | 16096  | 1708  | 50636  | 85848  | 13976  | 3640  | 
| Minor (frame) pf | 6883  | 802  | 74  | 6924  | 14922  | 2051  | 137  | 
| Voluntary con. switches | 37  | 7  | 2  | 131  | 600  | 17  | 1  | 
| Involuntary con. switches | 37  | 1  | 1  | 507  | 1445  | 6  | 1  | 

#  mergeSort 

| Metric | JavaScript | Swift | C | Kotlin | Java | Dart | C++ | 
| - |  - |  - |  - |  - |  - |  - |  - | 
| Execution time (ms) | 28.75392  | 13.38601  | 1.530770  | 25.82104  | 4.112910  | 8.339  | 1.63732  | 
| Max RSS Memory(kb) | 31912  | 15972  | 1760  | 54820  | 85700  | 16564  | 3628  | 
| Minor (frame) pf | 7670  | 809  | 83  | 7977  | 14452  | 2673  | 146  | 
| Voluntary con. switches | 12  | 0  | 1  | 136  | 656  | 3  | 0  | 
| Involuntary con. switches | 52  | 1  | 1  | 515  | 1779  | 7  | 1  | 

#  breadthFirstSearch 

| Metric | Swift | C | Kotlin | Java | 
| - |  - |  - |  - |  - | 
| Execution time (ms) | 18.91835  | 41.26676  | 28.01682  | 17.92338  | 
| Max RSS Memory(kb) | 18576  | 32900  | 85136  | 85480  | 
| Minor (frame) pf | 1943  | 7885  | 15652  | 14854  | 
| Voluntary con. switches | 5  | 1  | 123  | 586  | 
| Involuntary con. switches | 1  | 1  | 514  | 1423  | 

#  depthFirstSearch 

| Metric | Swift | C | Kotlin | Java | 
| - |  - |  - |  - |  - | 
| Execution time (ms) | 18.16016  | 2.528638  | 60.28435  | 73.90500  | 
| Max RSS Memory(kb) | 18532  | 17272  | 43864  | 86100  | 
| Minor (frame) pf | 1957  | 3973  | 5069  | 15139  | 
| Voluntary con. switches | 2  | 0  | 48  | 432  | 
| Involuntary con. switches | 1  | 1  | 301  | 1585  | 

# Execution modes

| Language | Mode |
| -------- | ---- |
| JavaScript | Node.js (execution runtime and V8 JIT compiler) |
| Swift | Swift compiler |
| C | GCC compiler |
| C++ | G++ compiler|
| Kotlin | kotlinc compiler and Java Runtime Environment |
| Java | Java Runtime Environment |
| Dart | dart2native compiler |
| Go | Go compiler |

