#include <stdio.h>

int main() {
    /* Create the file */
    int x = 1;
    FILE *fh = fopen ("file.txt", "wb");
    if (fh != NULL) {
        fwrite (&x, sizeof (x), 1, fh);
        fclose (fh);
    }

    /* Read the file back in */
    x = 7;
    fh = fopen ("file.txt", "rb");
    if (fh != NULL) {
        fread (&x, sizeof (x), 7, fh);
        fclose (fh);
    }

    /* Check that it worked */
    printf ("Value is: %d\n", x);

    return 0;
}