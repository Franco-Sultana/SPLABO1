#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include "../inc/LinkedList.h"
#include "LinkedList.h"


static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);


LinkedList* ll_newLinkedList(void)
{
    LinkedList* this= NULL;
    this = (LinkedList*)malloc(sizeof(LinkedList));
    if(this != NULL)
    {
    	this->pFirstNode = NULL;
    	this->size = 0;
    }
    return this;
}


int ll_len(LinkedList* this)
{
    int returnAux = -1;
    if(this != NULL)
    {
    	returnAux = this->size;
    }
    return returnAux;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pNode) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)
{
	Node* node = NULL;
	int i = 0;
	if(this != NULL && nodeIndex >= 0 && nodeIndex < ll_len(this))
	{
		node = this->pFirstNode;
		while(i < nodeIndex)
		{
			node = node->pNextNode;
			i++;
		}
	}
    return node;
}


Node* test_getNode(LinkedList* this, int nodeIndex)
{
    return getNode(this, nodeIndex);
}


/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    int returnAux = -1;
    Node* node;
    Node* previousNode;
    if(this != NULL && nodeIndex >= 0 && nodeIndex <= ll_len(this))
    {
    	node = (Node*)malloc(sizeof(Node));
    	if(node != NULL)
    	{
			if(nodeIndex == 0)
			{
				node->pNextNode = this->pFirstNode;
				node->pElement = pElement;
				this->pFirstNode = node;
			}
			else
			{
				previousNode = getNode(this, nodeIndex-1);
				node->pNextNode = node;
				node->pElement = pElement;
				previousNode->pNextNode = node;
			}
			returnAux = 0;
			this->size++;
    	}
    }
    return returnAux;
}


int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}


int ll_add(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    int len;
    if(this != NULL)
    {
    	len = ll_len(this);
    	returnAux = addNode(this, len, pElement);
    }

    return returnAux;
}


void* ll_get(LinkedList* this, int index)
{
    void* returnAux = NULL;
    Node* node;
    if(this != NULL && index >= 0 && index < ll_len(this))
    {
    	node = getNode(this, index);
    	if(node != NULL)
    	{
    		returnAux = node->pElement;
    	}
    }
    return returnAux;
}



int ll_set(LinkedList* this, int index,void* pElement)
{
    int returnAux = -1;
    Node* node;

    if(this != NULL && index >= 0 && index < ll_len(this))
    {
		node = getNode(this, index);
		if(node != NULL)
		{
			node->pElement = pElement;
			returnAux = 0;
		}
	}

    return returnAux;
}



int ll_remove(LinkedList* this,int index)
{
    int returnAux = -1;
    Node* previousNode;
    Node* nodeRemove;
	if(this != NULL && index >= 0 && index < ll_len(this))
	{
	if(ll_isEmpty(this) != 1)
	{
		nodeRemove = getNode(this, index);
		previousNode = getNode(this, index - 1);

		if(index == 0)
		{
			this->pFirstNode = nodeRemove->pNextNode;
		}
		else
		{
			previousNode->pNextNode = nodeRemove->pNextNode;
		}
		free(nodeRemove);
		this->size--;
		returnAux = 0;
		}
    }
    return returnAux;
}



int ll_clear(LinkedList* this)
{
    int returnAux = -1;
    int len;

    if(this != NULL)
    {
    	len = ll_len(this);
    	for(int i = len; i >= 0; i--)
    	{
    		if(ll_remove(this, i) == 0)
    		{
    			returnAux = 0;
    		}
    	}

    }
    return returnAux;
}



int ll_deleteLinkedList(LinkedList* this)
{
    int returnAux = -1;
    if(this != NULL)
    {
    	if(ll_clear(this) == 0)
    	{
			free(this);
			returnAux = 0;
    	}
    }

    return returnAux;
}


int ll_indexOf(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    Node* node;
    int i = 0;
    if(this != NULL)
    {
    	while(i < ll_len(this))
    	{
    		node = getNode(this, i);
			if(node->pElement == pElement)
			{
				returnAux = i;
				break;
			}
			i++;
    	}
    }

    return returnAux;
}


