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

## How does the compiler decide where padding goes?

**what exactly does the compiler look at when it decides to insert padding?**
The compiler mainly looks at two things for each member:

-   Size — how many bytes does the structure member occupy?
-   Alignment requirement — at which offsets is the structure member allowed to start?

For our STM32/Cortex-M4 examples, we'll assume:
```text

Type       Size       Alignment
────────────────────────────────
char       1 byte     1 byte
short      2 bytes    2 bytes
int        4 bytes    4 bytes
float      4 bytes    4 bytes
double     8 bytes    8 bytes

The most important column for calculating padding is alignment.
```
**The basic rule :**

Suppose the compiler is currently at some offset.
It asks: "Can the next member start at this offset according to its alignment requirement?"
    -   If yes → put the member there.
    -   If no → insert padding until we reach a suitable offset.

**Example 1 — No padding**
```c
struct Test
{
    int a; // 4 bytes
    int b;  // 4 bytes
};
```
Assume: int = 4 bytes and int alignment = 4.  Lets also assume that the structure starts at offset 0.

Inorder to place `a` in memory, the compiles requires 2 things (1. size, 2. Alighment requirement). The Size of `a`is 4 bytes. Is offset `0` suitable for a 4-byte-aligned object? Yes. So it places `a`in memory.

```text
Offset    0    1    2    3
          ┌─────────────────┐
          │        a        │
          └─────────────────┘
          
Now, current offset is 4. 
```
`b` also needs 4-byte alignment. Again the same 2 questions (1. size, 2. Alighment requirement). Size is 4 and Is the offset 4 suitable? Yes. 

```text
Offset    0──────3    4──────7
          ┌────────┐ ┌────────┐
          │   a    │ │   b    │
          └────────┘ └────────┘
```
Therefore: sizeof(struct Test) = 8. No padding.


** Example 2 — Padding appears :**

```c
struct Test
{
    char a;
    int b;
};
```

Assume:

char → size 1, alignment 1
int  → size 4, alignment 4
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

### Why does changing the order help?

The idea is to place members with larger alignment requirements before members with smaller alignment requirements.

For example:

```text
8-byte aligned members
        ↓
4-byte aligned members
        ↓
2-byte aligned members
        ↓
1-byte aligned members
```

For example:

```c
struct Example
{
    double   a;
    int      b;
    short    c;
    char     d;
};
```

Conceptually:

```text
double → 8-byte alignment
int    → 4-byte alignment
short  → 2-byte alignment
char   → 1-byte alignment
```

This ordering often minimizes unnecessary gaps between members.

But it is important to say **often**, not always. The exact layout depends on the target compiler, ABI, alignment rules, and any packing directives.

Assume the structure starts at offset 0.

```text
Offset    0    1    2    3    4    5    6    7    8    9    10   11   12   13   14   15
          ┌───────────────────────────────┬───────────────────────┬───────────┬───────────┐
          │             double a          │         int b         │  short c  │   char d  │
          │            8 bytes            │       4 bytes         │  2 bytes  │   1 byte  │
          └───────────────────────────────┴───────────────────────┴───────────┴───────────┘

So the offsets are:

a → offset 0
b → offset 8
c → offset 12
d → offset 14

```

There is no padding between the members in this particular layout. After d, we have used `8 + 4 + 2 + 1 = 15 bytes`. But the structure's alignment is 8 because of double. Therefore, the total structure size is rounded up to the next multiple of 8: `15 → 16`. So there is 1 byte of trailing padding.

```text
Offset    0    1    2    3    4    5    6    7    8    9    10   11   12   13   14   15
          ┌───────────────────────────────┬───────────────────────┬───────────┬────┬───────┐
          │             double a          │         int b         │  short c  │ d  │   P   │
          │            8 bytes            │       4 bytes         │  2 bytes  │1 B │  1 B  │
          └───────────────────────────────┴───────────────────────┴───────────┴────┴───────┘
```
Therefore `sizeof(struct Example) = 16 bytes`

Now lets compare with a bad ordering. Suppose we write:

```c
struct Example
{
    char   d;
    short  c;
    int    b;
    double a;
};

```
The compiler has to insert padding to satisfy the alignment requirements:

```text

Offset    0    1    2    3    4    5    6    7    8    9    10   11   12   13   14   15
          ┌────┬────┬───────────┬───────────────────────┬───────────────────────────────┐
          │ d  │ P  │  short c  │         int b         │           double a            │
          │1 B │1 B │  2 bytes  │       4 bytes         │           8 bytes             │
          └────┴────┴───────────┴───────────────────────┴───────────────────────────────┘
```

