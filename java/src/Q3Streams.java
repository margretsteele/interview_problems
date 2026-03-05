import java.util.List;
import java.util.Map;
import java.util.stream.Collectors;

record Employee(String name, String department, double salary) {}

public class Q3Streams {
    public static void main(String[] args) {
        List<Employee> employees = List.of(
            new Employee("Alice", "Engineering", 80000),
            new Employee("Bob", "Marketing", 45000),
            new Employee("Charlie", "Engineering", 90000),
            new Employee("Diana", "Marketing", 60000),
            new Employee("Eve", "HR", 55000)
        );

        Map<String, List<String>> result = employees.stream()
            .filter(emp -> emp.salary() > 50000)
            .collect(Collectors.groupingBy(emp -> emp.department(),
                Collectors.mapping(emp -> emp.name(), Collectors.toList()));

        System.out.println(result);
    }
}
