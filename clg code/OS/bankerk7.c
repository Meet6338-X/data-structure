#include <stdio.h>

int main()
{
    int processes, resources;

    printf("Enter number of processes: ");
    scanf("%d", &processes);

    printf("Enter number of resources: ");
    scanf("%d", &resources);

    int allocation[processes][resources];
    int max[processes][resources];
    int available[resources];
    int need[processes][resources];

    printf("\nEnter Allocation Matrix:\n");
    for (int i = 0; i < processes; i++)
    {
        for (int j = 0; j < resources; j++)
        {
            scanf("%d", &allocation[i][j]);
        }
    }

    printf("\nEnter Max Matrix:\n");
    for (int i = 0; i < processes; i++)
    {
        for (int j = 0; j < resources; j++)
        {
            scanf("%d", &max[i][j]);
        }
    }

    printf("\nEnter Available Resources:\n");
    for (int i = 0; i < resources; i++)
    {
        scanf("%d", &available[i]);
    }

    for (int i = 0; i < processes; i++)
    {
        for (int j = 0; j < resources; j++)
        {
            need[i][j] = max[i][j] - allocation[i][j];
        }
    }

    int finish[processes];
    int safeSeq[processes];
    int work[resources];

    for (int i = 0; i < resources; i++)
        work[i] = available[i];

    for (int i = 0; i < processes; i++)
        finish[i] = 0;

    int count = 0;

    while (count < processes)
    {
        int found = 0;

        for (int p = 0; p < processes; p++)
        {
            if (!finish[p])
            {
                int canExecute = 1;

                for (int r = 0; r < resources; r++)
                {
                    if (need[p][r] > work[r])
                    {
                        canExecute = 0;
                        break;
                    }
                }

                if (canExecute)
                {
                    for (int r = 0; r < resources; r++)
                        work[r] += allocation[p][r];

                    safeSeq[count++] = p;
                    finish[p] = 1;
                    found = 1;
                }
            }
        }

        if (!found)
        {
            printf("\n❌ System is in UNSAFE state (Deadlock Possible)\n");
            return 0;
        }
    }

    printf("\n✅ System is in SAFE state.\n");
    printf("Safe Sequence: ");
    for (int i = 0; i < processes; i++)
        printf("P%d ", safeSeq[i]);

    printf("\n");

    return 0;
}