In this particular example, it still happens to occupy 16 bytes, because the members naturally fit into the 16-byte layout. But with other combinations of members, poor ordering can create much more padding.

**To reduce padding, members with larger alignment requirements are generally placed before members with smaller alignment requirements.This is a practical layout rule, not a requirement of the C language. The exact result depends on the target ABI/compiler.**

---


# What else can affect padding?

Apart from order of members (as discussed in detail above, small quick example below), there are other things that can affect the layout.

### 1. Member ordering

This is the normal way to reduce padding.

For example:

```c
struct A
{
    char a;
    int b;
    char c;
};
```

may require more padding than:

```c
struct B
{
    int b;
    char a;
    char c;
};
```

Both structures contain exactly the same data, but their memory layouts can be different.

---

### 2. Using appropriate data types

The sizes and alignment requirements of the members affect padding.

For example:

```c
struct Example
{
    char a;
    int b;
    char c;
};
```

has different layout requirements from:

```c
struct Example
{
    char a;
    short b;
    char c;
};
```

because `short` generally has a smaller alignment requirement than `int`.

So choosing the correct data type can sometimes reduce padding.

However, **we should never change a data type just to reduce padding if the data actually requires the original type**.

For example, don't change:

```c
uint32_t counter;
```

to:

```c
uint16_t counter;
```

just to save two bytes if the counter can actually need values larger than 65535.

---

### 3. Bit-fields

Bit-fields can allow several small pieces of information to occupy individual bits within the same storage unit.

For example:

```c
struct Flags
{
    unsigned int ready : 1;
    unsigned int error : 1;
    unsigned int busy  : 1;
};
```

Instead of giving each flag a whole `unsigned int`, the compiler can place them into bits of the same storage unit.

Conceptually:

```text
31                         3  2    1     0
┌───────────────────────────┬────┬─────┬─────┐
│                           │busy│error│ready│
└───────────────────────────┴────┴─────┴─────┘
```

This can save space.

**But bit-fields are a separate topic**, and they have implementation-dependent layout details. For embedded hardware registers, we need to be particularly careful with them.

---

### 4. Packed structures

Some compilers provide a way to tell the compiler to reduce or eliminate padding.

For example, GCC provides:

```c

struct __attribute__((packed)) Example
{
    char a;
    int b;
    char c;
};

```

This can produce a layout such as:

```text

Offset    0    1    2    3    4    5
          ┌────┬───────────────┬────┐
          │ a  │       b       │ c  │
          │1 B │     4 bytes   │1 B │
          └────┴───────────────┴────┘
          
```

So the structure may occupy ```text 6 bytes``` instead of 12. However, packed structures should not be treated as a general better version of a struct. Because they can create unaligned members.

For example:

```text
a       → offset 0
b       → offset 1   ← int is now unaligned
```

And that can have consequences for performance or even correctness on some architectures.

So > **Don't use packing simply because we want to save RAM.** Use it when we specifically need a tightly packed memory representation, such as certain binary formats or protocol layouts, and we understand the target architecture's requirements.

---

### Application Structures vs hardware-register structures :

Lets see the distinction between normal application structures and hardware-register structures.

Suppose we have:

```c
struct Person
{
    char name[20];
    int age;
    float height;
};
```

Here, reducing padding can be useful because we're simply trying to store data efficiently.

But imagine:

```c
struct GPIO
{
    uint32_t MODER;
    uint32_t OTYPER;
    uint32_t OSPEEDR;
    uint32_t PUPDR;
};
```

Here, **we don't care about reducing padding**.

We care about this:

```text
GPIO base + 0x00 → MODER
GPIO base + 0x04 → OTYPER
GPIO base + 0x08 → OSPEEDR
GPIO base + 0x0C → PUPDR
```

The hardware has already decided where the registers are. So if padding were somehow required to reproduce those offsets, then we would keep the padding.

For example, suppose the hardware looked like:

```text
0x00 → REGISTER_A
0x04 → REGISTER_B
0x08 → REGISTER_C
0x0C → REGISTER_D
```

Then we want:

```c
struct Peripheral
{
    uint32_t REGISTER_A;
    uint32_t REGISTER_B;
    uint32_t REGISTER_C;
    uint32_t REGISTER_D;
};
```

