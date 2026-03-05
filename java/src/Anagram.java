import java.util.Arrays;

public class Anagram {

    public boolean isAnagram(String a, String b) {
        // your code here
        if (a.length() != b.length()) return false;

        char[] newA = a.toLowerCase().toCharArray();
        char[] newB = b.toLowerCase().toCharArray();
        Arrays.sort(newA);
        Arrays.sort(newB);
        System.out.println(newA);
        System.out.println(newB);

        return Arrays.equals(newA, newB);
    }

    public static void main(String[] args) {
        Anagram sol = new Anagram();
        System.out.println(sol.isAnagram("listen", "silent")); // true
        System.out.println(sol.isAnagram("Hello", "Olelh")); // true
        System.out.println(sol.isAnagram("abc", "abd")); // false
    }
}
