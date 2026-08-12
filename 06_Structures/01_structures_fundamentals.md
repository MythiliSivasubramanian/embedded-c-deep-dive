## Structures

## 1. What is a struct?

Suppose we have a student:

```c
char name[20];
int age;
float height;
```

Without a **struct**, these are three separate variables, and each variable can be stored at a different address in memory. But logically, they all describe one student. A struct allows us to group different data types together into a single type. A **structure** is a user-defined data type that can be used to group elements of different data types into a single type.

```c
struct Student
{
    char name[20];
    int age;
    float height;
};
```

Now `struct Student` describes a new data type. We can create a variable ```c struct Student s1;```

Conceptually,

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

With the help of the `.` dot operator, we can access the members of a structure.

```c
s1.age = 25;
s1.height = 165.5;

printf("%d", s1.age);
```

The above `printf()` would print the value of `age`, assuming it has already been assigned.
Let's consider the below code snippet:

```c
struct Person
{
    int age;
    int salary;
};

struct Person p1;
```

Assuming `sizeof(int) = 4` and there is no padding, if `p1` starts at address `0x20000000`:

```text
p1 starts at 0x20000000

Address          Member
────────────────────────────
0x20000000       age  ─┐
0x20000001          │   │ 4 bytes
0x20000002          │   │
0x20000003       ───┘
────────────────────────
0x20000004       salary ─┐
0x20000005           │    │ 4 bytes
0x20000006           │    │
0x20000007       ────┘
```

So,

```text
p1.age    -> offset 0
p1.salary -> offset 4
```

**A struct's members occupy different memory locations, one after another, subject to padding and alignment.**

Suppose, to the above code snippet, we create ```c struct Person *ptr = &p1; ``` We know ```text ptr -> 0x20000000 ```

Now, instead of ```c p1.age ``` we can write ```c ptr->age ```
Here, `->` means that we have a pointer to a structure, and we want to access a member of the structure pointed to by that pointer.

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

`p1.age` and `(&p1)->age` are equivalent because `&p1` gives us the address of `p1`, which is a pointer to the structure.
Also, ```c ptr->age ``` is equivalent to ```c (*ptr).age``` because `*ptr` gives us the structure itself, and then `.` is used to access its member.

---

## struct vs union

```c
struct Example
{
    int a;
    int b;
};
```

A struct needs space for both `a` and `b`. If `int = 4 bytes`:

```text
struct Example
┌──────────────┐
│ a            │ 4 bytes
├──────────────┤
│ b            │ 4 bytes
└──────────────┘

Total = 8 bytes
```

Now change `struct` to `union`:

```c
union Example
{
    int a;
    int b;
};
```

A union is completely different. Both members of a union use the **same memory**.

```text
union Example

┌────────────────────┐
│                    │
│   a OR b           │
│   same memory      │
│                    │
└────────────────────┘
       4 bytes
```

```c
union Example u;
```

Then `u.a` and `u.b` refer to the same starting address.

A struct gives every member its own storage:

```text
a -> memory A
b -> memory B
c -> memory C
```

whereas a union lets all members share the same storage:

```text
a ──┐
b ──┼──> same memory
c ──┘
```

The size of a union is large enough to hold its largest member, taking alignment requirements into consideration.

This is one reason unions are useful when working close to hardware, because the same memory can be interpreted in different ways.

---