We are not trying to make this structure smaller. We are trying to make the C structure's memory layout exactly match the hardware memory map.

---

### #pragma

#pragma is a preprocessor directive in C. It is used to give special instructions to the compiler.
Unlike normal C statements such as ```c int x; x = 10;``` a #pragma does not represent an operation that the CPU executes. Instead, it tells the compiler to do something in a particular way. The important thing is that #pragma is compiler-dependent. Different compilers can support different #pragma directives.

For example, GCC, ARM GCC, MSVC, and other compilers may provide different pragmas.

#### #pragma pack

For our current topic, the important one is ```c #pragma pack``` It can be used to control the maximum alignment of structure members, which can change the amount of padding inserted by the compiler.


Consider:
```c
struct Test
{
    char a;
    int b;
    char c;
};
```
Assuming normal alignment: `char → 1-byte alignment, int  → 4-byte alignment `

We get :
```text
Offset    0    1────3    4────7    8    9────11
          ┌───┬────────┬────────┬───┬────────┐
          │ a │padding │   b    │ c │padding │
          │1B │  3 B   │  4 B   │1B │  3 B   │
          └───┴────────┴────────┴───┴────────┘
```
So `sizeof(struct Test) = 12 bytes`. Now suppose we tell the compiler `#pragma pack(1)`, then this tells a compiler that supports this directive to use a maximum member alignment of 1 byte for the packed structure.
```c
struct Test
{
    char a;
    int b;
    char c;
};
```
can be laid out as:
```text
Offset    0    1────4    5
          ┌───┬────────┬───┐
          │ a │   b    │ c │
          │1B │  4 B   │1B │
          └───┴────────┴───┘
```
Now `sizeof(struct Test) = 6 bytes`. So `Normal alignment → 12 bytes, Packed alignment → 6 bytes`

The important thing is that the padding has not been magically removed from memory after compilation. Rather, the compiler was instructed to use different alignment rules when laying out that structure.
But there is a danger. 

With normal alignment:
```text
Offset    0    1────3    4────7
          ┌───┬────────┬────────┐
          │ a │padding │   b    │
          └───┴────────┴────────┘
```
b starts at offset 4. So if the structure starts at `b → 0x20000004`, which is properly 4-byte aligned.
With packing:
```text
Offset    0    1────4    5
          ┌───┬────────┬───┐
          │ a │   b    │ c │
          └───┴────────┴───┘
``` 
b starts at offset 1. If the structure starts at `0x20000000`, then `b → 0x20000001`. Now b is unaligned. That's why packing isn't simply, we would use pragma pck with caution. 

### #pragma pack is not part of standard C

```c #pragma pack(1)``` is not a standard C feature with identical behavior on every compiler. It is a compiler-specific extension.
For example, GCC/Clang also provide other mechanisms such as: ```__attribute__((packed))``` while other compilers have their own syntax.
So if we see: ```c #pragma pack(1)``` we  should immediately think, this is a compiler-specific instruction controlling structure layout/alignment.

### Why is this relevant to Embedded C?

**We have two very different situations.

**Normal data structure**

We might want to reduce memory usage:
```c
struct SensorData
{
    char status;
    int value;
    char error;
};
```
Here, changing member order may reduce padding naturally.
We generally prefer this:
```text
    reorder members
        ↓
reduce padding
        ↓
keep normal alignment
```
rather than immediately using packing.

**Hardware registers** for STM32 peripheral registers, our goal is not to make the structure as small as possible. Rather our goal is to 
make the structure layout exactly match the hardware register addresses.

For example:
```c
struct GPIO
{
    uint32_t MODER;     // 0x00
    uint32_t OTYPER;    // 0x04
    uint32_t OSPEEDR;   // 0x08
    uint32_t PUPDR;     // 0x0C
    uint32_t IDR;       // 0x10
    uint32_t ODR;       // 0x14
};
```
Here every member is naturally 4-byte aligned, so we don't need packing at all.

**Array vs Structure**

Both Array and Structure have contiguous block of memory. Array is the group of same type of elements, whereas Structure is a user defined type, which allows us to group elements of different data types. 

For example,  ```C int arr[3];``` in memory represented conceputally as 
```text
Offset:   0        1        2       3 4        5        6     7  8        9        10     11
          ┌──────────────────────────┬──────────────────────────┬──────────────────────────┐
          │         arr[0]           │         arr[1]           │         arr[2]           │
          │  0       1       2      3│  4       5       6      7│  8       9       10    11│
          └──────────────────────────┴──────────────────────────┴──────────────────────────┘

There cannot be gap betwen arr[0] and arr[1]

```
So, address of arr[1] = address of arr[0] + sizeof (type(int)) and similarly add[2] = address of arr[1] + sizeof(int). Thats why, 
`arr[i] = *(arr + i)`. The compiler knows that every element has the same size.

