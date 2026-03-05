public class MergeSortedArrays {

    public static int[] mergeSorted(int[] a, int[] b) {
        /*
        std::vector<int> mergeSortedShit(const std::vector<int>& a, const std::vector<int>& b) {
            std::vector<int> result;
            result.reserve(a.size() + b.size());
            auto ait = a.begin();
            auto bit = b.begin();

            while (ait != a.end() && bit != b.end()) {
                if (*ait <= *bit) {
                    result.push_back(*ait++);
                } else {
                    result.push_back(*bit++);
                }
            }
            while (ait != a.end()) result.push_back(*ait++);
            while (bit != b.end()) result.push_back(*bit++);

            return result;
        }

        */
        if (a.length == 0) {
            return b;
        }
        if (b.length == 0) {
            return a;
        }

        int[] result = new int[a.length + b.length];
        int k = 0;
        int i = 0;
        int j = 0;

        while (i < a.length && j < b.length) {
            if (a[i] <= b[j]) {
                result[k++] = a[i];
                i = i + 1;
            } else {
                result[k++] = b[j];
                j = j + 1;
            }
        }

        while (i < a.length) {
            result[k++] = a[i++];
        }
        while (j < b.length) {
            result[k++] = b[j++];
        }
        return result;
    }

    public static void main(String[] args) {
        int[] a = { 1, 3, 5, 7 };
        int[] b = { 2, 4, 6, 8 };
        int[] result = mergeSorted(a, b);

        // expected: [1, 2, 3, 4, 5, 6, 7, 8]
        System.out.print("[");
        for (int i = 0; i < result.length; i++) {
            System.out.print(result[i]);
            if (i < result.length - 1) System.out.print(", ");
        }
        System.out.println("]");
    }
}
