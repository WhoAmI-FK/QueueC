#ifndef QUEUE_C
#define QUEUE_C
#include <stdlib.h>
#include <stdio.h>
// item
struct node{
	int _data;
	struct node* _next;
};
// container
struct _queue{
	struct node* _head;
	unsigned long _size;
};


// queue initialization
struct _queue* initQueue()
{
	struct _queue* newEl = (struct _queue*)malloc(sizeof(struct _queue));
	newEl->_head = NULL;
	newEl->_size = 0;
}

struct node* alloc(){
	struct node* new_node = (struct node*)malloc(sizeof(struct node));
	new_node->_next = NULL;
	return new_node;
}


// push element to queue
void enqueue(struct _queue* que, int val)
{	
	if(que->_head==NULL){
		que->_head = alloc();
		que->_head->_data = val;
		que->_size++;
		return;
	}
	struct node* _iterator = que->_head;
	while(_iterator->_next!=NULL){
		_iterator = _iterator->_next;
	}
	_iterator->_next = alloc();
	_iterator->_next->_data = val;
	que->_size++;
	return;
}

void dequeue(struct _queue* que){
	if(que->_head!=NULL){
		struct node* _iterator = que->_head;
		if(que->_size==1){
			free(_iterator);
			que->_head = NULL;
			que->_size = 0;
			return;
		}
		que->_head = que->_head->_next;
		free(_iterator);
		que->_size--;
		return;
	}
}

int _front(struct _queue* que){
	if(que->_size!=0) return que->_head->_data;
}

int isEmpty(struct _queue* que){
	return que->_head==NULL && que->_size==0;
}
// helper function
void clear(struct _queue* que){
	while(!isEmpty(que)) dequeue(que);
}

void destroy(struct _queue*& que){
	clear(que);
	free(que);
}
#endif
