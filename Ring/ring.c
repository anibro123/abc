#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 10
int list[MAX], n, c;
void display() {
    int i;
    printf("\nProcesses-->");
    for (i = 1; i <= n; i++)
        printf("\t %d", i);
    printf("\nAlive-->");
    for (i = 1; i <= n; i++)
        printf("\t %d", list[i]);
    printf("\ncoordinator is::%d", c);
    }
void ring() {
    int msg[20], ring_n, k, i;
    int ch, crash, gid, flag, subcdr;
    do {
        printf("\n1.Crash\n2.Display\n3.Exit\nEnter Your choice::");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                printf("\nEnter Process no. to Crash::");
                scanf("%d", &crash);
                if (list[crash])
                    list[crash] = 0;
                else {
                    printf("\nProcess is already dead!!");
                    break;
                }
                do {
                    printf("\nEnter election generator id::");
                    scanf("%d", &gid);
                    if (gid == c) {
                        printf("\nEnter a valid generator id::");
                    }
                } while (gid == crash);
                flag = 0;
                k = 1;
                if (crash == c) 
                {
                    msg[k++] = gid;
                    for (i = (gid + 1) % n; i != gid; i = (i + 1) % n) 
                    {
                        if (list[i]) 
                        {
                            printf("\nmessage is sent to %d k %d", i, k);
                            msg[k++] = i;
                        }
                    }
                    subcdr = 0;
                    for (i = 1; i < k; i++) 
                    {
                        printf("\nmsg::%d\n", msg[i]);
                        if (subcdr <=msg[i]) {
                            subcdr = msg[i];
                        }
                    }
                    c = subcdr;
                }
                display();
                break;
            case 2:
                display();
                break;

            case 3:
                break;
        }
    } while (ch != 3);
}
int main() {
    int i, j;
    printf("\nEnter no. of processes::");
    scanf("%d", &n);
    for (i = 1; i <= n; i++) {
        printf("\nEnter Process %d is Alive or not (0/1)::", i);
        scanf("%d", &list[i]);
        if (list[i])
            c = i;
    }
    display();
    printf("\nRING ALGORITHM\n");
    ring();
    return 0;
}
