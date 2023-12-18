#include <stdio.h>
#include <string.h>

void mergeStrings(const char *str1, const char *str2, char *result) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);

    int i, j, k;
    i = j = k = 0;

    while (i < len1 && j < len2) {
        result[k++] = str1[i++];
        result[k++] = str2[j++];
    }
    while (i < len1) {
        result[k++] = str1[i++];
    }

    while (j < len2) {
        result[k++] = str2[j++];
    }
    result[k] = '\0';
}

int main() {
    const char *str1 = "12345";
    const char *str2 = "abcde";
    char result[2 * (strlen(str1) + strlen(str2)) + 1];

    mergeStrings(str1, str2, result);

    printf("Merged String: %s\n", result);

    return 0;
}
