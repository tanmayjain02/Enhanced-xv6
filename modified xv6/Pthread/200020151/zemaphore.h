#include <pthread.h>

typedef struct zemaphore {

    int num;
    pthread_cond_t cond_var;
    pthread_mutex_t lock;
    
} zem_t;

void zem_init(zem_t *, int);
void zem_up(zem_t *);
void zem_down(zem_t *);
