# Java Full-Stack Assessment — Practice Test
## 10 Questions | "Prove you can code" format

---

### Q1. What's the output? (OOP)
```java
class Vehicle {
    public String describe() {
        return "I am a vehicle";
    }
}

class Truck extends Vehicle {
    @Override
    public String describe() {
        return "I am a truck";
    }
}

public class Main {
    public static void main(String[] args) {
        Vehicle v = new Truck();
        System.out.println(v.describe());
    }
}
```

a) `I am a vehicle`
b) `I am a truck`
c) Compilation error
d) Runtime error

---

### Q2. Fix the bug (Collections)
This code should count word frequencies, but it crashes. Why? Fix it.

```java
Map<String, Integer> counts = new HashMap<>();
String[] words = {"apple", "banana", "apple", "cherry", "banana", "apple"};

for (String word : words) {
    counts.put(word, counts.get(word) + 1);
}

System.out.println(counts);
```

---

### Q3. Write a method (Strings)
Write a method that takes a `List<String>` and returns a new list containing only strings that are longer than 5 characters, all converted to uppercase.

```java
public List<String> filterAndTransform(List<String> input) {
    List<String> result = input.stream()
        .filter(i -> i.length() > 5)
        .map(i -> i.toUpperCase())
        .collect(Collectors.toList());
        
    return result;
}   
```

---

### Q4. What's the output? (Interfaces)
```java
interface Printable {
    default void print() {
        System.out.println("Printable");
    }
}

interface Loggable {
    default void print() {
        System.out.println("Loggable");
    }
}

class Document implements Printable, Loggable {
    @Override
    public void print() {
        Printable.super.print();
    }
}

public class Main {
    public static void main(String[] args) {
        new Document().print();
    }
}
```

a) `Printable`
b) `Loggable`
c) Compilation error — ambiguous default method
d) Prints both

---

### Q5. Complete the stream (Streams)
Fill in the blank to get a comma-separated string of names sorted alphabetically.

```java
List<String> names = List.of("Charlie", "Alice", "Bob", "Diana");

String result = names.stream()
    .sorted()
    .collect(Collectors.joining(","));
     

// result should be: "Alice,Bob,Charlie,Diana"
```

---

### Q6. SQL — Write a query
Given this table:

```sql
CREATE TABLE products (
    id INT PRIMARY KEY,
    name VARCHAR(100),
    category VARCHAR(50),
    price DECIMAL(10,2),
    in_stock BOOLEAN
);
```

Write a query that returns the **average price per category**, but only for categories that have **more than 3 products in stock**.

---

### Q7. Find the bug (Logic)
This method should return `true` if the array contains any duplicates. It doesn't work correctly. What's wrong?

```java
public boolean hasDuplicates(int[] nums) {
    Set<Integer> seen = new HashSet<>();
    for (int n : nums) {
        seen.add(n);
        if (seen.contains(n)) {
            return true;
        }
    }
    return false;
}
```

---

### Q8. Implement a method (Data Structures)
Write a method that takes two sorted arrays of integers and merges them into a single sorted array.

```java
public int[] mergeSorted(int[] a, int[] b) {
    // your code here
}
```

---

### Q9. What's the output? (Exception Handling)
```java
public class Main {
    public static int getValue() {
        try {
            return 1;
        } finally {
            return 2;
        }
    }

    public static void main(String[] args) {
        System.out.println(getValue());
    }
}
```

a) `1`
b) `2`
c) Compilation error
d) Runtime exception

---

### Q10. REST basics (HTTP)
Match each HTTP method to its purpose:

| Method | Purpose |
|--------|---------|
| GET    | ???     |
| POST   | ???     |
| PUT    | ???     |
| DELETE | ???     |

And: what's the difference between a `200`, `201`, `400`, `404`, and `500` status code?

---

## Scoring

| # | Topic | Your Score |
|---|-------|------------|
| 1 | OOP — output | /10 |
| 2 | Collections — debug | /10 |
| 3 | Strings — write code | /10 |
| 4 | Interfaces — output | /10 |
| 5 | Streams — fill in blank | /10 |
| 6 | SQL — write query | /10 |
| 7 | Logic — debug | /10 |
| 8 | Data structures — write code | /10 |
| 9 | Exceptions — output | /10 |
| 10 | REST/HTTP — concepts | /10 |
| **Total** | | **/100** |
