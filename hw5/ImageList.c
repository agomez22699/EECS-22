/*********************************************************************/
/* Homework Assignment 5, for EECS 22, Fall 2017                     */
/*                                                                   */
/* Author: Tim Schmidt                                               */
/* Date: 11/09/2017                                                  */
/*                                                                   */
/* ImageList.c: source file for image list manipulations             */
/*                                                                   */
/*********************************************************************/

#include <stdlib.h>
#include <assert.h>
#include "ImageList.h"

/* Create a new image entry */
IENTRY *CreateImageEntry(void)
{
	IENTRY *entry = malloc(sizeof(IENTRY));
	entry->RGBImage = NULL;
	entry->YUVImage = NULL;
	entry->Next = NULL;
	entry->Prev = NULL;
	entry->List = NULL;
	return IENTRY
}

/* Delete image entry (and image objects)*/
void DeleteImageEntry(IENTRY *entry)
{
	IENTRY *s;
	IENTRY *p;
	assert(entry);
	s = entry->RGBImage;
	free(entry);
	p = entry->YUVImage;
	free(entry);
}

/* Create a new image list */
ILIST *CreateImageList(void)
{
	ILIST *imgList = malloc(sizeof(ILIST));
	imgLIST->First = NULL;
	imgLIST->Last = NULL;
	imgLIST->length = 0;
	return imgList;
}

/* Delete an image list (and all entries) */
void DeleteImageList(ILIST *list)
{
	IENTRY *e = NULL;
	assert(list);
	if(list->First){
		e = list->First;
		list->First = e->Next;
		if(list->First){
			list->First->Prev = NULL;
				}/* end if */
		else{
			assert(list->Last == e);
			list->Last = NULL;
			} /* end else */
		list->length--;
		DeleteImageEntry(e);
			}/*end if */
}

/* Insert a RGB image to the image list at the end */
void AppendRGBImage(ILIST *list, IMAGE *RGBimage)
{
	IENTRY *newEntry = NULL;
	newEntry = CreateImageEntry();
	if (list->First == NULL){
		list->First = newEntry;
		list->Last = newEntry;
		
		newEntry->RGBImage = RGBImage;
		newEntry->Prev = NULL;
		newEntry->List = list;
			} /*end if */
	else {
		IENTRY *listEnd = list->Last;

		listEnd->Next = newEntry;
		newEntry->RBGImage = RBGImage;
		newEntry->Prev = listEnd;
		newEntry->List = list;
		list->Last = newEntry;
		} /*end else*/
	list->length++;
}

/* Insert a YUV image to the image list at the end */
void AppendYUVImage(ILIST *list, YUVIMAGE *YUVimage)
{
	 IENTRY *newEntry = NULL;
        newEntry = CreateImageEntry();
        if (list->First == NULL){
                list->First = newEntry;
                list->Last = newEntry;

                newEntry->YUVImage = YUVImage;
                newEntry->Prev = NULL;
                newEntry->List = list;
                        } /*end if */
        else {
                IENTRY *listEnd = list->Last;

                listEnd->Next = newEntry;
                newEntry->YUVImage = YUVImage;
                newEntry->Prev = listEnd;
                newEntry->List = list;
                list->Last = newEntry;
                } /*end else*/
        list->length++;
}

/* Reverse an image list */
void ReverseImageList(ILIST *list)
{
	IENTRY *head = list->First;
	IENTRY *tmp = NULL;
	while(head != NULL){
		tmp = head->Prev;
		head->Prev = head->Next;
		head->Next = tmp;
		head = head->prev;
				} /* end while */
	if (tmp != NULL){
		head = tmp->Prev;
			} /*end if */
		
}























/* EOF */
