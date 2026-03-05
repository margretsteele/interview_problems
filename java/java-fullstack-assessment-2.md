# Java Full-Stack Assessment — Practice Test 2
## 10 Questions | "Prove you can code" format

---

### Q1. What's the output? (Inheritance)
```java
class Base {
    int x = 10;

    int getX() {
        return x;
    }
}

class Child extends Base {
    int x = 20;

    int getX() {
        return x;
    }
}

public class Main {
    public static void main(String[] args) {
        Base obj = new Child();
        System.out.println(obj.x);
        System.out.println(obj.getX());
    }
}
```

a) `10` then `10`
b) `20` then `20`
c) `10` then `20`
d) `20` then `10`

---

### Q2. Fix the bug (Strings)
This method should reverse a string. It compiles but returns the wrong result. Why?

```java
public String reverse(String s) {
    String result = "";
    for (int i = 0; i <= s.length(); i++) {
        result = s.charAt(i) + result;
    }
    return result;
}
```

---

### Q3. Write a method (Arrays)
Write a method that takes an array of integers and returns the second largest value. If the array has fewer than 2 unique values, return -1.

```java
public int secondLargest(int[] nums) {
    // your code here
}

// secondLargest({3, 1, 4, 1, 5, 9}) -> 5
// secondLargest({7, 7, 7}) -> -1
// secondLargest({1}) -> -1
```

---

### Q4. What's the output? (Generics & Autoboxing)
```java
public class Main {
    public static void main(String[] args) {
        Integer a = 127;
        Integer b = 127;
        Integer c = 128;
        Integer d = 128;

        System.out.println(a == b);
        System.out.println(c == d);
        System.out.println(c.equals(d));
    }
}
```

a) `true`, `true`, `true`
b) `true`, `false`, `true`
c) `false`, `false`, `true`
d) `true`, `false`, `false`

---

### Q5. Complete the stream (Streams)
Fill in the blank to get a list of unique words (lowercase, no duplicates) sorted by length, then alphabetically.

```java
List<String> words = List.of("Banana", "apple", "Cherry", "apple", "banana", "Date");

List<String> result = words.stream()
    ____________________________;

// result should be: ["date", "apple", "banana", "cherry"]
```

---

### Q6. SQL — Write a query
Given these tables:

```sql
CREATE TABLE orders (
    id INT PRIMARY KEY,
    customer_id INT,
    total DECIMAL(10,2),
    order_date DATE
);

CREATE TABLE customers (
    id INT PRIMARY KEY,
    name VARCHAR(100),
    email VARCHAR(100)
);
```

Write a query that returns the **name and email** of customers who have placed **more than 5 orders** with a **total greater than $100 each**.

---

### Q7. Find the bug (Logic)
This method should return true if the string is a palindrome (reads the same forwards and backwards). It doesn't work for all cases. What's wrong?

```java
public boolean isPalindrome(String s) {
    s = s.toLowerCase();
    int left = 0;
    int right = s.length();
    while (left < right) {
        if (s.charAt(left) != s.charAt(right)) {
            return false;
        }
        left++;
        right--;
    }
    return true;
}
```

---

### Q8. Write a method (HashMap)
Write a method that takes two strings and returns true if they are anagrams of each other (contain the same characters in any order). Ignore case and spaces.

```java
public boolean isAnagram(String a, String b) {
    // your code here
}

// isAnagram("listen", "silent") -> true
// isAnagram("Hello", "Olelh") -> true
// isAnagram("abc", "abd") -> false
```

---

### Q9. What's the output? (Collections)
```java
import java.util.*;

public class Main {
    public static void main(String[] args) {
        List<String> list = new ArrayList<>(Arrays.asList("a", "b", "c", "d"));
        Iterator<String> it = list.iterator();
        while (it.hasNext()) {
            String s = it.next();
            if (s.equals("b")) {
                list.remove(s);
            }
        }
        System.out.println(list);
    }
}
```

a) `[a, c, d]`
b) `[a, b, c, d]`
c) Compilation error
d) `ConcurrentModificationException`

---

### Q10. REST API Design (Concepts)
You're building an API for a task management app. For each action, give the HTTP method and URL path:

1. Get all tasks for a user
2. Create a new task
3. Mark a specific task as complete
4. Delete a task
5. Get all tasks that are overdue

What status code would you return for each?

---

## Scoring

| # | Topic | Your Score |
|---|-------|------------|
| 1 | Inheritance — output | /10 |
| 2 | Strings — debug | /10 |
| 3 | Arrays — write code | /10 |
| 4 | Autoboxing — output | /10 |
| 5 | Streams — fill in blank | /10 |
| 6 | SQL — write query | /10 |
| 7 | Logic — debug | /10 |
| 8 | HashMap — write code | /10 |
| 9 | Collections — output | /10 |
| 10 | REST API — design | /10 |
| **Total** | | **/100** |
