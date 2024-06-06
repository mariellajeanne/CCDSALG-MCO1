#include <stdio.h>
#include <math.h>

int main() {
    printf("%i\n", 3);
    printf("%i\n", 79);
    printf("%i\n", 91);
    printf("%i\n", !2);
    printf("%i\n", !0);
    printf("%i\n", !!!1);
    printf("%i\n", 5 + 6);
    printf("%i\n", 17 - 3);
    printf("%i\n", 38 + 97 - 80);
    printf("%i\n", 14 - 66 + 5);
    printf("%i\n", 29 + (51 - 62));
    printf("%i\n", 57 - (52 + 61));
    printf("%i\n", (82 - 10) + 23);
    printf("%i\n", (76 + 39) - 48);
    printf("%i\n", !!!!5+2);
    printf("%i\n", 2 * 39);
    printf("%i\n", 21 / 3);
    printf("Division by zero error!\n");
    // printf("%i\n", 51 / 0); // Division by zero is undefined
    printf("%i\n", 81 % 4);
    printf("Division by zero error!\n");
    // printf("%i\n", 43 % 0); // Modulus by zero is undefined
    printf("%i\n", 9 * 2 / 5);
    printf("%i\n", 65 / 4 * 7);
    printf("%i\n", 83 * (14 / 6));
    printf("%i\n", 77 / (12 * 3));
    printf("%i\n", (44 * 68) / 65);
    printf("%i\n", (36 / 8) * 83);
    printf("%i\n", 33 * 8 / 6 % 4);
    printf("%i\n", 73 / 17 % 8 * 6);
    printf("%i\n", (56 / 4) % (6 * 86));
    printf("Division by zero error!\n");
    printf("Division by zero error!\n");
    // printf("%i\n", 18 * (77 / 0) % 52); // Division by zero is undefined
    // printf("%i\n", (16 % (0 * 60)) / 13); // Division by zero is undefined
    printf("%i\n", 78 + 9 / 38 * 44 % 92 - 3);
    printf("%i\n", 47 / 5 - 7 * 9 + 43 % 54);
    printf("%i\n", 88 - 30 % 63 / 8 * +58);
    printf("%i\n", 40 % 17 + 26 - 3 / 4 * 6);
    printf("Division by zero error!\n");
    // printf("%i\n", (4 * 95) % (58 / (84 - 6 + 79)));
    printf("%i\n", (int)pow(2, 3));
    printf("%i\n", (int)pow(2, (pow(2, 3))));
    printf("%i\n", (int)pow(3, (int)pow(2, (int)pow(1, 2))));
    printf("%i\n", (int)pow((int)pow(2, 2), 3));
    printf("%i\n", (int)pow(2, pow(pow(3, (!0)), 2)));
    printf("%i\n", 37 / 3 * 24 % (int)pow(57, 2) / 32);
    printf("%i\n", (int)pow(4, 4) / 66 / 13 * 6 / (int)pow(70, 1)); // Invalid C syntax
    printf("%i\n", 50 / ((int)pow(98, 1) % 56) * (int)pow((31 / 37), 0));
    printf("Division by zero error!\n");
    // printf("%i\n", (3 * 16 / 12) % (0 * (int)pow(3, 12 / 6)) * 18); // Division by zero is undefined
    printf("%i\n", 37 * 54 / 2 % 38 + 85 - (int)pow(3, 2));
    printf("%i\n", (int)pow(2, 7) / 5 - 94 * 10 + 96 % 45);
    printf("%i\n", ((15 - 60) * 19) / (int)pow(2, 4) + (77 + (60 * 78)));
    printf("%i\n", (82 / (17 * 82)) + (int)pow(64 - 52, 3));
    printf("%i\n", 9 > 23);
    printf("%i\n", 38 > 31);
    printf("%i\n", 87 < 945);
    printf("%i\n", 14 < 10);
    printf("%i\n", 49 > 75 < 68);
    printf("%i\n", 75 < 32 > 5);
    printf("%i\n", 56>22==!0);
    printf("%i\n", 4 >= 57);
    printf("%i\n", 48 >= 48);
    printf("%i\n", 79 >= 42);
    printf("%i\n", 788 <= 869);
    printf("%i\n", 84 <= 84);
    printf("%i\n", 70 <= 17);
    printf("%i\n", 4 >= 72 <= 87);
    printf("%i\n", 37 <= 3 >= 10);
    printf("%i\n", 55 != 48);
    printf("%i\n", 96 == 96);
    printf("%i\n", 79 == 41);
    printf("%i\n", 0 == 14 >= 29);
    printf("%i\n", 51 <= 43 != 1);
    printf("%i\n", 23 || 44);
    printf("%i\n", 97 || 0);
    printf("%i\n", 19 && 56);
    printf("%i\n", 0 && 67);
    printf("%i\n", 6 && 3 > 2);
    printf("%i\n", 6 == 7 || 19);
    printf("%i\n", !0==1);
    printf("%i\n", !!(1==!0));
    printf("%i\n", 44 <= 65 && 98 > 68);
    printf("%i\n", 59 < 69 || 35 >= 37);
    printf("%i\n", 61 > 44 || 30 < 33 && 4 >= 61);
    printf("%i\n", 45 != 9 && 62 > 59 || 1 >= 66);
    printf("%i\n", (1 == (12 || 94)) != 16 && 66 < 47);
    printf("%i\n", (23 != 19) && ((44 || 94) > 0 != 96));
    printf("%i\n", (69 - 79 * 91) > !(78 + 22 / 13) && !14 < 88);
    printf("%i\n", 43 + 50 == 93 && 16 <= 93 != 35 || 24 < 21);
    printf("%i\n", (!65 < 73) % 34 != (98 - 97) && 82 > 58 <= 50);
    printf("%i\n", ((54 * (96 - 48) + 39 % 97) || 84 > 26) + 39);

    return 0;
}
