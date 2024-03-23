// #include <stdio.h>
// #include <stdlib.h>

// // กำหนดโครงสร้างข้อมูลสำหรับโหนดของ stack
// struct Node
// {
//     int data;
//     struct Node *next;
// };

// // ฟังก์ชันสำหรับสร้างโหนดใหม่
// struct Node *newNode(int data)
// {
//     struct Node *node = (struct Node *)malloc(sizeof(struct Node));
//     node->data = data;
//     node->next = NULL;
//     return node;
// }

// // ฟังก์ชันเพิ่มข้อมูลเข้าสู่ stack
// void push(struct Node **root, int data)
// {
//     struct Node *node = newNode(data);
//     node->next = *root;
//     *root = node;
//     printf("%d pushed to stack\n", data);
// }

// // ฟังก์ชันลบข้อมูลออกจาก stack
// int pop(struct Node **root)
// {
//     if (*root == NULL)
//         return -1; // ถ้า stack ว่างจะคืนค่า -1

//     struct Node *temp = *root;
//     *root = (*root)->next;
//     int popped = temp->data;
//     free(temp);
//     return popped;
// }

// // ฟังก์ชันแสดงค่าข้อมูลบน stack แต่ไม่ลบข้อมูล
// int peek(struct Node *root)
// {
//     if (root == NULL)
//         return -1; // ถ้า stack ว่างจะคืนค่า -1
//     return root->data;
// }

// // ฟังก์ชันทดสอบการทำงานของ stack
// int main()
// {
//     struct Node *root = NULL;

//     push(&root, 10);
//     push(&root, 20);
//     push(&root, 30);

//     printf("%d popped from stack\n", pop(&root));

//     printf("Top element is %d\n", peek(root));

//     return 0;
// }