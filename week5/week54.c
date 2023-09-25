#include <stdio.h>
#include <stdint.h>

// Function to check if a number is a quadratic residue modulo p
int isQuadraticResidue(int x,int p) {
    for (int i = 0; i < p; i++) {
        if ((i * i) % p == x)
            return 1;
    }
    return 0;
}

// Function to find all points on the elliptic curve
void findPointsOnCurve(int p, int a,int b) {
   for (int x = 0; x < p; x++) {
        int y_squared = (x * x * x + a * x + b) % p;
        if (isQuadraticResidue(y_squared,p)) {
            int y = 0;
            while ((y * y) % p != y_squared) {
                y++;
            }
             printf("(%d, %d)\n", x, y);
             printf("(%d, %d)\n",x , p-y);
        }
    }
}

int main() {
    int a,b,p;
    printf("Enter the value of p:" );
    scanf("%d", &p);
    printf("Enter the value of a:" );
     scanf("%d", &a);
    printf("Enter the value of b:" );
     scanf("%d", &b);
    printf("Points on the elliptic curve y^2 = x^3 + %dx + %d (mod %d):\n", a, b, p);
    findPointsOnCurve(p,a,b);
    return 0;
}
