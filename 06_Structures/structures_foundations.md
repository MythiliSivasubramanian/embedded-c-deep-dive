# Structures in C (Embedded View)

## What is a structure?
A structure is:
- A way to group different types of variables under one name.
- Think of it as a custom data type.

Example:
```c
struct Student {
   int id;
   float marks;
   char grade;
};
```

Now we have created a new type:
`Student = {int, float, char}` but memory will not be allocated here.

### Using it:
```c
struct Student s1;
```

Only now memory is allocated for all members together.

## Memory View
Assume:
```c
struct Student {
   int id;      // 4 bytes
   float marks; // 4 bytes
   char grade;  // 1 byte
};
```

Memory (conceptual):

| Member | Size |
|--------|------|
| id | 4B |
| marks | 4B |
| grade | 1B |
| padding | 3B |

`Total = 12 bytes (due to alignment/padding)`

## Accessing members of a structure
We use the dot operator:
```c
s1.id = 101;
s1.marks = 89.5;
s1.grade = 'A';
```

## Why structures are important in Embedded
This is where structures become powerful.

### 1. Representing real hardware
Example: Sensor data
```c
struct SensorData {
   int temperature;
   int pressure;
   int humidity;
};
```

Instead of 3 separate variables:
- `temperature`
- `pressure`
- `humidity`

you group them into one: `SensorData`.

### 2. Memory-mapped registers
This is STM32 level usage:
```c
struct GPIO {
   volatile int MODER;
   volatile int ODR;
   volatile int IDR;
};
```

Now hardware registers behave like:
```c
GPIOA->ODR = 1;
```

Instead of messy memory addresses.

### 3. Clean firmware design
Without structures:
```c
int temp;
int pressure;
int humidity;
```

With structures:
```c
struct SensorData data;
```

Cleaner, scalable, maintainable.

> Note: Structures are NOT just variables. They are: Memory layouts defined by the programmer.

