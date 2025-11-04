#include <stdio.h>
typedef struct
{
    int value;
} semaphore;

void wait(semaphore *s)
{
    s->value--;
    printf("wait - value = %d\n", s->value);

    if (s->value < 0)
    {
        printf("Process Blocked (Sleeping)\n");
    }
}

void signal(semaphore *s)
{
    s->value++;
    printf("signal - value = %d\n", s->value);

    if (s->value <= 0)
    {
        printf("Process Woken Up\n");
    }
}

void wait_binary(semaphore *s)
{
    printf("binary - wait : ");
    if (s->value == 1)
    {
        s->value = 0;
        printf("Lock acquired\n");
    }
    else
    {
        printf("locked already \n");
    }
}

void signal_binary(semaphore *s)
{
    s->value = 1;
    printf("signal binary - Lock released\n");
}

int main()
{
    semaphore countS, binS;

    countS.value = 1;
    binS.value = 1;

    printf("Counting Semaphore\n");
    wait(&countS);
    wait(&countS);
    signal(&countS);
    signal(&countS);

    printf("\nSemaphore Demo\n");
    wait_binary(&binS);
    wait_binary(&binS);
    signal_binary(&binS);

    return 0;
}

// chatgpt
// code
//  #include <stdio.h>
//  #include <pthread.h>
//  #include <semaphore.h>
//  #include <unistd.h>

// // Semaphore variables
// sem_t binarySem;
// sem_t countSem;

// // wait() for Binary Semaphore
// void waitBinary()
// {
//     sem_wait(&binarySem); // Wait / P operation
//     printf("Binary semaphore acquired\n");
// }

// // signal() for Binary Semaphore
// void signalBinary()
// {
//     sem_post(&binarySem); // Signal / V operation
//     printf("Binary semaphore released\n");
// }

// // wait() for Counting Semaphore
// void waitCounting()
// {
//     sem_wait(&countSem);
//     printf("Counting semaphore decremented\n");
// }

// // signal() for Counting Semaphore
// void signalCounting()
// {
//     sem_post(&countSem);
//     printf("Counting semaphore incremented\n");
// }

// // Thread function for testing
// void *test(void *arg)
// {
//     waitBinary();
//     waitCounting();

//     printf("Critical Section...\n");
//     sleep(1); // simulate work

//     signalCounting();
//     signalBinary();
//     return NULL;
// }

// int main()
// {
//     pthread_t t1, t2;

//     // Initialize Binary semaphore (1 = unlocked)
//     sem_init(&binarySem, 0, 1);

//     // Initialize Counting semaphore (3 = max resources)
//     sem_init(&countSem, 0, 3);

//     pthread_create(&t1, NULL, test, NULL);
//     sleep(1);
//     pthread_create(&t2, NULL, test, NULL);

//     pthread_join(t1, NULL);
//     pthread_join(t2, NULL);

//     sem_destroy(&binarySem);
//     sem_destroy(&countSem);

//     return 0;
// }
