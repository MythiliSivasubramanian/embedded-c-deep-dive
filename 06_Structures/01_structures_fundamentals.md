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

# How memory is allocated to Structure Members?

## Memory Allocation: Padding & Alignment

Structure padding is the compiler's insertion of unused bytes between members or at the end of a struct so that the members are placed at addresses that satisfy their alignment requirements.

To understand padding fully, we must look at it from two perspectives:

1. Compiler rules — how the memory layout is determined.
2. Hardware rationale — why alignment can be useful or required by the target architecture.

### Perspective 1: The Compiler View — Type Alignment Rules

The compiler does not simply pad everything to arbitrary word boundaries. Instead, each data type has an **alignment requirement** determined by the target architecture and ABI.

For our STM32/Cortex-M4 examples, we can use the following simplified assumptions:

```text
char      -> size 1 byte, alignment 1 byte
short     -> size 2 bytes, alignment 2 bytes
int       -> size 4 bytes, alignment 4 bytes
float     -> size 4 bytes, alignment 4 bytes
```

It is better to say **alignment requirement** rather than > "N bytes must start at an offset divisible by N."

That relationship is true for many common types on the systems we are studying, but it is not a universal rule of C. The actual alignment requirement is determined by the target implementation.

For example, assuming 4-byte alignment for `int`, suitable starting addresses are:

```text
0x1000
0x1004
0x1008
0x100C
...
```

because these addresses are aligned to a 4-byte boundary.

Now consider:

```c
struct Test
{
    char a;   // 1 byte
    int b;    // 4 bytes
    char c;   // 1 byte
};

struct Test var1;
```

Suppose `var1` starts at ```text 0x1000 ``. The compiler first places `a`. Since `char` has 1-byte alignment ```text 0x1000 -> a```
`a` occupies one byte, so the next available address is ```text 0x1001```

Now the compiler wants to place `b`. `b` is an `int`, and we are assuming that `int` requires 4-byte alignment. Therefore, `b` cannot start at ```text 0x1001 ```. The compiler inserts 3 bytes of padding so that `b` can start at the next correctly aligned address ```text 0x1004```

Therefore:

```text
0x1000 -> a
0x1001 -> padding
0x1002 -> padding
0x1003 -> padding
0x1004 -> b
0x1005 -> b
0x1006 -> b
0x1007 -> b
```

Now the next available address is ```text 0x1008 ``` The next member is `c`, which is a `char`. Since `char` has 1-byte alignment, it can be placed directly at `0x1008`. ```text 0x1008 -> c ```

So the structure currently looks like:

```text
Address     Content
────────────────────────
0x1000      a
0x1001      padding
0x1002      padding
0x1003      padding
0x1004      b
0x1005      b
0x1006      b
0x1007      b
0x1008      c
```

At this point, the members themselves occupy:

```text
a = 1 byte
padding = 3 bytes
b = 4 bytes
c = 1 byte

Total = 9 bytes
```

However, there can also be **padding at the end of the structure**, called **trailing padding**. This becomes important when we create an array of structures.

For example: ```c struct Test arr[2]; ```

If the first structure occupied only 9 bytes, the second structure would start 9 bytes after the first one. If the first structure started at:

```text
0x1000
```

the second structure would start at:

```text
0x1009
```

But `0x1009` is not 4-byte aligned.

Therefore, the compiler can add 3 bytes of trailing padding so that the size of the structure becomes 12 bytes:

```text
Address     Content
────────────────────────
0x1000      a
0x1001      padding
0x1002      padding
0x1003      padding

0x1004      b
0x1005      b
0x1006      b
0x1007      b

