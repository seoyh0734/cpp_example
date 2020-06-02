#include <iostream>
#include <pthread.h>

pthread_mutex_t mutex;

void* callCount(void* arg)
{
    int cnt = 0;
    static int sum = 1;

    while (cnt++ < 100000)
    {
        pthread_mutex_lock(&mutex);
        std::cout << pthread_self() << " : " << sum++ << std::endl;
        pthread_mutex_unlock(&mutex);
    }
}

int main(int argc, char* argv[])
{
    int ret = -1;

    pthread_t thd1;
    pthread_t thd2;

    pthread_mutex_init(&mutex, NULL);

    pthread_create(&thd1, NULL, &callCount, NULL);
    pthread_create(&thd2, NULL, &callCount, NULL);

    pthread_join(thd2, NULL);
    pthread_join(thd1, NULL);

    return ret;
}
