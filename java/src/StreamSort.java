import java.util.*;
import java.util.stream.*;

public class StreamSort {

    public static void main(String[] args) {
        List<String> words = List.of(
            "Banana",
            "apple",
            "Cherry",
            "apple",
            "banana",
            "Date"
        );

        List<String> result = words
            .stream()
            // your code here
            .map(w -> w.toLowerCase())
            .distinct()
            .sorted(
                Comparator.comparingInt(String::length).thenComparing(
                    Comparator.naturalOrder()
                )
            )
            .collect(Collectors.toList());

        // expected: [date, apple, banana, cherry]
        System.out.println(result);
    }
}
