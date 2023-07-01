# Sniffer

## Milestones
- [] Capturing Packets
- [] Packet Filtering
- [] Analyzing Packets
- [] Displaying Results
- [] Additional Features

## Prerequisites:
- G++
- Boost
- CMake
- GTest and GMock

## How to Build

 **Make Sure you installed all Prerequisites!**

 Inside folder run:
 ```
 mkdir build
 cd build
 cmake ..
 ```
After file generation run:
```
cmake --build .
```
Run program:
```
./Sniff
```

## How to contribute

### Making changes

Before making changes create your own local branch by:
```
git checkout -b "branch_name"
```

If you created new files you have to add them accordingly to examples
in CMakeLists.txt file (There are examples how to do it in proper way)

### How to commit
After adding all files to stage run:
```
git commit
```

Commit message style:
```
Commit title
 * bullet point1
 * bullet point2
 * ...
 ```
remember to run ```git pull --rebase``` after commiting, to sync with main branch

to create pull request run:
```
git push origin branch_name:github_nickname/pullRequestName
```
and go to repository page to create pull request


If all tests passes, pull request is ready to review, if it's still in progress convert it to draft

