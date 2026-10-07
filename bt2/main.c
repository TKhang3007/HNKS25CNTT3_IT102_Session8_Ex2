#include <stdio.h>

#define MAX_USERS 100

struct UserAccount {
    int user_id;
    char username[50];
    int plan_type;
    int days_overdue;
    int active_devices;
    int actual_fee;
};

int main() {
    struct UserAccount user_list[MAX_USERS];

    int n;
    int i;
    int total_revenue = 0;
    int downgraded_count = 0;

    do {
        printf("Nhap so luong tai khoan (1-%d): ", MAX_USERS);
        scanf("%d", &n);

        if (n < 1 || n > MAX_USERS) {
            printf("Loi: So luong tai khoan phai tu 1 den %d!\n", MAX_USERS);
        }
    } while (n < 1 || n > MAX_USERS);

    for (i = 0; i < n; i++) {
        printf("\n===== NHAP TAI KHOAN %d =====\n", i + 1);

        printf("Nhap ma tai khoan: ");
        scanf("%d", &user_list[i].user_id);

        printf("Nhap ten tai khoan: ");
        scanf("%49s", user_list[i].username);

        do {
            printf("Nhap ma goi (1-Free, 2-Personal, 3-Family): ");
            scanf("%d", &user_list[i].plan_type);

            if (user_list[i].plan_type < 1 ||
                user_list[i].plan_type > 3) {
                printf("Loi: Ma goi phai tu 1 den 3!\n");
            }
        } while (user_list[i].plan_type < 1 ||
                 user_list[i].plan_type > 3);

        do {
            printf("Nhap so ngay no cuoc: ");
            scanf("%d", &user_list[i].days_overdue);

            if (user_list[i].days_overdue < 0) {
                printf("Loi: So ngay no cuoc khong duoc am!\n");
            }
        } while (user_list[i].days_overdue < 0);

        do {
            printf("Nhap so thiet bi dang ket noi: ");
            scanf("%d", &user_list[i].active_devices);

            if (user_list[i].active_devices < 0) {
                printf("Loi: So thiet bi khong duoc am!\n");
            }
        } while (user_list[i].active_devices < 0);
    }

    for (i = 0; i < n; i++) {
        if (user_list[i].plan_type == 1) {
            user_list[i].actual_fee = 0;
        } else if (user_list[i].plan_type == 2) {
            user_list[i].actual_fee = 120000;
        } else {
            user_list[i].actual_fee = 250000;
        }

        if (user_list[i].days_overdue >= 3) {
            user_list[i].plan_type = 1;
            user_list[i].actual_fee = 0;
            downgraded_count++;
        }

        if (user_list[i].plan_type == 2 &&
            user_list[i].active_devices > 1) {
            int extra_devices;
            extra_devices = user_list[i].active_devices - 1;

            user_list[i].actual_fee = user_list[i].actual_fee + extra_devices * 30000;
        }

        total_revenue = total_revenue + user_list[i].actual_fee;
    }

    printf("\n\n===============================================================\n");
    printf("       BAO CAO DOI SOAT VA XU LY NO CUOC STREAMFLOW\n");
    printf("===============================================================\n");

    printf("%-10s %-15s %-8s %-12s %-12s %-18s\n",
           "Ma TK",
           "Ten TK",
           "Ma Goi",
           "Thiet Bi",
           "No Cuoc",
           "Phi Thuc Thu");

    printf("---------------------------------------------------------------\n");

    for (i = 0; i < n; i++) {
        printf("%-10d %-15s %-8d %-12d %-12d %-18d\n",
               user_list[i].user_id,
               user_list[i].username,
               user_list[i].plan_type,
               user_list[i].active_devices,
               user_list[i].days_overdue,
               user_list[i].actual_fee);
    }

    printf("---------------------------------------------------------------\n");

    printf("Tong doanh thu thuc te: %d VND\n", total_revenue);
    printf("Tong so tai khoan bi ha cap: %d\n", downgraded_count);

    return 0;
}