Now, lets consider a Structure.

```c
struct Test
{
    char a;
    int  b;
    char c;
};
```
Here, the members are of different type and has different alignment. char requires 1 byte and has 1 byte alignment, int occupies 4 bytes and has 4 byte alignment. Now the compiler has to satisfy the alignment requirement of each individual member. Hence the structure contains padding inside itself.

In Array, its elements are placed immediately after the previous element, whereas in Structure, each element is placed at an offset that satisfies that member's alignment requirement.

```text
ARRAY
─────────────────────────────────────────

Element 0 | Element 1 | Element 2
           ↑
           No gap


STRUCTURE
─────────────────────────────────────────

Member A | Padding | Member B | Member C
                    ↑
                    Padding may be required because members have different alignments.


ARRAY OF STRUCTURES
─────────────────────────────────────────

┌──────────── struct 0 ────────────┐
│ members + internal/trailing pad  │
└──────────────────────────────────┘
┌──────────── struct 1 ────────────┐
│ members + internal/trailing pad  │
└──────────────────────────────────┘
```

## structure assignment

```c
struct Person
{
    int age;
    int salary;
};

struct Person p1;
struct Person p2;

p1.age = 25;
p1.salary = 3000;

```
So conceptually,

```text
p1
┌──────────────┐            
│ age    = 25  │
├──────────────┤
│ salary = 3000│
└──────────────┘

p2
┌──────────────┐
│ age          │
├──────────────┤
│ salary       │
└──────────────┘

```
Now, wehen we do **structure assignment**, ```c p2 = p1;``` The result is,

```text
p1                         p2
┌──────────────┐           ┌──────────────┐
│ age    = 25  │  ───────► │ age    = 25  │
├──────────────┤           ├──────────────┤
│ salary = 3000│  ───────► │ salary = 3000│
└──────────────┘           └──────────────┘
```
**The values of the members are copied.** Here it doesnot mean, that p1 is pointing to p2. They remain two independent objects. If we do, ```c p2.age = 40``` then p1.age is 25 and p2.age is 40. So the assignment copied the structure's value, not its address. Structure assignment creates a separate copy of the member values.

Now, lets quickly consider an another example with Structure padding:
```c
struct Test
{
    char a;
    int b;
    char c;
};

struct Test t1;
struct Test t2;

t1.a = 10;
t1.b = 20;
t1.c = 30;

t2 = t1;
```
Here, the size of the structure = char a (1 byte) + 3 bytes padding + int b(4 bytes) + char c(1 byte) + 3 bytes padding = 12 bytes.
So, when we do structure assignment, ie ```c t2 = t1```, will the entire 12 bytes(including structure padding) be copied?? We are sure that, the actual values of a,b and c will be copied from t1 to t2. But what about the structure padding layout and the contents/ values inside the Structure padding bytes? 

The contents of the padding bytes are not part of the structure's member values, and C does not give us a guarantee that their byte contents are preserved by structure assignment.

***Structure assignment copies the values of all members from the source structure to the destination structure. The structure layout including the padding layout (total 12 bytes) is copied. But the values / contents inside the padding bytes are not guaranteed and not preserved. Only the padding layout exsits in t2 as in t1***

- Both objects t1 and t2 have 12 bytes. (padding layout/ padding positions same)
- values of t1 are copied to t2
- padding bytes values of not guranteed to be copied / they differ. 

Now, what do we do incase, if we would like **to copy all bytes of the object representation, including padding bytes** 

### memcpy
**`#include <string.h>` is needed when using the standard library functions: `memcpy()`and `memmove()`.** As this provides the declarations for standard memory/string functions.

Lets consider, 
```c
struct Test
{
    int a;
    char b;
};

struct Test s1;
struct Test s2;

s1.a = 100;
s2.b = `A`;

memcpy(&s2, &s1, sizeof(s1));

```
sizeof(struct Test) = 8 bytes. So the layout is: 

