public class SecondLargest {

    public static int secondLargest(int[] nums) {
        int max = 0;
        int secondMax = 0;

        if (nums.length < 2) return -1;

        for (int i = 0; i < nums.length; i++) {
            int current = nums[i];
            if (current >= max) {
                secondMax = max;
                max = current;
            } else if (current > secondMax) {
                secondMax = current;
            }
        }

        if (max == secondMax) return -1;
        return secondMax;
    }

    public static void main(String[] args) {
        System.out.println(secondLargest(new int[] { 3, 1, 4, 1, 5, 9 })); // expected: 5
        System.out.println(secondLargest(new int[] { 7, 7, 7 })); // expected: -1
        System.out.println(secondLargest(new int[] { 1 })); // expected: -1
    }
}
