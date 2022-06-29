#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"


static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
    LinkedList* this;

    this = (LinkedList*) malloc(sizeof(LinkedList));
    if(this != NULL)
    {
    	this->size = 0;
    	this->pFirstNode = NULL;
    }

    return this;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
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
	Node* pNode;
	int len;
	int i;

	if(this != NULL && nodeIndex >= 0)
	{
		len = ll_len(this);
		if(nodeIndex < len)
		{
			pNode = this->pFirstNode;	//nodo 0
			if(pNode != NULL)
			{
				for(i = 0; i < len; i++)
				{
					if(i == nodeIndex)
					{
						return pNode;
					}
					pNode = pNode->pNextNode;
				}
			}
		}
	}
	return NULL;
}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
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
    Node* auxNode;
    Node* pNode;
    int len;
    int flag = 0;
    if(this != NULL && nodeIndex > -1)
    {
    	len = ll_len(this);
    	if(nodeIndex <= len)
    	{
    		pNode = (Node*) malloc(sizeof(Node));
    		if(pNode != NULL)
			{
    			if(nodeIndex == 0) // Agregar al principio (indice 0)
				{
					auxNode = this->pFirstNode;
					pNode->pNextNode = auxNode;
					pNode->pElement = pElement;
					this->pFirstNode = pNode;
					flag = 1;
				}
				else // Agregar en el medio o en el final
				{
					auxNode = getNode(this, nodeIndex-1);  // Obtengo el anterior
					if(auxNode != NULL)
					{
						pNode->pNextNode = auxNode->pNextNode; // Nuevo nodo apunta a donde apuntaba el anterior
						auxNode->pNextNode = pNode;
						pNode->pElement = pElement;
						flag = 1;
					}
					else
					{
						free(pNode);
					}
				}

			}
    		if(flag == 1)
    		{
				this->size++;
				returnAux = 0;
    		}

    	}
    }
    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}


/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    int len;

    if(this != NULL)
    {
    	len = ll_len(this);
    	if(!addNode(this, len, pElement))
    	{
    		returnAux = 0;
    	}
    }

    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int index)
{
    void* returnAux = NULL;
    Node* pNode;

    if(this != 0 && index > -1 && index < ll_len(this))
    {
    	pNode = getNode(this, index);
    	if(pNode != NULL)
    	{
    		returnAux = pNode->pElement;
    	}
    }

    return returnAux;
}


/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* this, int index,void* pElement)
{
    int returnAux = -1;
    Node* pNode;
    if(this != NULL && index > -1 && index < ll_len(this))
    {
    	pNode = getNode(this, index);
    	pNode->pElement = pElement;
    	returnAux = 0;
    }

    return returnAux;
}


/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this,int index)
{
    int returnAux = -1;
    Node* auxNode;
    Node* prevNode;

    if(this != NULL && index >= 0 && index < ll_len(this))
    {
    	auxNode = getNode(this, index);
    	if(auxNode != NULL)
    	{
			if(index == 0)
			{
				this->pFirstNode = auxNode->pNextNode;
			}
			else
			{
				prevNode = getNode(this, index-1);
				prevNode->pNextNode = auxNode->pNextNode;
			}
			free(auxNode);
			this->size--;
			returnAux = 0;
    	}
    }

    return returnAux;
}


/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* this)
{
    int returnAux = -1;
    int i, len;
    Node* pNode;

    if(this != NULL)
    {
    	len = ll_len(this);
    	for(i = 0; i < len; i++)
    	{
    		pNode = getNode(this, i);
    		if(pNode != NULL)
    		{
    			free(pNode);
    		}
    	}
    	this->pFirstNode = NULL;
    	this->size = 0;
    	returnAux = 0;
    }

    return returnAux;
}


/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* this)
{
    int returnAux = -1;

    if(this != NULL && !ll_clear(this))
    {
		free(this);
		returnAux = 0;
    }

    return returnAux;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    int i;
    int len;
    Node* pNode;

    if(this != NULL)
    {
    	len = ll_len(this);
    	for(i = 0; i < len; i++)
    	{
    		pNode = getNode(this, i);
    		if(pNode != NULL && (pNode->pElement == pElement))
    		{
    			returnAux = i;
    			break;
    		}
    	}
    }

    return returnAux;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this)
{
    int returnAux = -1;
    int len;
    if(this != NULL)
    {
    	len = ll_len(this);
		if(!len)
		{
    		returnAux = 1;
		}
		else
		{
			returnAux = 0;
		}
    }
    return returnAux;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* this, int index, void* pElement)
{
    int returnAux = -1;

    if(this != NULL && index > -1 && index <= ll_len(this))
    {
    	if(addNode(this, index, pElement) == 0)
    	{
    		returnAux = 0;
    	}
    }
    return returnAux;

}