```text
Offset:   0    1    2    3    4    5    6    7
          ┌───────────────┬────┬─────────────────┐
          │       a       │ b  │    padding      │
          │    4 bytes    │1 B │     3 bytes     │
          └───────────────┴────┴─────────────────┘
```
its padding bytes happen to contain AA BB CC. When we do ```c memcpy(&s2, &s1, sizeof(s1));```, what happens to the 3 trailing structure padding bytes? Do they remain undefined or do they contain AA BB CC same as s1? The contents /Values of Structure padding bytes of s2 will have the same values / contents of Structure padding bytes of s1. memcpy() copies all 8 bytes, byte by byte.  

memcpy() copies the object representation byte by byte, including any padding bytes, when the requested size covers them.

```text
Offset:    0    1    2    3    4    5    6    7
           ┌───────────────┬────┬─────────────────┐
s1:        │      a        │ b  │    padding      │
           │     100       │ A  │   AA BB CC      │
           └───────────────┴────┴─────────────────┘
           
After memcpy(&s2, &s1, sizeof(s1)):

Offset:    0    1    2    3    4    5    6    7
           ┌───────────────┬────┬─────────────────┐
s2:        │      a        │ b  │    padding      │
           │     100       │ A  │   AA BB CC      │
           └───────────────┴────┴─────────────────┘
           
s1 padding = AA BB CC
s2 padding = AA BB CC

```

**How do we copy a specified number of bytes from one memory location to another memory location?**

**memmove()** is a standard C library function used to copy a specified number of bytes from one memory location to another.

```c memmove(destination, source, number_of_bytes);```

For example:

```c
char src[] = "Hello";
char dest[6];

memmove(dest, src, 6);
```
Conceptually:
```text
After memmov():
src                         dest

'H'                         'H'
'e'                         'e'
'l'          ──────────►    'l'
'l'                         'l'
'o'                         'o'
'\0'                        '\0'

```
**memmove() works with raw bytes in memory. It doesn't know that the bytes represent a char, int, struct, etc. It only sees addresses and a number of bytes.**

Considering the above example code snippet, C stores the string including the terminating '\0'. So src contains 6 bytes.
```text
src
┌─────┬─────┬─────┬─────┬─────┬─────┐
│ 'H' │ 'e' │ 'l' │ 'l' │ 'o' │ '\0'│
└─────┴─────┴─────┴─────┴─────┴─────┘
   0     1     2     3     4     5
   
after memmove():

src                            
┌────┬────┬────┬────┬────┬────┐
│ H  │ e  │ l  │ l  │ o  │\0  │
└────┴────┴────┴────┴────┴────┘

dest
┌────┬────┬────┬────┬────┬────┐
│ H  │ e  │ l  │ l  │ o  │\0  │
└────┴────┴────┴────┴────┴────┘

```
So what's the **difference between memcpy() and memmove(), if both copy from source to destionation with the mentioned number of bytes?**

Syntax:
```c
memcpy(destination, source, number_of_bytes);
memmove(destination, source, number_of_bytes);
```
The difference is ***what happens when source and destination memory overlap.***

Lets consider the same example:
```c
char src[] = "Hello";
char dest[6];
```
src and dest are completely separate memory areas. Both memcpy() and memmove() can copy this safely. After either one:
```
src:
┌────┬────┬────┬────┬────┬────┐
│ H  │ e  │ l  │ l  │ o  │ \0 │
└────┴────┴────┴────┴────┴────┘

dest:
┌────┬────┬────┬────┬────┬────┐
│ H  │ e  │ l  │ l  │ o  │ \0 │
└────┴────┴────┴────┴────┴────┘
```
***So when memory doesn't overlap, there is practically no difference for us to worry about.*** The difference matters only when the    source and destionation addresses overlaps.

For example, ```c char str[] = "ABCDE";```. The Memory conceptually looks like :

```text
Address
100   101   102   103   104
 A     B     C     D     E
``` 

Now suppose we want to move A B C these 3 bytes to the right by 1 position, then the source and destionation memory address overlap.

```text
Source:      100 101 102 103
              A   B   C   D

Destination: 101 102 103
              ?   ?   ?
```

`memmove(&str[1], &str[0], 3);`

Before:

```text
Address:   100   101   102   103   104
           ┌────┬────┬────┬────┬────┐
           │ A  │ B  │ C  │ D  │ E  │
           └────┴────┴────┴────┴────┘
             ↑
           source

We want to copy 3 bytes starting from 100 to starting at 101. (right shift by 1 position)

So: Source:   100  101  102
               A    B    C


Destination:  101  102  103
```
Here's the important problem: If we simply copied from left to right, 100 -> 101, we would get

