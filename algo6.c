#include <stdio.h>

int main() {
int T;
scanf("%d", &T);                                                                                                                                                                                                                        for(int i=1; i<=T; i++) {
    int B, C, D;
    scanf("%d %d %d", &B, &C, &D);

    int E[7];
    int total_customers = 0;
    for(int j=0; j<7; j++) {
        scanf("%d", &E[j]);
        total_customers += E[j];
    }

    int benches = 0;
    int stools = 0;
    int rented_benches = 0;
    int rented_stools = 0;

    for(int j=0; j<7; j++) {
        int customers = E[j];
        if(customers == 0) continue;

        int seats_needed = customers;
        if(seats_needed % 2 == 1) {
            // If odd number of customers, we need an extra stool
            stools++;
            seats_needed--;
        }

        int benches_needed = seats_needed / 2;
        benches += benches_needed;

        // If we don't have enough rented benches or stools, rent more
        int benches_to_rent = benches_needed - rented_benches;
        if(benches_to_rent > 0) {
            int cost = benches_to_rent * D * B;
            rented_benches += benches_to_rent;
            printf("Rented %d benches for %d\n", benches_to_rent, cost);
        }

        int stools_to_rent = stools - rented_stools;
        if(stools_to_rent > 0) {
            int cost = stools_to_rent * C * B;
            rented_stools += stools_to_rent;
            printf("Rented %d stools for %d\n", stools_to_rent, cost);
        }
    }

    printf("Case #%d: %d %d\n", i, benches, rented_benches * D * B + rented_stools * C * B);
}

return 0;
}