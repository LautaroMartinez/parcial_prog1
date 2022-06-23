#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Passenger.h"

LinkedList* ll_newLinkedList(void){
	LinkedList* this = (LinkedList*) malloc(sizeof(LinkedList));

	if(this != NULL) {
		this->pFirstNode = NULL;
		this->size = 0;
	}
	return this;
}

int ll_len(LinkedList* this){
	int retorno = -1;

	if(this != NULL) {
		retorno = this->size;
	}
	return retorno;
}

Node* test_getNode(LinkedList* this, int nodeIndex){
	Node* pNode = NULL;

	if(this != NULL && nodeIndex >= 0 && nodeIndex < ll_len(this)){

		pNode = this->pFirstNode;

		for(int i = 0;i<nodeIndex;i++){
			pNode = pNode->pNextNode;
		}
	}
	return pNode;
}

int test_addNode(LinkedList* this, int nodeIndex,void* pElement){
	int retorno = -1;
	Node* pNuevoNodo = NULL;
	Node* pAuxNodo = NULL;

	if(this != NULL && nodeIndex >= 0 && nodeIndex <= ll_len(this)){
		pNuevoNodo = (Node*) malloc(sizeof(Node));

		if(pNuevoNodo != NULL) {
			pNuevoNodo->pNextNode = NULL;

			if(nodeIndex == 0) {
				pNuevoNodo->pNextNode = this->pFirstNode;
				this->pFirstNode = pNuevoNodo;
				pNuevoNodo->pElement = pElement;
				this->size++;
				retorno = 0;
			} else {
				pAuxNodo = test_getNode(this,nodeIndex - 1);
				if(pAuxNodo != NULL) {

					pNuevoNodo->pNextNode = pAuxNodo->pNextNode;
					pAuxNodo->pNextNode = pNuevoNodo;

					pNuevoNodo->pElement = pElement;
					this->size++;
					retorno = 0;
				}
			}
		}
	}
	return retorno;
}

int ll_add(LinkedList* this, void* pElement){
	int retorno = -1;

	if(this != NULL) {
		retorno = test_addNode(this,ll_len(this),pElement);
	}
	return retorno;
}

void* ll_get(LinkedList* this, int index){
	void* returnAux = NULL;
	Node* pNodo = NULL;

	if(this != NULL && index >= 0 && index < ll_len(this)) {
		pNodo = test_getNode(this,index);
		if(pNodo != NULL) {
			returnAux = pNodo->pElement;
		}
	}
	return returnAux;
}

int ll_set(LinkedList* this, int index,void* pElement){
	int returnAux = -1;
	Node* pNodo = NULL;

	if(this != NULL && index >= 0 && index < ll_len(this)) {
		pNodo = test_getNode(this,index);
		if(pNodo != NULL) {
			pNodo->pElement = pElement;
			returnAux = 0;
		}
	}
	return returnAux;
}

int ll_remove(LinkedList* this,int index){
	int retorno = -1;
	int len = ll_len(this);
	Node* pAuxNodo = NULL; // NODO ANTERIOR
	Node* pAuxNodoAnterior = NULL;

	if(this != NULL && index >= 0 && index < len) {
		pAuxNodo = test_getNode(this,index);
		if(pAuxNodo != NULL) {
			if(index == 0) {
				this->pFirstNode = pAuxNodo->pNextNode;
			} else {
				pAuxNodoAnterior = test_getNode(this,index - 1);
				if(pAuxNodoAnterior != NULL) {
					pAuxNodoAnterior->pNextNode = pAuxNodo->pNextNode;
				}
			}
			this->size--;
			free(pAuxNodo);
			retorno = 0;
		}
	}
	return retorno;
}

int ll_clear(LinkedList* this){
	int retorno = -1;
	int len = ll_len(this);
	if(this != NULL && len > 0) {
		for(int i = 0;i<len;i++) {
			ll_remove(this,i);
		}
		retorno = 0;
	}
	return retorno;
}

int ll_deleteLinkedList(LinkedList* this){

	 int retorno = -1;

	if (this != NULL && !ll_clear(this)) {
		free(this);
		retorno = 0;
	}

	return retorno;
}

