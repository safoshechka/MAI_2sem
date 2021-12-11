#include <stdio.h>
#include <string.h>
#include "tree.h"

// меняет числа местами
void swap1(int *a,int *b)
{
    int t1=*a;
    *a=*b;
    *b=t1;
}

// поиск первого вхождения символа в строке с шагом перебора
int find_from1(char *a,int alen,int from,char b,int step)
{
    for(int i=from;i>=0 && i<alen;i+=step)
        if(a[i]==b)
            return i;
    return -1;
}

// получить приоритет операции по символу
int get_operator_priority1(char a)
{
    if(a=='+' || a=='-')
        return 1;
    if(a=='*' || a=='/')
        return 2;
    return -1;
}

// расставить приоритет операций в выражении
char *get_priority1(char *a)
{
    int len1=strlen(a);
    char na1[len1];
    memcpy(na1,a,len1);
    char *ret1=calloc(len1,1);
    int curnum1=1;
    while(true)
    {
        int to1=find_from1(na1,len1,0,')',1);
        int from1=0;
        if(to1==-1)
            to1=len1;
        else
            from1=find_from1(na1,len1,to1,'(',-1);
        int op1=-1;
        int op2=-1;
        for(int i=from1;i<to1;i++)
        {
            if(ret1[i]!=0)
                continue;
            int pr1=get_operator_priority1(na1[i]);
            if(pr1==-1)
                continue;
            if(op1==-1)
                op1=i;
            else if(op2==-1)
                op2=i;
            else
                break;
        }
        if(op1==-1)
        {
            if(na1[from1]=='(')
            {
                na1[from1]='[';
                na1[to1]=']';
                continue;
            }
            else
                break;
        }
        if(op2!=-1 && get_operator_priority1(na1[op1])<get_operator_priority1(na1[op2]))
            swap1(&op1,&op2);
        ret1[op1]=curnum1;
        curnum1++;
    }
    return ret1;
}

// выделить строку в куче
char *str_in_heap1(char *a)
{
    int l1=strlen(a);
    char *ret1=malloc(l1+1);
    memcpy(ret1,a,l1);
    ret1[l1]=0;
    return ret1;
}

// получить подстроку в куче
char *substr1(char *a,int fr,int to)
{
    char *ret1=malloc(to-fr+1);
    memcpy(ret1,a+fr,to-fr);
    ret1[to-fr]=0;
    return ret1;
}

// развернуть операцию в дерево
tnode *create_operator1(char *str,char *pri,int len)
{
    int mx1=0;
    int ttl1=0;
    for(int i=1;i<len;i++)
    {
        if(pri[i])
            ttl1++;
        if(pri[i]>pri[mx1])
            mx1=i;
    }
    tnode *ret1;
    if(ttl1==0)
    {
        char *val_str=substr1(str,0,len);
        while(val_str[0]=='(')
            val_str=substr1(val_str,1,strlen(val_str));
        while(val_str[strlen(val_str)-1]==')')
            val_str=substr1(val_str,0,strlen(val_str)-1);
        ret1=tree_create(val_str);
    }
    else
    {
        char opn1[2] = {str[mx1],0};
        ret1=tree_create(str_in_heap1(opn1));
        tree_add_node(ret1,create_operator1(str+mx1+1,pri+mx1+1,len-(mx1+1)));
        tree_add_node(ret1,create_operator1(str,pri,mx1));
    }
    return ret1;
}

// развернуть выражение в дерево
tnode *convert_to_tree1(char *a)
{
    int len1=strlen(a);
    char *prior1=get_priority1(a);
    tnode *ret1=create_operator1(a,prior1,len1);
    free(prior1);
    return ret1;
}

// проверяет равны ли деревья
int tree_equal(tnode *t1, tnode *t2)
{
    if((t1==NULL) ^ (t2==NULL))
        return 0;
    if(t1==NULL && t2==NULL)
        return 1;
    if(strcmp(t1->data,t2->data)!=0)
        return 0;
    if(!tree_equal(t1->childs,t2->childs))
        return 0;
    if(t1->childs==NULL)
        return 1;
    return tree_equal(t1->childs->next,t2->childs->next);
}

// считает колво вхождений t1 в t2
int count_repeats(tnode *t1, tnode *t2)
{
    int res = 0;
    res += tree_equal(t1, t2);
    if(t1->childs != NULL)
        res += count_repeats(t1->childs, t2) + count_repeats(t1->childs->next, t2);
    return res;
}

int main(int argc,char *argv[])
{
    char exp1[256];
    printf("*введите первое выражение:\n");
    scanf("%s",exp1);
    tnode *tr1=convert_to_tree1(exp1); // превращает строку в дерево
    printf("*введите второе выражение:\n");
    scanf("%s",exp1);
    tnode *tr2=convert_to_tree1(exp1);
    printf("*дерево первого выражения:\n");
    tree_print(tr1);
    printf("*дерево второго выражения:\n");
    tree_print(tr2);
    printf("*вхождений первого выражения во второе:\n%d\n",count_repeats(tr2,tr1));
    tree_destroy(tr1);
    return 0;
}
