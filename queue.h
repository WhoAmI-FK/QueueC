typedef struct _queue _queue; // opaque type

void destroy(struct _queue*& que);
void clear(struct _queue* que);
int isEmpty(struct _queue* que);
int _front(struct _queue* que);
void dequeue(struct _queue* que);
void enqueue(struct _queue* que, int val);
struct _queue* initQueue();