int ll_isEmpty(LinkedList* this)
{
    int returnAux = -1;
    int len;
    if(this != NULL)
    {
    	len = ll_len(this);
    	returnAux = 1;
    	if(len != 0)
		{
			returnAux = 0;
		}

    }
    return returnAux;
}


int ll_push(LinkedList* this, int index, void* pElement)
{
    return addNode(this, index, pElement);
}



void* ll_pop(LinkedList* this,int index)
{
    void* returnAux = NULL;
    if(this != NULL && index >= 0 && index < ll_len(this))
    {
    	returnAux = ll_get(this, index);
    	ll_remove(this, index);
    }
    return returnAux;
}



int ll_contains(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    if(this != NULL)
    {
    	returnAux = 0;
    	if(ll_indexOf(this, pElement) != -1)
    	{
    		returnAux = 1;
    	}
    }
    return returnAux;
}


int ll_containsAll(LinkedList* this,LinkedList* this2)
{
    int returnAux;
    int i = 0;
    if(this != NULL && this2 != NULL)
    {
    	returnAux = 1;
    	while(i < ll_len(this2))
    	{
    		if(ll_contains(this, ll_get(this2, i)) != 1)
    		{
    			returnAux = 0;
				break;
    		}
    		i++;
    	}
    }
    return returnAux;
}


LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* cloneArray = NULL;
    void* pElement;
    if(this != NULL && from >= 0 && to <= ll_len(this))
    {

    	cloneArray = ll_newLinkedList();
    	if(cloneArray != NULL)
    	{
			for(int i = from; i < to; i++)
			{
				pElement = ll_get(this, i);
				ll_add(cloneArray, pElement);
			}
    	}

    }
    return cloneArray;
}



LinkedList* ll_clone(LinkedList* this)
{
    LinkedList* cloneArray = NULL;
    if(this != NULL)
    {
    	cloneArray = ll_subList(this, 0, ll_len(this));
    }
    return cloneArray;
}



int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order)
{
    int returnAux =-1;
    void* pElement1;
    void* pElement2;
    void* aux;
    int compare;

    if(this != NULL && pFunc != NULL && (order == 0 || order == 1))
    {
		for(int i = 0; i<ll_len(this)-1; i++)
		{
			for(int j = i + 1; j<ll_len(this); j++)
			{
				pElement1 = ll_get(this, i);
				pElement2 = ll_get(this, j);
				compare = pFunc(pElement1, pElement2);
				if((compare > 0 && order == 1) || (compare < 0 && order == 0))
				{
					aux = pElement1;
					ll_set(this, i, pElement2);
					ll_set(this, j, aux);
				}
			}
    	}
    	returnAux = 0;
    }

    return returnAux;

}

int ll_count(LinkedList* this, int integreer, int (*pFunc)(void*, int))
{
	int quantity = -1;
	if(this != NULL && pFunc != NULL)
	{
		for(int i = 0; i<ll_len(this); i++)
		{
			quantity += pFunc(ll_get(this, i), integreer);
		}
	}
	return quantity;
}

LinkedList* ll_filter(LinkedList* this, int(*pFunc)(void* element))
{
	LinkedList* auxiliarList = NULL;
	int returnFunc;
	void* pElement;
	if(this != NULL && pFunc != NULL)
	{
		auxiliarList = ll_newLinkedList();
		for(int i = 0; i<ll_len(this); i++)
		{
			pElement = ll_get(this, i);
			returnFunc = pFunc(pElement);
			if(returnFunc == 1)
			{
				ll_add(auxiliarList, pElement);
			}
		}
	}
	return auxiliarList;
}

LinkedList* ll_map(LinkedList* this, int(*pFunc)(void* pElement))
{
	LinkedList* pListAux = ll_newLinkedList();
	void* pElement;


	if(this != NULL && pFunc != NULL && pListAux != NULL)
	{
		for(int i = 0; i<ll_len(this); i++)
		{
			pElement = ll_get(this, i);
			if(pFunc(pElement) == 1)
			{

				ll_add(pListAux, pElement);
			}
		}
	}
	return pListAux;
}
