import java.util.Arrays;

public class Solution {
    public String lexPalindromicPermutation(String s, String target) {
        int n = s.length();
        int[] counts = new int[26]; 
        for (char c : s.toCharArray()) {
            counts[c - 'a']++;
        }

        int oddCount = 0;
        int oddCharIdx = -1;
        for (int i = 0; i < 26; i++) {
            if (counts[i] % 2 != 0) {
                oddCount++;
                oddCharIdx = i;
            }
        }
        if (oddCount > 1) {
            return "";
        }
        int halfLen = n / 2;
        int[] halfCounts = new int[26];
        for (int i = 0; i < 26; i++) {
            halfCounts[i] = counts[i] / 2;
        }

        StringBuilder smallestHalf = new StringBuilder();
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < halfCounts[i]; j++) {
                smallestHalf.append((char) ('a' + i));
            }
        }
        String smallestPal = buildPalindrome(smallestHalf.toString(), oddCharIdx);
        if (smallestPal.compareTo(target) > 0) {
            return smallestPal;
        }

        String targetHalf = target.substring(0, halfLen);

        int[] exactCounts = halfCounts.clone();
        boolean canFormExactHalf = true;
        for (int i = 0; i < halfLen; i++) {
            int idx = targetHalf.charAt(i) - 'a';
            if (exactCounts[idx] > 0) {
                exactCounts[idx]--;
            } else {
                canFormExactHalf = false;
                break;
            }
        }
        if (canFormExactHalf) {
            String exactPal = buildPalindrome(targetHalf, oddCharIdx);
            if (exactPal.compareTo(target) > 0) {
                return exactPal;
            }
        }

        for (int i = halfLen - 1; i >= 0; i--) {
            int[] remCounts = halfCounts.clone();
            
            boolean possiblePrefix = true;
            for (int j = 0; j < i; j++) {
                int idx = targetHalf.charAt(j) - 'a';
                if (remCounts[idx] > 0) {
                    remCounts[idx]--;
                } else {
                    possiblePrefix = false;
                    break;
                }
            }
            if (!possiblePrefix) continue;

            int startChar = targetHalf.charAt(i) - 'a' + 1;
            for (int c = startChar; c < 26; c++) {
                if (remCounts[c] > 0) {
                    StringBuilder newHalf = new StringBuilder(targetHalf.substring(0, i));
                    newHalf.append((char) ('a' + c));
                    remCounts[c]--;

                    
                    for (int k = 0; k < 26; k++) {
                        while (remCounts[k] > 0) {
                            newHalf.append((char) ('a' + k));
                            remCounts[k]--;
                        }
                    }

                    String candidate = buildPalindrome(newHalf.toString(), oddCharIdx);
                    if (candidate.compareTo(target) > 0) {
                        return candidate;
                    }
                }
            }
        }

        return "";
    }

    private String buildPalindrome(String half, int oddCharIdx) {
        String mid = (oddCharIdx != -1) ? String.valueOf((char) ('a' + oddCharIdx)) : "";
        String rev = new StringBuilder(half).reverse().toString();
        return half + mid + rev;
    }
}

