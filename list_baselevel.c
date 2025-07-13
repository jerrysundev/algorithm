#include <stdio.h>
#include <stdlib.h>

// 单链表节点定义
typedef struct ListNode {
    int val;
    struct ListNode* next;
} ListNode;

// 创建链表（待实现）
ListNode* createList(int* arr, int len) {
    // TODO: 请补充你的实现
    if(len <= 0)
        return NULL;
    int i = 0;
    ListNode * head = malloc(sizeof(ListNode));
    if (!head) return NULL; // 防止分配失败
    head->val = arr[i++];
    ListNode * tmp = head;
    while(--len){
        ListNode * nt = malloc(sizeof(ListNode));
        if (!nt) return head; // 分配失败提前返回，实际可以加释放已分配节点
        nt->val = arr[i++];
        tmp->next = nt;
        tmp = nt;
    }
    tmp->next = NULL; // 补上尾结点 next
    return head;
}

// 打印链表
void printList(ListNode* head) {
    ListNode* p = head;
    while (p) {
        printf("%d", p->val);
        if (p->next) printf(" -> ");
        p = p->next;
    }
    printf("\n");
}

// 释放链表
void freeList(ListNode* head) {
    while (head) {
        ListNode* tmp = head;
        head = head->next;
        free(tmp);
    }
}

// 链表反转函数（你可以自行补充）
ListNode* reverseList(ListNode* head) {
    // TODO
    ListNode * pre = NULL;

    while(head){
        ListNode * nt = head->next;
        head->next = pre;
        pre = head;
        head = nt;
    }
    return pre;
}

// 头插法：在链表头部插入一个节点
ListNode* insertHead(ListNode* head, int val) {
    // TODO: 实现头插
    ListNode* pre = malloc(sizeof(ListNode));
    pre->val = val;

    pre->next = head;
    return pre;
}

// 尾插法：在链表尾部插入一个节点
ListNode* insertTail(ListNode* head, int val) {
    // TODO: 实现尾插
    ListNode* last = malloc(sizeof(ListNode));
    last->val = val;
    last->next = NULL;
    if(head==NULL)
        return last;

    ListNode* tmp = head;
    while(tmp->next)
        tmp = tmp->next;
    
    tmp->next = last;
    
    return head;
}

// 指定位置插入：在第pos个节点前插入val，pos从0开始
ListNode* insertAt(ListNode* head, int pos, int val) {
    // TODO: 实现指定位置插入
    ListNode * mid = malloc(sizeof(ListNode));
    mid->val = val;
    mid->next = NULL;

    if(pos == 0){
        mid->next = head;
        return mid;
    }

    ListNode* pre = head;
    ListNode* nt = head->next;

    while(--pos){
        pre = pre->next;
        nt = nt->next;
    }
    pre->next = mid;
    mid->next = nt;

    return head;
}


// 指定位置删除：删除第pos个节点，pos从0开始
ListNode* deleteAt(ListNode* head, int pos) {
    // TODO: 实现指定位置删除
    ListNode* nt = head->next;
    if(pos == 0){
        free(head);
        head  = NULL;
        return nt;
    }
    ListNode* tmp = head;

    while(--pos){
        nt = nt->next;
        tmp =  tmp->next;
    }
    tmp->next = nt->next;
    free(nt);
    nt = NULL;
    return head;
}

int main() {
    int arr[] = {1,2,3,4,5};
    ListNode* list = createList(arr, 5);
    printf("原链表: ");
    printList(list);

    /*反转后链表
    ListNode* rev = reverseList(list);
    printf("反转后链表: ");
    printList(rev);
    freeList(rev);
    */

     ListNode* head = list;
    // 练习头插
    //head = insertHead(head, 11);


    // 练习尾插
    //head = insertTail(head, 12);

    // 练习指定位置插入
    //head = insertAt(head, 5, 13);

    // 练习删除
    head = deleteAt(head, 4);

    // 最终输出链表内容
    printList(head);

    // 释放链表
    freeList(head);
    return 0;
}
