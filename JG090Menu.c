/**************************************************************************************************/
/* Copyright (C) mc2lab.com, SSE@USTC, 2014-2015                                                  */
/*                                                                                                */
/*  FILE NAME             :  JG090menu.c                                                          */
/*  PRINCIPAL AUTHOR      :  Zhuyiliang                                                           */
/*  SUBSYSTEM NAME        :  JG090menu                                                            */
/*  MODULE NAME           :  JG090menu                                                            */
/*  LANGUAGE              :  C                                                                    */
/*  TARGET ENVIRONMENT    :  ANY                                                                  */
/*  DATE OF FIRST RELEASE :  2014/09/15                                                           */
/*  DESCRIPTION           :  This is a menu program                                               */
/**************************************************************************************************/

/*
 * Revision log:
 *
 * Created by Zhuyiliang, 2014/09/15
 *
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DESC_LEN 1024
#define CMD_LEN 20
#define CMD_NUM 10

typedef struct DataNode
{
    int    num;	
    char   cmd[CMD_LEN];	
    char   desc[DESC_LEN];
    struct DataNode *next;
} tDataNode;

tDataNode CmdList[] = 
{
    {0, "cd",    "this is cd cmd!",    &CmdList[1]},
    {1, "close", "this is close cmd!", &CmdList[2]},
    {2, "dir",   "this is dir cmd!",   &CmdList[3]},
    {3, "get",   "this is get cmd!",   &CmdList[4]},
    {4, "help",  "this is help cmd!",  &CmdList[5]},
    {5, "open",  "this is open cmd!",  &CmdList[6]},
    {6, "put",   "this is put cmd!",   &CmdList[7]},
    {7, "send",  "this is send cmd!",  &CmdList[8]},
    {8, "type",  "this is type cmd!",  &CmdList[9]},
    {9, "user",  "this is user cmd!",  NULL},
};

void PrintCmdList()
{
    tDataNode * p = CmdList;
    printf("Menu List:\n");
    while(p != NULL)
    {
        printf("%s - %s\n", p->cmd, p->desc);
        p = p->next;
    }
}

void CmdProcessing(char *c)
{
    tDataNode * p = CmdList;
    int exist = 0;
    while(p != NULL)
    {
        if(!strcmp(p->cmd, c))
        {
            exist = 1;
            printf("%s - %s\n", p->cmd, p->desc);
            break;
        }
        p = p->next;
    }
    if(exist == 0)
    {
        printf("This is a wrong cmd!\n");
    }
}

main()
{
    PrintCmdList();
    while(1)
    {
        char cmd[CMD_LEN];
        printf("Please input a cmd > ");
        scanf("%s", &cmd);
        CmdProcessing(cmd);
    }
}