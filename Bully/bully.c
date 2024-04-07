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

void bully() {
    int ch, crash,i, gid, flag, subcdr;
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
                if (crash == c) 
                {
                    for (i = gid + 1; i <= n; i++) {
                        printf("\nmessage is sent from %d to %d", gid, i);
                        if (list[i]) 
                        {
                            subcdr = i;
                            printf("Response is sent from %d to %d", i, gid);
                            flag = 1;
                        }
                    }
                    if (flag == 1) {
                        c = subcdr;
                    } else {
                        c = gid;
                    }
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
    printf("\nEnter no. of process::");
    scanf("%d", &n);
    for (i = 1; i <= n; i++) {
        printf("\nEnter Process %d is Alive or not(0/1)::", i);
        scanf("%d", &list[i]);
        if (list[i])
            c = i;
    }
    display();
    printf("\nBULLY ALGORITHM\n");
    bully();
    return 0;
}
