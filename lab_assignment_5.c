#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	char letter;
	struct node* next;
} node;

// Returns number of nodes in the linkedList.
int length(node* head)
{
	node* reader = head;
	int counter = 0;

	if(reader == NULL){
		return 0;
	
	}

	while(reader != NULL){
		counter++;
		reader = reader->next;
	}

	return counter;
}

// parses the string in the linkedList
//  if the linked list is head -> |a|->|b|->|c|
//  then toCString function wil return "abc"
char* toCString(node* head)
{
	node* scribe = head;
	int strle = length(&head);
	char* stringList = (char*)malloc(strle * sizeof(char));
	

	if(scribe = NULL){
		printf("wack");
	}


	while(scribe != NULL){
		for(int i = 0; i < strle; i++){
			stringList[i] = scribe->letter;
			scribe = scribe->next;
			i++;
		}

	}

	return stringList;
}

// inserts character to the linkedlist
// f the linked list is head -> |a|->|b|->|c|
// then insertChar(&head, 'x') will update the linked list as foolows:
// head -> |a|->|b|->|c|->|x|
void insertChar(node** pHead, char c)
{
	node* tmpMarker = *pHead;
	node* newNodeMark = (node*)malloc(sizeof(node));
	if(newNodeMark == NULL){
		printf("wack");
	}

	newNodeMark->letter = c;
	newNodeMark->next = NULL;
	while(tmpMarker != NULL){
		tmpMarker = tmpMarker->next;
		if(tmpMarker->next == NULL){
			tmpMarker->next = newNodeMark;

		}
	}
}

// deletes all nodes in the linkedList.
void deleteList(node** pHead)
{
	node* tmpMarker = *pHead;
	if(tmpMarker == NULL){
		printf("There's nothing here lil bro");
	}
	while (tmpMarker != NULL){
		*pHead = tmpMarker ->next;
		free(tmpMarker);
		tmpMarker = *pHead;
	}

	*pHead = NULL;

}

int main(void)
{
	int i, strLen, numInputs;
	node* head = NULL;
	char* str;
	char c;
	FILE* inFile = fopen("input.txt","r");

	fscanf(inFile, " %d\n", &numInputs);
	
	while (numInputs-- > 0)
	{
		fscanf(inFile, " %d\n", &strLen);
		for (i = 0; i < strLen; i++)
		{
			fscanf(inFile," %c", &c);
			insertChar(&head, c);
		}

		str = toCString(head);
		printf("String is : %s\n", str);

		free(str);
		deleteList(&head);

		if (head != NULL)
		{
			printf("deleteList is not correct!");
			break;
		}
	}

	fclose(inFile);
}