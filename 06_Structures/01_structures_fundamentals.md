## Structures

## 1. What is a struct?

Suppose we have a student:

```c
char name[20];
int age;
float height;
```
Without a **struct**, these are three separate variables, each of these variables stored somewhere at different addresses in memrory. But logically, they all describe one student. A struct lets us to group different datatypes together.

```c
struct Student
{
    char name[20];
    int age;
    float height;
};
```
Now struct Student describes a new data type. We can create a variable ```c struct Student s1;```.  Conceptually, 

```text
s1
┌──────────────────────┐
│ name[20]             │
├──────────────────────┤
│ age                  │
├──────────────────────┤
│ height               │
└──────────────────────┘
```
**A struct stores all of its members at the same time.**

## 2. Accessing struct members

With the help of (.) dot operator, we can access the members of the Structure. ```c s1.age = 25; s1.height = 165.5; printf("%d", s1.age); ``` would print the age if already assigned. 


Lets consider the below code snippet:

```c
struct Person
{
    int age;
    int salary;
};

struct Person p1;
```
and assuming sizeof(int) = 4 and no padding, 

```text
p1 starts at 0x20000000

Address          Member
────────────────────────────
0x20000000       age  ─┐
0x20000001          │   │ 4 bytes
0x20000002          │   │
0x20000003       ───┘   │
────────────────────────
0x20000004       salary ─┐
0x20000005           │    │ 4 bytes
0x20000006           │    │
0x20000007       ────┘
```
So ,
```text
p1.age    → offset 0
p1.salary → offset 4
```
**A struct's members occupy different memory locations, one after another (subject to padding/alignment).**

Suppose, to the above code snippet, lets create ```c struct Person *ptr = &p1;``` We know, `ptr → 0x20000000` Now, instead of `p1.age`, we can write `ptr-> age`. Here `->`means that the pointer points to a struct. Go to that struct and access this member.

```text
ptr
 │
 │ 0x20000000
 ▼
┌─────────────────┐
│ age             │ ← ptr->age
├─────────────────┤
│ salary          │ ← ptr->salary
└─────────────────┘
```
**`p1.age` and `(&p1)->age`are equivalent. Because &p1 gives us a pointer to p1. And thats why  ptr -> age is also equivalent to (*ptr).age**