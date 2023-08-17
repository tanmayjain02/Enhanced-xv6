#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <string.h>
#include <errno.h>
#include <signal.h>
#include <wait.h>
#include "zemaphore.h"

void zem_init(zem_t *s, int value) {

    
    if (pthread_cond_init(&s->cond_var, NULL) != 0) {                                    
        perror("error in initialization ");                                        
        exit(1);                                                                    
    }   
    if (pthread_mutex_init(&s->lock, NULL) != 0) {
        perror("error in initialization");
        exit(1);
    }
    s->num = value;
}

void zem_down(zem_t *s) {
    pthread_mutex_lock(&s->lock);
    s->num--;
    if(s->num< 0)
        pthread_cond_wait(&s->cond_var, &s->lock);
    pthread_mutex_unlock(&s->lock);
}

void zem_up(zem_t *s) {
    pthread_mutex_lock(&s->lock);
    s->num++;
    pthread_cond_signal(&s->cond_var);
    pthread_mutex_unlock(&s->lock);
}
