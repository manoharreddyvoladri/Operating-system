//Implementation of the process Synchronization  by using the Moniters with c code

#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
typedef struct {
    pthread_mutex_t mutex;
    pthread_cond_t cond;
    int data;
} monitor_t;

void monitor_init(monitor_t* mon) {
    pthread_mutex_init(&mon->mutex, NULL);
    pthread_cond_init(&mon->cond, NULL);
    mon->data = 0;
}

void monitor_enter(monitor_t* mon) {
    pthread_mutex_lock(&mon->mutex);
}

void monitor_exit(monitor_t* mon) {
    pthread_mutex_unlock(&mon->mutex);
}

void monitor_wait(monitor_t* mon) {
    pthread_cond_wait(&mon->cond, &mon->mutex);
}

void monitor_signal(monitor_t* mon) {
    pthread_cond_signal(&mon->cond);
}

void* thread_func(void* arg) {
    monitor_t* mon = (monitor_t*) arg;

    monitor_enter(mon);

    while (mon->data < 10) {
        monitor_wait(mon);
        printf("Thread %lu received signal, data = %d\n", pthread_self(), mon->data);
    }

    monitor_exit(mon);
    return NULL;
}

int main() {
    
    printf("21BRS1177 -- Voaldri Manohar Reddy\n");
    pthread_t threads[3];
    monitor_t mon;
    monitor_init(&mon);

    for (int i = 0; i < 3; i++) {
        pthread_create(&threads[i], NULL, thread_func, &mon);
    }

    for (int i = 0; i < 10; i++) {
        monitor_enter(&mon);
        mon.data = i;
        monitor_signal(&mon);
        monitor_exit(&mon);
    }

    for (int i = 0; i < 3; i++) {
        pthread_join(threads[i], NULL);
    }

    pthread_mutex_destroy(&mon.mutex);
    pthread_cond_destroy(&mon.cond);

    return 0;
}
