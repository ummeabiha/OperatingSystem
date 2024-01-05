#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#define MAX_PAGES 50
sem_t empty_sem, full_sem;
int page_tray = 0;
void *producer(void *arg)
{
    while (1)
    {
        sem_wait(&empty_sem);
        page_tray++;
        printf("Produced a page. Total pages in tray: %d\n", page_tray);
        sem_post(&full_sem);
        usleep(500000);
    }
    pthread_exit(NULL);
}
void *consumer(void *arg)
{
    while (1)
    {
        sem_wait(&full_sem);
        page_tray--;
        printf("Printed a page. Total pages in tray: %d\n", page_tray);
        sem_post(&empty_sem);
        usleep(700000);
    }
    pthread_exit(NULL);
}
int main()
{
    pthread_t producer_thread, consumer_thread;
    sem_init(&empty_sem, 0, MAX_PAGES);
    sem_init(&full_sem, 0, 0);
    pthread_create(&producer_thread, NULL, producer, NULL);
    pthread_create(&consumer_thread, NULL, consumer, NULL);
    pthread_join(producer_thread, NULL);
    pthread_join(consumer_thread, NULL);
    sem_destroy(&empty_sem);
    sem_destroy(&full_sem);
    return 0;
}