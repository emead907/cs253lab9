/*
* Author: Emily Mead
* Date: Monday 15 March 
* Description: This is apart of week 9 lab activity. Here we created
* the functions needed to implement in out main.c
*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#include "PlaylistNode.h"


PlaylistNode* CreatePlaylistNode(char id[], char songName[], char artistName[], int songLength) {
    PlaylistNode * newNode = (PlaylistNode *) malloc(sizeof(PlaylistNode));
    
    if(newNode == NULL){
        return NULL;
    }

    //setting things up
    newNode->nextNodePtr = NULL;
    strncpy(newNode->uniqueID, id, 50);
    strncpy(newNode->songName, songName, 50);
    strncpy(newNode->artistName, artistName, 50);
    newNode->songLength = songLength;

    return newNode;
}

int InsertPlaylistNodeAfter(PlaylistNode* nodeInList, PlaylistNode* newNode) {
   PlaylistNode* tempNode = NULL;

   if(newNode == NULL | nodeInList == NULL) {
      return -1;
   }
   tempNode = nodeInList->nextNodePtr;
   nodeInList->nextNodePtr = newNode;
   newNode->nextNodePtr = tempNode;
   
   return 1;
}

int SetNextPlaylistNode(PlaylistNode* nodeInList, PlaylistNode* newNode) {
    //checking to make sure that the nodeInList in not NULL
    if(nodeInList == NULL)
    {
        return -1;
    }

    PlaylistNode* tempNode = NULL;
    tempNode = nodeInList->nextNodePtr;
    newNode->nextNodePtr = tempNode;
    nodeInList->nextNodePtr = newNode;

    return 0;
}

PlaylistNode* GetNextPlaylistNode(PlaylistNode* nodeInList) {
    if(nodeInList == NULL) {
      return NULL;
   }
   return nodeInList->nextNodePtr;
}

void PrintPlaylistNode(PlaylistNode* thisNode) {
    printf("Unique ID: %s\n", thisNode->uniqueID);
    printf("Song Name: %s\n", thisNode->songName);
    printf("Artist Name: %s\n", thisNode->artistName);
    printf("Song Length (in seconds): %d\n\n", thisNode->songLength);
}

void DestroyPlaylistNode(PlaylistNode* thisNode) {
    if(thisNode == NULL){
        return;
    }
    free(thisNode);
}