```text
Address:   100   101   102   103
           ┌────┬────┬────┬────┐
           │ A  │ A  │ C  │ D  │
           └────┴────┴────┴────┘
           
Then 101 -> 102, But 101 no longer contains B. We already overwrote it with A!

Address:   100   101   102   103
           ┌────┬────┬────┬────┐
           │ A  │ A  │ A  │ D  │
           └────┴────┴────┴────┘
           
then 102 -> 103, copy also uses overwritten data.
Address:   100   101   102   103
           ┌────┬────┬────┬────┐
           │ A  │ A  │ A  │ A  │
           └────┴────┴────┴────┘

```
That's the problem with overlapping memory. ***memmove()*** is specifically designed to handle this situation safely. It effectively chooses a safe direction for the copy. In this case, because the destination is to the right of the source, it copies from right to left:

```text
102-> 103   (C)
101-> 102   (B)
100-> 101   (A)
```
Result (After memmove():

```text
Address:   100   101   102   103   104
           ┌────┬────┬────┬────┬────┐
           │ A  │ A  │ B  │ C  │ E  │
           └────┴────┴────┴────┴────┘
```
So the final string is "AABCE". That's the main idea of memmove(): it handles overlapping source and destination correctly.
When source and destination overlap, memmove() chooses a safe copy direction so that source bytes are not overwritten before they are copied.

Lets consider an other example :
```c
char str[] = "ABCDE";
memmove(&str[0], &str[1], 3); // Copy 3 bytes from &str[1] to &str[0].
```

Before copying:
```text
Address:   100   101   102   103   104
           ┌────┬────┬────┬────┬────┐
           │ A  │ B  │ C  │ D  │ E  │
           └────┴────┴────┴────┴────┘
```
We want to copy 3 bytes from &str[1] to &str[0].

```text
Source:       101   102   103
               B     C     D

Expected Destination:  100   101   102
                        B     C    D
```
The destination is now to the LEFT of the source. To avoid overwriting the original B, C, and D, should we copy from ***left to right***
Let's see why. We have:

```text
Source:       101   102   103
               B     C     D

Destination:  100   101   102
```
**We copy left → right:**
```text
101-> 100    B
102-> 101    C
103-> 102    D
```

```text
steps:
Start:
100   101   102   103
 A     B     C     D

101-> 100:
100   101   102   103
 B     B     C     D

102-> 101:
100   101   102   103
 B     C     C     D

103-> 102:
100   101   102   103
 B     C     D     D
 ```

Finally, we will have `B C D D E`

The important pattern is ,

```text
Overlap?
           ↓
          YES
           ↓
   ┌───────┴────────────────┐
   ↓                        ↓
Destination             Destination
is LEFT                 is RIGHT
of source               of source
   ↓                        ↓
copy Left → Right     copy Right → Left

```
And that is why memmove() is safe for overlapping memory, while memcpy() does not guarantee correct behavior when the regions overlap.

### Structure assignment vs memcpy()/memmove()

Since we learnt Structure assignment, memcpy() and memmove(), lets quickly consider the below example code snippet and understand which is the simplest way to copy  p1 into p2.

Lets consider, 

```c
struct Point
{
    int x;
    int y;
};

struct Point p1;
struct Point p2;

p1.x = 10;
p1.y = 20;
```
The simplest way to do is the structure assignment `p2 = p1`. Then `p2.x = 10 and p2.y = 20`. later, when we do `p2.x = 50`, only `p2.x` will have the new value 50, whereas `p1.x `will still have the old value 10. So p1 and p2 are two separate structure objects. Changing one does not change the other.

memcpy() can be used when source and destination must NOT overlap.  memcpy(destination, source, number_of_bytes) ie, when the source and destination memory regions are separate / non-overlapping.

Example:
```c
char src[] = "Hello";
char dest[6];


memcpy(dest, src, 6);
```

Here:
```text
src:   H e l l o \0
       └─────────┘


dest:  [           ]
       └─────────┘
```

They are separate memory regions. So memcpy() is appropriate.

memmove() can be used when overlap is possible. ie, memmove(destination, source, number_of_bytes); when source and destination may overlap.

For example:
```c
char str[] = "ABCDE";
memmove(&str[1], &str[0], 3);
```

Here:
```text
Source:       A B C
              ↑ ↑ ↑
Destination:    A B C
```

The memory regions overlap. memmove() handles this safely by choosing the appropriate copying direction.