int ll_indexOf(LinkedList* this, void* pElement){
	int retorno = -1;
	int len = ll_len(this);
	Node* auxNode = NULL;

	if(this != NULL) {
		for(int i = 0;i<len;i++) {
			auxNode = test_getNode(this,i);
			if(auxNode->pElement == pElement) {
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}

int ll_isEmpty(LinkedList* this){
	int retorno = -1;

	if(this != NULL){
		if(ll_len(this) > 0) {
			retorno = 0;
		} else {
			retorno = 1;
		}
	}
	return retorno;
}

int ll_push(LinkedList* this, int index, void* pElement){
	int retorno = -1;

	if(this != NULL && index >= 0 && index <= ll_len(this)) {
		retorno = test_addNode(this,index,pElement);
	}
	return retorno;
}

void* ll_pop(LinkedList* this,int index){
	void* retorno = NULL;

	if(this != NULL && index >= 0 && index < ll_len(this)) {
		retorno = ll_get(this,index);
		ll_remove(this,index);
	}
	return retorno;
}

int ll_contains(LinkedList* this, void* pElement){
	int retorno = - 1;

	if(this != NULL) {
		if(ll_indexOf(this,pElement) != -1) {
			retorno = 1;
		} else {
			retorno = 0;
		}
	}
	return retorno;
}

int ll_containsAll(LinkedList* this,LinkedList* this2){

	int retorno = -1;
	int len;
	void* pElement = NULL;

	if(this != NULL && this2 != NULL) {

		len = ll_len(this2);
		retorno = 1;
		for(int i = 0;i<len;i++) {
			pElement = ll_get(this2,i);
			if(!ll_contains(this2,pElement)) {
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}

LinkedList* ll_subList(LinkedList* this,int from,int to){
	LinkedList* subList = NULL;
	void* auxElement = NULL;

	if(this != NULL && from >= 0 && from < ll_len(this) && to > from && to <= ll_len(this)) {
		subList = ll_newLinkedList();
		if(subList != NULL) {
			for(int i = from;i<to;i++) {
				auxElement = ll_get(this,i);
				ll_add(subList,auxElement);
			}
		}
	}
	return subList;
}

LinkedList* ll_clone(LinkedList* this) {

	LinkedList* clone = NULL;

	if(this != NULL) {
		clone = ll_subList(this,0,ll_len(this));
	}
	return clone;
}

int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order){
	int retorno = -1;
	int estaOrdenado;
	int len;
	void* auxElement = NULL;
	void* auxElement2 = NULL;

	if(this != NULL && (order == 0 || order == 1) && pFunc != NULL) {
		len = ll_len(this);

		do {
			estaOrdenado = 1;
			len--;

			for(int i = 0;i<len;i++) {
				auxElement = ll_get(this,i);
				auxElement2 = ll_get(this,i+1);

				if((order == 1 && pFunc(auxElement,auxElement2) > 0) ||
				  (order == 0 && pFunc(auxElement,auxElement2) < 0)) {
					ll_set(this,i,auxElement2);
					ll_set(this,i+1,auxElement);
					estaOrdenado = 0;
				}
			}
		}while(estaOrdenado == 0);
		retorno = 0;
	}
	return retorno;
}

int ll_count(LinkedList* this, int (*pFunc)(void*)){
	int counter = 0;
	int len;
	void* auxElement = NULL;

	if(this != NULL && pFunc != NULL) {
		len = ll_len(this);
		for(int i = 0;i<len;i++) {
			auxElement = ll_get(this,i);
			if(pFunc(auxElement) == 1) {
				counter++;
	        }
		}
	}
	return counter;
}

LinkedList* ll_filter(LinkedList* this, int (*pFunc)(void*, char*), char fnParam[]){
	LinkedList* returnList;
	returnList = ll_newLinkedList();
	int len;
	int j = 0;
	void* auxElement = NULL;

	if(this != NULL && pFunc != NULL) {
		len = ll_len(this);
		for(int i = 0;i<len;i++) {
			auxElement = ll_get(this,i);
			if(pFunc(auxElement, fnParam) == 0) {
	        	ll_push(returnList, j, auxElement);
	        	j++;
	        }
		}
	}
	return returnList;
}

LinkedList* ll_map(LinkedList* this, void (*pFunc)(void*)){
	int len;
	void* auxElement = NULL;

	if(this != NULL && pFunc != NULL) {
		len = ll_len(this);
		for(int i = 0;i<len;i++) {
			auxElement = ll_get(this,i);
			pFunc(auxElement);
			ll_set(this, i, auxElement);
		}
	}
	return this;
}