0x1008      c
0x1009      padding
0x100A      padding
0x100B      padding
```

Therefore:

```text
a       = 1 byte
padding = 3 bytes
b       = 4 bytes
c       = 1 byte
padding = 3 bytes
────────────────────
total   = 12 bytes
```

So, under these alignment assumptions:

```c
sizeof(struct Test)
```

would be:

```text
12 bytes
```

The important thing to understand is that the compiler is **not adding padding because it cannot physically store `b` immediately after `a`**.

It could physically store the bytes like this:

```text
0x1000 -> a
0x1001 -> b
0x1002 -> b
0x1003 -> b
0x1004 -> b
```

But then `b` would start at an address that does not satisfy its 4-byte alignment requirement.

Therefore, the compiler inserts padding:

```text
0x1000 -> a
0x1001 -> padding
0x1002 -> padding
0x1003 -> padding
0x1004 -> b
```

This is the fundamental reason padding exists.

---

### Perspective 2: The Hardware View

The reason alignment requirements exist is related to how the **target processor and memory system handle different types of accesses**.

It is tempting to say:

> "A 32-bit processor reads exactly 4 bytes in one CPU cycle, so an `int` must be aligned to 4 bytes."

This is **too simplistic and should not be used as our explanation**.

A 32-bit CPU does not necessarily perform every memory access as exactly one 32-bit transfer in exactly one CPU cycle. Memory accesses depend on the processor architecture, the instruction being executed, the bus, the memory system, wait states, and other factors.

Instead, think of it this way:

```text
Data type
    ↓
Alignment requirement
    ↓
Compiler places object at a suitable address
    ↓
Processor can perform the required access according
to the rules of the target architecture
```

For example, on our STM32 Cortex-M4, a naturally aligned 32-bit value starts at an address such as:

```text
0x20000000
0x20000004
0x20000008
0x2000000C
```

rather than:

```text
0x20000001
0x20000002
0x20000003
```

Unaligned accesses have architecture-specific behavior. Some can be supported, some may require additional handling, and some types of accesses can generate a fault.

Therefore, **padding is primarily a consequence of alignment requirements, not a simple CPU-cycle optimization technique.**

---


When the compiler lays out a structure, we can think about the process like this:

```text
Place the first member
        ↓
Look at the next member's alignment requirement
        ↓
Is the current address correctly aligned?
        ↓
   YES ─────────→ Place the member
        │
       NO
        ↓
Insert padding
        ↓
Move to the next correctly aligned address
        ↓
Place the member
        ↓
Continue with the remaining members
        ↓
Add trailing padding if required
```


For example, if the hardware specifies:

```text
MODER    offset 0x00
OTYPER   offset 0x04
OSPEEDR  offset 0x08
PUPDR    offset 0x0C
IDR      offset 0x10
ODR      offset 0x14
```

then our C structure must have the same layout:

```c
struct GPIO
{
    uint32_t MODER;      // offset 0x00
    uint32_t OTYPER;     // offset 0x04
    uint32_t OSPEEDR;    // offset 0x08
    uint32_t PUPDR;      // offset 0x0C
    uint32_t IDR;        // offset 0x10
    uint32_t ODR;        // offset 0x14
};
```

That is where **struct layout, alignment, padding, and memory-mapped hardware** all come together.

## How can we reduce structure padding?

Padding is sometimes necessary because of the alignment requirements of the members. Inorder to save the memory, we can reduce the amount of padding by carefully choosing the order of the structure members.

Consider:

```c
struct Test
{
    char a;
    int b;
    char c;
};
```

Assuming:

```text
char -> 1 byte, alignment 1
int  -> 4 bytes, alignment 4
```

If the structure starts at offset `0`:

```text

Offset   0──────3    4──────7    8    9──────11
         ┌────────┐ ┌────────┐ ┌───┐ ┌────────┐
         │a + P   │ │   b    │ │ c │ │   P    │
         └────────┘ └────────┘ └───┘ └────────┘
           4 bytes    4 bytes  1 B    3 bytes
           
a = member a
b = member b
c = member c
P = padding
```

So ```text sizeof(struct Test) = 12 bytes ```, Wehereas the actual data only requires ```text 1 + 4 + 1 = 6 bytes ``` but the structure occupies 12 bytes because of padding.

One way here to reduce the padding is to **order the members according to their alignment requirements**.

For example:

```c
struct Test
{
    int b;
    char a;
    char c;
};
```

Now the compiler can place the members like this:

```text

Offset    0    1    2    3    4    5    6    7
          ┌─────────────────┬────┬────┬────────┐
          │        b        │ a  │ c  │padding │
          └─────────────────┴────┴────┴────────┘
             4 bytes          1B   1B    2B
             
```

So ```text sizeof(struct Test) = 8 bytes ``` by reordering the members. Instead of ```text 12 bytes ``` which is before reordering the members. So simply changing the order of the members reduced the structure size from 12 bytes to 8 bytes.

---