/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this,int index)
{
    void* returnAux = NULL;
    Node* pNode;
    if(this != NULL && index >= 0 && index < ll_len(this))
    {
    	pNode = getNode(this, index);
    	if(pNode != NULL)
    	{
        	returnAux = pNode->pElement;
        	ll_remove(this, index);
    	}
    }

    return returnAux;
}


/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    int i;
    int len;
    Node* pNode;

    if(this != NULL)
    {
    	len = ll_len(this);
    	returnAux = 0;
    	for(i = 0; i < len; i++)
    	{
    		pNode = getNode(this, i);
    		if(pNode != NULL && pNode->pElement == pElement)
    		{
    			returnAux = 1;
    			break;
    		}
    	}
    }

    return returnAux;
}

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* this,LinkedList* this2)
{
    int returnAux = -1;
    int i;
    int len,len2;
    int contador = 0;
    Node* pNode;
    Node* pNode2;

    if(this != NULL && this2 != NULL)
    {
    	len = ll_len(this);
    	len2 = ll_len(this2);
    	for(i = 0; i < len2; i++)
    	{
    		pNode2 = ll_get(this2, i);
    		if(pNode2 != NULL)
    		{
    			for(int j = 0; j < len; j++)
				{
					pNode = ll_get(this, j);
					if(pNode != NULL)
					{
						if(pNode->pElement == pNode2->pElement)
						{
							contador++;
							break;
						}
					}
				}
    		}
    	}
    	if(contador == this2->size)
    	{
    		returnAux = 1;
    	}
    	else
    	{
    		returnAux = 0;
    	}
    }

    return returnAux;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* cloneArray = NULL;
    int len;
    int i;
    void* auxElement;

    if(this != NULL && from >= 0 && from < to)
    {
    	len = ll_len(this);
    	if(from < len && to <= len)
    	{
    		cloneArray = ll_newLinkedList();
    		/*for(i = 0; i < to-from; i++)
    		{
    			auxElement = ll_get(this, from+i);
    			addNode(cloneArray, i, auxElement);
    		}
    		*/
    		for(i = from; i < to; i++)
    		{
    			auxElement = ll_get(this, i);
    			ll_add(cloneArray,auxElement);
    		}
    	}
    }

    return cloneArray;
}



/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this)
{
    LinkedList* cloneArray = NULL;
    int len;
    //void* auxElement;
    //int i;

    if(this != NULL)
    {
    	cloneArray = ll_newLinkedList();
    	len = ll_len(this);
    	cloneArray = ll_subList(this, 0, len);

    	/*for(i = 0; i < len; i++)
    	{
    		auxElement = ll_get(this, i);
    		ll_add(cloneArray,auxElement);
    	}*/
    }
    return cloneArray;
}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                        ( 0) Si ok
 */
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order)
{
    int returnAux =-1;
    int i;
    int j;
    int len;
    int comparador;
    void* iElement;
    void* jElement;
    void* auxElement;

    if(this != NULL && pFunc != NULL && (order == 0 || order == 1))
    {
    	len = ll_len(this);
    	returnAux = 0;/*
    	for(i = 0; i < len-1; i++)
		{
			for(j = i+1; j < len; j++)
			{
				iElement = ll_get(this, i);
				jElement = ll_get(this, j);
				comparador = pFunc(iElement, jElement);
				if(order == 1 && comparador > 0)
				{
					auxElement = jElement;
					ll_set(this, j, iElement);
					ll_set(this, i, auxElement);

				}
				else
				{
					if(order == 0 && comparador < 0)
					{
						auxElement = jElement;
						ll_set(this, j, iElement);
						ll_set(this, i, auxElement);
					}
				}
			}
		}*/

    	switch(order)
    	{
    	case 1:
    		for(i = 0; i < len-1; i++)
			{
				for(j = i+1; j < len; j++)
				{
					iElement = ll_get(this, i);
					jElement = ll_get(this, j);
					if(pFunc(iElement, jElement) > 0)
					{
						auxElement = jElement;
						ll_set(this, j, iElement);
						ll_set(this, i, auxElement);

					}

				}
			}
    		returnAux = 0;
    		break;
    	case 0:
    		for(i = 0; i < len-1; i++)
			{
				for(j = i+1; j < len; j++)
				{
					iElement = ll_get(this, i);
					jElement = ll_get(this, j);
					if(pFunc(iElement, jElement) < 0)
					{
						auxElement = jElement;
						ll_set(this, j, iElement);
						ll_set(this, i, auxElement);
					}
				}
			}
    		returnAux = 0;
    		break;
    	}

    }

    return returnAux;

}

