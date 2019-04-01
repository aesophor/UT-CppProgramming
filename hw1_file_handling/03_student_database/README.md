## Student Database
A simple student database which...
* keeps track of each student's scores
* displays the average/highest score of each course
* import/export database

## Complexity Analysis
What if there are a lot of students in this database? What's the time complexity to find a student in the database?

* std::vector<Student> and **Linear Search**
  * the time complexity of finding a student is O(n).

* If Student::id exists, then **Binary Search** can be used
  * but the time complexity to find a student is still O(log n).

* std::unordered_map and **Random Access** 
  * enables the user to find a specific student in O(1) time (average case).
  
Therefore I chose std::unordered_map as the underlying data structure (I know it's an overkill here)

## Run
```
$ make
$ make run
```

## Result
Tested on linux (4.14.83-gentoo)
```
Student Database
================
(1) Add course
(2) Add student
(3) Import from...
(4) Export to...

Student	 C++	Java	
Marco	 95	  98	
Tim	 99	  50	
Dave	 44	  66	
C++ avg: 79.3333 highest: 99
Java avg: 71.3333 highest: 98

> 
```
